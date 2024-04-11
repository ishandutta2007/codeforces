#include <bits/stdc++.h>
using namespace std;
#define LOCAL
#pragma region Macros
typedef long long ll;
#define ALL(x) (x).begin(),(x).end()
const long long MOD=1e9+7;
// const long long MOD=998244353;
const int INF=1e9;
const long long IINF=1e18;
const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
const char dir[4]={'D','R','U','L'};

template<typename T>
istream &operator>>(istream &is,vector<T> &v){
    for (T &x:v) is >> x;
    return is;
}
template<typename T>
ostream &operator<<(ostream &os,const vector<T> &v){
    for (int i=0;i<v.size();++i){
        os << v[i] << (i+1==v.size()?"": " ");
    }
    return os;
}
template<typename T,typename U>
ostream &operator<<(ostream &os,const pair<T,U> &p){
    os << '(' << p.first << ',' << p.second << ')';
    return os;
}
template<typename T,typename U>
ostream &operator<<(ostream &os,const map<T,U> &m){
    os << '{';
    for (auto itr=m.begin();itr!=m.end();++itr){
        os << '(' << itr->first << ',' << itr->second << ')';
        if (++itr!=m.end()) os << ',';
        --itr;
    }
    os << '}';
    return os;
}
template<typename T>
ostream &operator<<(ostream &os,const set<T> &s){
    os << '{';
    for (auto itr=s.begin();itr!=s.end();++itr){
        os << *itr;
        if (++itr!=s.end()) os << ',';
        --itr;
    }
    os << '}';
    return os;
}

void debug_out(){cerr << '\n';}
template<class Head,class... Tail>
void debug_out(Head&& head,Tail&&... tail){
    cerr << head;
    if (sizeof...(Tail)>0) cerr << ", ";
    debug_out(move(tail)...);
}
#ifdef LOCAL
#define debug(...) cerr << " ";\
cerr << #__VA_ARGS__ << " :[" << __LINE__ << ":" << __FUNCTION__ << "]" << '\n';\
cerr << " ";\
debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

template<typename T> T gcd(T x,T y){return y!=0?gcd(y,x%y):x;}
template<typename T> T lcm(T x,T y){return x/gcd(x,y)*y;}

template<class T1,class T2> inline bool chmin(T1 &a,T2 b){
    if (a>b){a=b; return true;} return false;
}
template<class T1,class T2> inline bool chmax(T1 &a,T2 b){
    if (a<b){a=b; return true;} return false;
}
#pragma endregion

vector<int> prime_factor_table(int n){
    vector<int> res(n,0);
    for (int i=2;i<n;++i){
        if (res[i]) continue;
        for (int j=i;j<n;j+=i){
            res[j]=i;
        }
    }
    return res;
}

const int MAX_K=5010;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    vector<int> table=prime_factor_table(MAX_K);

    int n; cin >> n;
    vector<int> cnt(MAX_K,0);
    for (int i=0;i<n;++i){
        int k; cin >> k;
        ++cnt[k];
    }

    ll add=0;
    vector<map<int,int>> trie(1);
    vector<int> now(MAX_K,0),sum(1,n);
    for (int i=0;i<MAX_K;++i){
        int d=i;
        while (d>1){
            ++now[table[d]];
            d/=table[d];
        }
        int node=0;
        for (int j=MAX_K-1;j>=2;--j){
            if (table[j]!=j) continue;
            add+=(ll)now[j]*cnt[i];
            if (!trie[node].count(now[j])){
                trie[node][now[j]]=trie.size();
                trie.emplace_back();
                sum.emplace_back(0);
            }
            node=trie[node][now[j]];
            sum[node]+=cnt[i];
        }
    }

    ll ans=0;
    auto dfs=[&](auto self,int v,ll ret)->void{
        ans=max(ans,ret);
        int ch=0; ll cur=0;
        for (auto p:trie[v]) ch+=sum[p.second];
        for (auto p:trie[v]){
            self(self,p.second,ret+cur+(ll)(2*ch-n)*p.first);
            ch-=sum[p.second]; cur+=2LL*sum[p.second]*p.first;
        }
    };

    dfs(dfs,0,0);
    cout << add-ans << '\n';
}