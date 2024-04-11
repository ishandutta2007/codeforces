#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(x) (x).begin(),(x).end()
const long long MOD=1e9+7;
// const long long MOD=998244353;
const int INF=1e9;
const long long IINF=4e18;
const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
const char dir[4]={'D','R','U','L'};
// #define LOCAL

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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; ll k; cin >> n >> k;
    vector<ll> a(n); cin >> a;
    ll ub=IINF,lb=-IINF;
    auto f=[&](int i,ll x)->ll{return a[i]-1-3*x*x-3*x;};
    while(ub-lb>1LL){
        ll mid=(ub+lb)/2;
        vector<ll> use;
        for (int i=0;i<n;++i){
            ll lb2=-1,ub2=a[i];
            while(ub2-lb2>1LL){
                ll mid2=(ub2+lb2)/2,delta=f(i,mid2);
                (delta>=mid?lb2:ub2)=mid2;
            }
            use.emplace_back(ub2);
        }
        ll sum=accumulate(ALL(use),0LL);
        (sum<=k?ub:lb)=mid;
    }
    vector<ll> ans;
    for (int i=0;i<n;++i){
        ll lb2=-1,ub2=a[i];
        while(ub2-lb2>1LL){
            ll mid2=(ub2+lb2)/2,delta=f(i,mid2);
            (delta>=ub?lb2:ub2)=mid2;
        }
        ans.emplace_back(ub2);
    }
    ll rest=k-accumulate(ALL(ans),0LL);
    priority_queue<pair<ll,int>> pq;
    for (int i=0;i<n;++i){
        if (ans[i]!=a[i]){
            pq.emplace(f(i,ans[i]),i);
        }
    }
    for (int i=0;i<rest;++i){
        auto p=pq.top(); pq.pop();
        int id=p.second;
        if (++ans[id]!=a[id]) pq.emplace(f(id,ans[id]),id);
    }
    cout << ans << '\n';
}