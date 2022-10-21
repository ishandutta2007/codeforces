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

template<typename Monoid>
struct SegmentTree{
    typedef function<Monoid(Monoid,Monoid)> F;
    int n;
    F f;
    Monoid id;
    vector<Monoid> dat;
    SegmentTree(int n_,F f,Monoid id):f(f),id(id){init(n_);}
    void init(int n_){
        n=1;
        while(n<n_) n<<=1;
        dat.assign(n<<1,id);
    }
    void build(const vector<Monoid> &v){
        for (int i=0;i<v.size();++i) dat[i+n]=v[i];
        for (int i=n-1;i;--i) dat[i]=f(dat[i<<1|0],dat[i<<1|1]);
    }
    void update(int k,Monoid x){
        dat[k+=n]=x;
        while(k>>=1) dat[k]=f(dat[k<<1|0],dat[k<<1|1]);
    }
    Monoid query(int a,int b){
        if (a>=b) return id;
        Monoid vl=id,vr=id;
        for (int l=a+n,r=b+n;l<r;l>>=1,r>>=1){
            if (l&1) vl=f(vl,dat[l++]);
            if (r&1) vr=f(dat[--r],vr);
        }
        return f(vl,vr);
    }
    Monoid operator[](int i){
        return dat[i+n];
    }
    // most left position that meets condition "check"
    template<typename C>
    int find(int a,int b,const C &check,int k,int l,int r){
        if (!check(dat[k])||r<=a||b<=l) return -1;
        if (l+1==r) return k-n;
        int vl=find(a,b,check,k<<1|0,l,(l+r)>>1);
        if (~vl) return vl;
        return find(a,b,check,k<<1|1,(l+r)>>1,r);
    }
    template<typename C>
    int find(int a,int b,const C &check){
        return find(a,b,check,1,0,n);
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m; cin >> n >> m;
    vector<int> Min(n),Max(n,0),pos(n);
    iota(Min.begin(),Min.end(),1);
    for (int i=0;i<n;++i) pos[i]=n-1-i;
    SegmentTree<int> seg(n+m,[](int a,int b){return a+b;},0);
    for (int i=0;i<n;++i) seg.update(i,1);
    for (int i=0;i<m;++i){
        int a; cin >> a; --a;
        Min[a]=1;
        Max[a]=max(Max[a],seg.query(pos[a]+1,n+i)+1);
        seg.update(pos[a],0);
        seg.update(n+i,1);
        pos[a]=n+i;
    }
    for (int i=0;i<n;++i) Max[i]=max(Max[i],seg.query(pos[i]+1,n+m)+1);
    for (int i=0;i<n;++i) cout << Min[i] << ' ' << Max[i] << '\n';
}