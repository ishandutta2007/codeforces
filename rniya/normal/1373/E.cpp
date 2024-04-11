#include <bits/stdc++.h>
using namespace std;
#pragma region Macros
typedef long long ll;
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(x) (x).begin(),(x).end()
const long long MOD=1e9+7;
// const long long MOD=998244353;
const int INF=1e9;
const long long IINF=1e18;
const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
const char dir[4]={'D','R','U','L'};
#define LOCAL

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
    int n,k; cin >> n >> k;
    ll ans=4*IINF;
    for (int i=0;i+k<10;++i){
        int rest=n-(i+i+k)*(k+1)/2;
        if (rest<0||rest%(k+1)!=0) continue;
        ll res=0,po=1; rest/=k+1;
        while(rest>0){
            int use=min(9,rest);
            res+=po*use; po*=10; rest-=use;
        }
        chmin(ans,res*10+i);
    }
    vector<ll> p(19,1);
    for (int i=0;i<18;++i) p[i+1]=p[i]*10;
    for (int i=0;i<10;++i){
        if (i+k<10) continue;
        int pre=10-i,nxt=i+k-9;
        int rest=n;
        for (int j=i;j<=i+k;++j) rest-=j%10;
        if (rest<0) continue;
        ll s=0;
        for (int j=0;;++j){
            int rest2=rest;
            rest2-=nxt;
            if (rest2<0) break;
            // debug(i,j,pre,nxt,rest2);
            if (rest2%(k+1)==0){
                rest2/=k+1;
                ll now=0,po=1; int start=1;
                while(rest2>0){
                    int use=min((start?8:9),rest2);
                    if (start) start=0;
                    now+=po*use; po*=10; rest2-=use;
                }
                chmin(ans,i+s*10+now*p[j+1]);
            }
            (s*=10)+=9; rest-=9*pre;
            if (rest<0) break;
        }
    }
    cout << (ans==4*IINF?-1:ans) << '\n';
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        solve();
    }
}