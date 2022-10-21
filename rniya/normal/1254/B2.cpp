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

template<typename T> vector<T> prime_factor(T n){
    vector<T> res;
    for (T i=2;i*i<=n;++i){
        if (n%i==0) res.emplace_back(i);
        while(n%i==0) n/=i;
    }
    if (n!=1) res.emplace_back(n);
    return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n); cin >> a;
    ll sum=accumulate(ALL(a),0LL);
    if (sum==1){cout << -1 << '\n'; return 0;}
    vector<ll> D=prime_factor(sum);
    ll ans=IINF;
    for (ll d:D){
        auto calc=[&](vector<int> v)->ll{
            ll res=0,s=0; int to;
            for (int i=0;i<v.size();++i){
                if (s<d/2+1&&s+v[i]>=d/2+1) to=i;
                s+=v[i];
            }
            for (int i=0;i<v.size();++i) res+=(ll)v[i]*abs(to-i);
            return res;
        };
        ll cnt=0,now=0;
        vector<int> v;
        for (int i=0;i<n;++i){
            if (now+a[i]<d) v.emplace_back(a[i]),now+=a[i];
            else {
                v.emplace_back(d-now);
                cnt+=calc(v); v.clear();
                v.emplace_back((a[i]-d+now)%d);
                now=v.front();
            }
        }
        chmin(ans,cnt);
    }
    cout << ans << '\n';
}