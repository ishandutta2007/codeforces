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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> p(n); p[0]=-1;
    for (int i=1;i<n;++i) cin >> p[i];

    vector<vector<int>> G(n);
    for (int i=1;i<n;++i) G[p[i]].emplace_back(i);

    vector<int> dep(n);
    auto dfs1=[&](auto self,int v)->void{
        if (p[v]<0) dep[v]=0;
        for (int u:G[v]){
            dep[u]=dep[v]+1;
            self(self,u);
        }
    };

    dfs1(dfs1,0);
    int l=max_element(ALL(dep))-dep.begin();
    vector<int> path(n,0);
    int L=l;
    while(L>=0){path[L]=1; L=p[L];}

    vector<int> ope;
    auto dfs2=[&](auto self,int v,int r)->void{
        if (v==r){
            int nxt;
            for (int i=0;i<G[v].size();++i){
                if (path[G[v][i]]){
                    r=G[v][i];
                    swap(G[v][i],G[v][0]);
                }
            }
            for (int u:G[v]){
                self(self,u,r);
                r=u;
            }
        } else {
            ope.emplace_back(r); p[r]=v;
            for (int u:G[v]){
                self(self,u,r);
                r=u;
            }
        }
    };

    dfs2(dfs2,0,0);
    vector<int> ans;
    L=l;
    while(L>=0){
        ans.emplace_back(L);
        L=p[L];
    }
    reverse(ALL(ans));
    reverse(ALL(ope));

    cout << ans << '\n';
    cout << n-1-dep[l] << '\n';
    cout << ope << '\n';
}