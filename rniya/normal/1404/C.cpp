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
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,q; cin >> n >> q;
    vector<int> a(n);
    for (int i=0;i<n;++i) cin >> a[i],a[i]-=i+1;

    BinaryIndexedTree<int> BIT1(n+1);
    vector<pair<int,int>> dis;
    for (int i=0;i<n;++i){
        int time;
        if (a[i]>0) time=-1;
        else time=min(i,BIT1.lower_bound(a[i]+i+1)-2);
        dis.emplace_back(time,i);
        BIT1.add0(time+1,1);
    }
    sort(dis.begin(),dis.end());

    struct query{
        int x,y,id;
        query(int x,int y,int id):x(x),y(y),id(id){}
        const bool operator<(const query &other){
            return x<other.x;
        }
    };
    vector<query> Q;
    for (int i=0;i<q;++i){
        int x,y; cin >> x >> y;
        Q.emplace_back(x,n-y,i);
    }
    sort(Q.begin(),Q.end());

    vector<int> ans(q);
    BinaryIndexedTree<int> BIT2(n+1);
    for (int i=0;i<n;++i) BIT2.add0(i,1);
    int now=0;
    for (int i=0;i<q;++i){
        while(now<n&&dis[now].first<Q[i].x){
            BIT2.add0(dis[now++].second,-1);
        }
        ans[Q[i].id]=BIT2.query0(Q[i].x,Q[i].y);
    }

    for (int i=0;i<q;++i) cout << ans[i] << '\n';
}