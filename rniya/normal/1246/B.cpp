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
    vector<int> res(n+1,0);
    for (int i=2;i<=n;++i) if (!res[i]){
        for (int j=i;j<=n;j+=i){
            if (!res[j]) res[j]=i;
        }
    }
    return res;
}

const int MAX_A=1e5+10,MAX_K=110;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    vector<int> table=prime_factor_table(MAX_A);
    vector<vector<ll>> POW(MAX_A,vector<ll>(MAX_K,1));
    for (int i=2;i<MAX_A;++i){
        for (int j=0;j<MAX_K-1;++j){
            POW[i][j+1]=POW[i][j]*i;
            if (POW[i][j+1]>=MAX_A) break;
        }
    }

    int n,k; cin >> n >> k;
    vector<int> a(n); cin >> a;

    auto f=[&](int N){
        map<int,int> res;
        while(N>1){
            ++res[table[N]];
            N/=table[N];
        }
        return res;
    };
    for (int i=0;i<n;++i){
        map<int,int> fac=f(a[i]);
        for (auto p:fac){
            while(p.second>=k){
                a[i]/=POW[p.first][k];
                p.second-=k;
            }
        }
    }

    vector<int> cnt(MAX_A,0);
    ll ans=0;
    for (int i=0;i<n;++i){
        map<int,int> fac=f(a[i]);
        ll x=1; int ok=1;
        for (auto p:fac){
            ll y=POW[p.first][k-p.second];
            if (y==1){ok=0; break;}
            x*=y;
            if (x>=MAX_A){ok=0; break;}
        }
        if (ok) ans+=cnt[x];
        ++cnt[a[i]];
    }

    cout << ans << '\n';
}