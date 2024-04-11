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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m; cin >> n >> m;
    vector<vector<int>> a(n,vector<int>(m));
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            cin >> a[i][j];
        }
    }
    vector<int> mask(n),check(1<<m);
    int lb=0,ub=INF+10;
    while(ub-lb>1){
        int mid=(ub+lb)>>1;
        for (int i=0;i<(1<<m);++i) check[i]=0;
        for (int i=0;i<n;++i){
            int bit=0;
            for (int j=0;j<m;++j){
                if (a[i][j]>=mid){
                    bit|=1<<j;
                }
            }
            mask[i]=bit; check[bit]=1;
        }
        for (int bit=(1<<m)-1;bit>=0;--bit){
            for (int i=0;i<m;++i){
                check[bit]|=check[bit|1<<i];
            }
        }
        bool ok=false;
        for (int i=0;i<n;++i) ok|=check[((1<<m)-1)^mask[i]];
        (ok?lb:ub)=mid;
    }
    for (int i=0;i<(1<<m);++i) check[i]=0;
    for (int i=0;i<n;++i){
        int bit=0;
        for (int j=0;j<m;++j){
            if (a[i][j]>=lb){
                bit|=1<<j;
            }
        }
        mask[i]=bit; check[bit]=i+1;
    }
    for (int bit=(1<<m)-1;bit>=0;--bit){
        for (int i=0;i<m;++i){
            if (check[bit|1<<i]){
                check[bit]=check[bit|1<<i];
            }
        }
    }
    pair<int,int> ans;
    for (int i=0;i<n;++i){
        if (check[((1<<m)-1)^mask[i]]){
            ans={i+1,check[((1<<m)-1)^mask[i]]};
        }
    }
    cout << ans.first << ' ' << ans.second << '\n';
}