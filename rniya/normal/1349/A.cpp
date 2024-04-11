#include <bits/stdc++.h>
using namespace std;
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

vector<int> prime_factor_table(int n){
    vector<int> res(n+1,0);
    for (int i=2;i<=n;++i) if (!res[i]){
        for (int j=i;j<=n;j+=i){
            if (!res[j]) res[j]=i;
        }
    }
    return res;
}

const int MAX=2e5+10;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n); cin >> a;
    vector<int> table=prime_factor_table(MAX);
    map<int,pair<int,int>> cnt;
    vector<int> check(MAX,n);
    for (int i=0;i<n;++i){
        map<int,int> fac;
        while(a[i]!=1){
            ++fac[table[a[i]]];
            a[i]/=table[a[i]];
        }
        // debug(fac);
        for (auto x:fac){
            int num=x.first,app=x.second;
            if (cnt.count(num)){
                if (app<cnt[num].first){
                    cnt[num].second=cnt[num].first;
                    cnt[num].first=app;
                } else if (app<cnt[num].second){
                    cnt[num].second=app;
                }
            } else cnt[num]={app,INF};
            --check[num];
        }
    }
    for (auto x:cnt){
        int num=x.first;
        for (int i=0;i<min(check[num],2);++i){
            if (!i){
                cnt[num].second=cnt[num].first;
                cnt[num].first=0;
            } else cnt[num].second=0;
        }
    }
    ll ans=1;
    // debug(cnt);
    for (auto x:cnt){
        int sum=x.second.second;
        if (sum>=INF) continue;
        for (int i=0;i<sum;++i) ans*=x.first;
    }
    cout << ans << '\n';
}