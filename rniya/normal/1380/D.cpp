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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m,K; ll x,y; cin >> n >> m >> x >> K >> y;
    vector<int> a(n),b(m); cin >> a >> b;
    if (n<m){cout << -1 << '\n'; return 0;}
    vector<bool> rest(n,false);
    int B=0;
    for (int i=0;i<n;++i){
        if (B<m&&a[i]==b[B]){
            rest[i]=true; ++B;
        }
    }
    if (B!=m){cout << -1 << '\n'; return 0;}
    vector<ll> costs(n+1,IINF);
    costs[K]=x;
    for (int i=K+1;i<=n;++i){
        costs[i]=min(costs[i-1]+y,costs[i-K]+x);
    }
    ll ans=0; int pre=0;
    a.emplace_back(0);
    for (int i=0;i<n;++i){
        if (rest[i]){pre=a[i]; continue;}
        int cnt=0,M=0;
        while(i<n&&!rest[i]){
            chmax(M,a[i]);
            ++i,++cnt;
        }
        ll add=IINF;
        if (cnt>=K) add=costs[cnt];
        if (M<a[i]||M<pre) chmin(add,y*cnt);
        if (add==IINF){cout << -1 << '\n'; return 0;}
        ans+=add;
        --i;
    }
    cout << ans << '\n';
}