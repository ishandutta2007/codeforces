#include <bits/stdc++.h>
using namespace std;
#define LOCAL
#pragma region Macros
typedef long long ll;
#define ALL(x) (x).begin(),(x).end()
const long long MOD=1000000007;
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

const int sz=500;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m; cin >> n >> m;
    vector<int> d(n),h(n); cin >> d >> h;

    for (int i=0;i<n;++i) h.emplace_back(h[i]);
    vector<ll> sum(2*n,0);
    for (int i=0;i<2*n-1;++i) sum[i+1]=sum[i]+d[i%n];

    int N=(2*n+sz-1)/sz;
    vector<ll> X(N*sz),Y(N*sz);
    for (int i=0;i<2*n;++i){
        X[i]=2*h[i]+sum[i];
        Y[i]=2*h[i]-sum[i];
    }
    vector<ll> val(N,-IINF),max_x(N,-IINF),max_y(N,-IINF);
    for (int i=0;i<N;++i){
        int l=i*sz,r=(i+1)*sz;
        ll Max=-IINF;
        for (int j=l;j<r;++j){
            chmax(val[i],X[j]+Max);
            chmax(max_x[i],X[j]);
            chmax(max_y[i],Y[j]);
            chmax(Max,Y[j]);
        }
    }

    auto query=[&](int x,int y){
        ll res=-IINF,Max=-IINF;
        for (int i=0;i<N;++i){
            int l=i*sz,r=(i+1)*sz;
            if (r<=x||y<=l) continue;
            if (x<=l&&r<=y){
                chmax(res,val[i]); // 
                chmax(res,max_x[i]+Max); // 
                chmax(Max,max_y[i]);
            } else {
                for (int j=max(x,l);j<min(y,r);++j){
                    chmax(res,X[j]+Max);
                    chmax(Max,Y[j]);
                }
            }
        }
        return res;
    };

    for (int i=0;i<m;++i){
        int a,b; cin >> a >> b; --a,--b;
        if (a<=b) a+=n;
        cout << query(b+1,a) << '\n';
    }
}