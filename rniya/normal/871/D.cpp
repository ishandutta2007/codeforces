#include <bits/stdc++.h>
using namespace std;
const long long MOD=1000000007;
// const long long MOD=998244353;
#define LOCAL
#pragma region Macros
typedef long long ll;
typedef __int128_t i128;
typedef unsigned int uint;
typedef unsigned long long ull;
#define ALL(x) (x).begin(),(x).end()
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
template<typename T,typename U,typename V>
ostream&operator<<(ostream &os,const tuple<T,U,V> &t){
    os << '(' << get<0>(t) << ',' << get<1>(t) << ',' << get<2>(t) << ')';
    return os;
}
template<typename T,typename U,typename V,typename W>
ostream&operator<<(ostream &os,const tuple<T,U,V,W> &t){
    os << '(' << get<0>(t) << ',' << get<1>(t) << ',' << get<2>(t) << ',' << get<3>(t) << ')';
    return os;
}
template<typename T,typename U>
ostream &operator<<(ostream &os,const map<T,U> &m){
    os << '{';
    for (auto itr=m.begin();itr!=m.end();){
        os << '(' << itr->first << ',' << itr->second << ')';
        if (++itr!=m.end()) os << ',';
    }
    os << '}';
    return os;
}
template<typename T,typename U>
ostream &operator<<(ostream &os,const unordered_map<T,U> &m){
    os << '{';
    for (auto itr=m.begin();itr!=m.end();){
        os << '(' << itr->first << ',' << itr->second << ')';
        if (++itr!=m.end()) os << ',';
    }
    os << '}';
    return os;
}
template<typename T>
ostream &operator<<(ostream &os,const set<T> &s){
    os << '{';
    for (auto itr=s.begin();itr!=s.end();){
        os << *itr;
        if (++itr!=s.end()) os << ',';
    }
    os << '}';
    return os;
}
template<typename T>
ostream &operator<<(ostream &os,const multiset<T> &s){
    os << '{';
    for (auto itr=s.begin();itr!=s.end();){
        os << *itr;
        if (++itr!=s.end()) os << ',';
    }
    os << '}';
    return os;
}
template<typename T>
ostream &operator<<(ostream &os,const unordered_set<T> &s){
    os << '{';
    for (auto itr=s.begin();itr!=s.end();){
        os << *itr;
        if (++itr!=s.end()) os << ',';
    }
    os << '}';
    return os;
}
template<typename T>
ostream &operator<<(ostream &os,const deque<T> &v){
    for (int i=0;i<v.size();++i){
        os << v[i] << (i+1==v.size()?"": " ");
    }
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

vector<ll> tle(int n){
    vector<vector<int>> d(n+1,vector<int>(n+1,INF));
    for (int i=1;i<=n;++i) d[i][i]=0;
    for (int i=1;i<=n;++i){
        for (int j=i+1;j<=n;++j){
            if (gcd(i,j)!=1){
                d[i][j]=d[j][i]=1;
            }
        }
    }

    for (int k=1;k<=n;++k){
        for (int i=1;i<=n;++i){
            for (int j=1;j<=n;++j){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }

    vector<ll> cnt(4,0);
    for (int i=1;i<=n;++i){
        for (int j=i+1;j<=n;++j){
            if (d[i][j]==INF) continue;
            ++cnt[d[i][j]];
        }
    }
    return cnt;
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;

    vector<int> min_factor(n+1),mobius(n+1,-1);
    iota(min_factor.begin(),min_factor.end(),0);
    for (int i=2;i<=n;++i){
        if (min_factor[i]<i) continue;
        for (int j=i;j<=n;j+=i){
            min_factor[j]=min(min_factor[j],i);
            mobius[j]*=-1;
            if (j/i%i==0) mobius[j]=0;
        }
    }

    vector<ll> cnt(4,0);
    for (int i=2;i<=n;++i){
        int x=n/i;
        cnt[1]+=ll(x)*(x-1)/2*mobius[i];
    }

    vector<ll> rui(n+1,0);
    for (int i=2;i<=n;++i) ++rui[min_factor[i]];
    for (int i=2,j=n,sum=n-1;i<=n;++i){
        while (j>=2&&ll(i)*j>n) sum-=rui[j--];
        cnt[2]+=ll(rui[i])*sum;
    }
    for (int i=2;i*i<=n;++i) cnt[2]-=ll(rui[i])*(rui[i]);
    cnt[2]/=2;
    for (int i=2;i*i<=n;++i) cnt[2]+=ll(rui[i])*(rui[i]-1)/2;
    cnt[2]-=cnt[1];

    int ng=1;
    for (int i=2;i<=n;++i) ng+=(i*2>n&&min_factor[i]==i);
    ll whole=ll(n-ng)*(n-ng-1)/2;
    cnt[3]=whole-(cnt[1]+cnt[2]);

    ll ans=0;
    for (int i=1;i<=3;++i) ans+=cnt[i]*i;
    cout << ans << '\n';
}