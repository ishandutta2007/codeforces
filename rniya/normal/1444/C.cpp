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

struct UnionFindUndo{
    vector<int> dat;
    stack<pair<int,int>> hist;
    UnionFindUndo(int n):dat(n,-1){}
    int root(int x){
        return (dat[x]<0?x:root(dat[x]));
    }
    bool merge(int x,int y){
        x=root(x); y=root(y);
        hist.emplace(x,dat[x]);
        hist.emplace(y,dat[y]);
        if (x==y) return false;
        if (dat[x]>dat[y]) swap(x,y);
        dat[x]+=dat[y]; dat[y]=x;
        return true;
    }
    void undo(){
        dat[hist.top().first]=hist.top().second; hist.pop();
        dat[hist.top().first]=hist.top().second; hist.pop();
    }
    void snapshot(){
        while(!hist.empty()) hist.pop();
    }
    void rollback(){
        while(!hist.empty()) undo();
    }
    bool same(int x,int y){return root(x)==root(y);}
    int size(int x){return -dat[root(x)];}
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m,k; cin >> n >> m >> k;
    vector<int> c(n);
    for (int i=0;i<n;++i) cin >> c[i];

    UnionFindUndo UF(2*n);
    auto merge=[&](int a,int b){
        UF.merge(a,b+n);
        UF.merge(a+n,b);
    };
    map<pair<int,int>,vector<pair<int,int>>> mp;
    for (int i=0;i<m;++i){
        int a,b; cin >> a >> b;
        int ca=c[--a],cb=c[--b];
        if (ca>cb) swap(a,b),swap(ca,cb);
        if (ca==cb) merge(a,b);
        else mp[{ca,cb}].emplace_back(a,b);
    }
    UF.snapshot();

    int soli=0;
    vector<bool> ok(k,true);
    for (int i=0;i<n;++i){
        if (!ok[c[i]]) continue;
        if (UF.same(i,i+n)){
            ok[c[i]]=false;
            ++soli;
        }
    }
    ll ans=(ll)k*(k-1)/2-(ll)(k-soli+k-1)*soli/2;

    for (auto x:mp){
        int ca=x.first.first,cb=x.first.second;
        if (!ok[ca]) continue;
        if (!ok[cb]) continue;
        int check=0;
        for (auto e:x.second){
            int a=e.first,b=e.second;
            merge(a,b);
            check|=UF.same(a,a+n);
        }
        ans-=check;
        UF.rollback();
    }

    cout << ans << '\n';
}