#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(v) (v).begin(),(v).end()
#define debug(x) cout << #x << '=' << x << '\n'
const long long MOD=1e9+7;
//const long long MOD=998244353;
const int INF=1e9;
const long long IINF=1e18;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
const char dir[4]={'D','R','U','L'};

template<typename T>
istream &operator>>(istream &is,vector<T> &v){
    for (T &x:v) is >> x;
    return is;
}
template<typename T>
ostream &operator<<(ostream &os,const vector<T> &v){
    for (int i=0;i<v.size();++i){
        os << v[i] << (i+1==v.size()?'\n':' ');
    }
    return os;
}
template<typename T,typename U>
ostream &operator<<(ostream &os,const pair<T,U> &p){
    cout << '(' << p.first << ',' << p.second << ')';
    return os;
}

template<class T> inline bool chmin(T &a,T b){
    if (a>b){a=b; return true;} return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){a=b; return true;} return false;
}

template<typename T>
struct BinaryIndexedTree{
    vector<T> dat;
    BinaryIndexedTree(int n):dat(n+1,0){}
    void add(int i,T x){
        if (i==0) return;
        for (;i<=dat.size();i+=(i&-i)) dat[i]+=x;
    }
    T sum(int i){
        T res=0;
        for (;i>0;i-=(i&-i)) res+=dat[i];
        return res;
    }
    T query(int l,int r){ //[l,r)
        return sum(r-1)-sum(l-1);
    }
    int lower_bound(T x){
        if (x<=0) return 0;
        int lb=0,r=1;
        while(r<dat.size()) r<<=1;
        for (;r>0;r>>=1){
            if (lb+r<dat.size()&&dat[lb+r]<x){
                x-=dat[lb+r]; lb+=r;
            }
        }
        return lb+1;
    }
    void add0(int i,T x){add(i+1,x);}
    T sum0(int i){return sum(i+1);}
    T query0(int l,int r){return sum(r)-sum(l);}
    T operator[](int i){return query0(i,i+1);}
};

const int MAX_N=2e5+10;

int n;
string S,T;
vector<int> A(MAX_N),B(MAX_N);

void solve(){
    for (int i=0;i<n;++i) A[i]=(S[i]-'a')+1;
    for (int i=0;i<n;++i) B[i]=(T[i]-'a')+1;
    sort(S.begin(),S.end()); sort(T.begin(),T.end());
    if (S!=T){cout << "NO" << '\n'; return;}
    int can=0;
    for (int i=0;i<n-1;++i) if (S[i]==S[i+1]){
        cout << "YES" << '\n'; return;
    }
    BinaryIndexedTree<ll> BIT1(30),BIT2(30);
    ll cnt1=0,cnt2=0;
    for (int i=0;i<n;++i){
        cnt1+=(ll)i-BIT1.sum(A[i]);
        BIT1.add(A[i],1LL);
    }
    for (int i=0;i<n;++i){
        cnt2+=(ll)i-BIT2.sum(B[i]);
        BIT2.add(B[i],1LL);
    }
    cout << (cnt1%2==cnt2%2?"YES":"NO") << '\n';
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        cin >> n >> S >> T;
        solve();
    }
}