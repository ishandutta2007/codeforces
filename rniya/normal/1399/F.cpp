#include <bits/stdc++.h>
using namespace std;
// #define LOCAL
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
    cout << '(' << p.first << ',' << p.second << ')';
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

void solve(){
    int n; cin >> n;
    struct seg{
        int l,r;
        seg(int l,int r):l(l),r(r){}
    };
    vector<int> l(n),r(n),comp;
    for (int i=0;i<n;++i){
        cin >> l[i] >> r[i];
        comp.emplace_back(l[i]);
        comp.emplace_back(r[i]);
    }
    sort(ALL(comp));
    comp.erase(unique(ALL(comp)),comp.end());
    vector<seg> S;
    for (int i=0;i<n;++i){
        l[i]=lower_bound(ALL(comp),l[i])-comp.begin();
        r[i]=lower_bound(ALL(comp),r[i])-comp.begin();
        S.emplace_back(l[i],r[i]);
    }
    int m=comp.size();
    S.emplace_back(0,m-1);
    sort(ALL(S),[](seg a,seg b){return a.r-a.l<b.r-b.l;});
    vector<int> have(n+1);
    vector<vector<int>> G(n+1),dp(n+1,vector<int>(m,0));
    for (int i=0;i<=n;++i){
        for (int j=0;j<i;++j){
            if (S[i].l<=S[j].l&&S[i].r>=S[j].r){
                G[i].emplace_back(j);
            }
        }
        sort(ALL(G[i]),[&](int a,int b){return S[a].l<S[b].l;});
        int M=0,now=S[i].l-1;
        for (int x:G[i]){
            while(S[x].l-1>now) chmax(M,dp[i][++now]);
            chmax(dp[i][S[x].r],M+have[x]);
        }
        M=0;
        for (int j=S[i].l;j<=S[i].r;++j) chmax(M,dp[i][j]);
        have[i]=M+1;
        debug(i,have[i],now,dp[i]);
    }
    cout << have[n]-1 << '\n';
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        solve();
    }
}