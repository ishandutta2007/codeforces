#include <bits/stdc++.h>
using namespace std;
#define LOCAL
#pragma region Macros
typedef long long ll;
#define ALL(x) (x).begin(),(x).end()
const long long MOD=1000000007;
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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m; cin >> n >> m;

    vector<int> a(m),b(m),deg(n,0);
    for (int i=0;i<m;++i){
        cin >> a[i] >> b[i];
        ++deg[--a[i]]; ++deg[--b[i]];
    }

    vector<int> odds;
    for (int i=0;i<n;++i){
        if (deg[i]&1) odds.emplace_back(i);
        deg[i]=0;
    }
    for (int i=0;i<odds.size();i+=2,++m){
        a.emplace_back(odds[i]);
        b.emplace_back(odds[i+1]);
    }
    if (m&1){
        a.emplace_back(0);
        b.emplace_back(0);
        ++m;
    }

    vector<vector<pair<int,int>>> G(n),nG(n);
    for (int i=0;i<m;++i){
        G[a[i]].emplace_back(b[i],i);
        G[b[i]].emplace_back(a[i],i);
    }

    vector<bool> seen(n,false),used(m,false);
    auto dfs1=[&](auto self,int v)->void{
        seen[v]=true;
        for (auto e:G[v]){
            int u=e.first;
            if (seen[u]) continue;
            used[e.second]=true;
            nG[v].emplace_back(u,e.second);
            self(self,u);
        }
    };
    dfs1(dfs1,0);

    for (int i=0;i<m;++i){
        if (used[i]) continue;
        ++deg[a[i]];
    }

    auto dfs2=[&](auto self,int v,int p,int id)->void{
        for (auto e:nG[v]){
            self(self,e.first,v,e.second);
        }
        if (p<0) return;
        if (deg[v]&1){
            a[id]=v; b[id]=p;
            ++deg[v];
        } else {
            a[id]=p; b[id]=v;
            ++deg[p];
        }
    };
    dfs2(dfs2,0,-1,-1);

    cout << m << '\n';
    for (int i=0;i<m;++i) cout << a[i]+1 << ' ' << b[i]+1 << '\n';
}