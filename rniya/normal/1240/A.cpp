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

void solve(){
    int n; cin >> n;
    vector<int> p(n); cin >> p;
    int x,y; ll a,b; cin >> x >> a >> y >> b;
    ll k; cin >> k;

    if (x>y) swap(x,y),swap(a,b);
    vector<ll> pri={a,b,lcm(a,b)};
    vector<int> v={x,y,x+y};
    sort(ALL(p)); reverse(ALL(p));
    vector<vector<int>> sum(3,vector<int>(n+1,0));
    for (int i=0;i<3;++i){
        for (ll j=pri[i]-1;j<n;j+=pri[i]){
            ++sum[i][j+1];
            if (i==0&&(j+1)%b==0) --sum[i][j+1];
            if (i==1&&(j+1)%a==0) --sum[i][j+1];
        }
        for (int j=0;j<n;++j) sum[i][j+1]+=sum[i][j];
    }

    auto check=[&](int mid){
        vector<int> use(3);
        for (int i=0;i<3;++i) use[i]=sum[i][mid];
        ll sum=0; int now=0;
        for (int i=2;i>=0;--i){
            for (int j=0;j<use[i];++j){
                sum+=p[now++]/100*v[i];
            }
        }
        return sum>=k;
    };

    int lb=-1,ub=n+1,mid;
    while(ub-lb>1){
        mid=(ub+lb)>>1;
        (check(mid)?ub:lb)=mid;
    }
    cout << (ub==n+1?-1:ub) << '\n';
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int q; cin >> q;
    for (;q--;){
        solve();
    }
}