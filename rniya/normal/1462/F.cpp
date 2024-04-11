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

template<typename T>
class BinaryIndexedTree{
    T sum(int i){
        T res=T();
        for (;i>0;i-=(i&-i)) res+=dat[i];
        return res;
    }
public:
    int n;
    vector<T> dat;
    BinaryIndexedTree(int n_):n(n_+1),dat(n+1,0){}
    void add(int i,const T &x){
        for (++i;i<=n;i+=(i&-i)) dat[i]+=x;
    }
    T query(int l,int r){return sum(r)-sum(l);}
    int lower_bound(T x) const {
        if (x<=0) return 0;
        int pos=0,k=1;
        while (k<n) k<<=1;
        for (;k>0;k>>=1){
            if (pos+k<=n&&dat[pos+k]<x){
                x-=dat[pos+k]; pos+=k;
            }
        }
        return pos;
    }
    int upper_bound(T x) const {return lower_bound(x+1);}
    T operator[](int i){return query(i,i+1);}
};

template<typename T> map<T,int> compress(vector<T> v){
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    map<T,int> res;
    for (int i=0;i<v.size();++i) res[v[i]]=i;
    return res;
}

void solve(){
    int n; cin >> n;
    vector<int> l(n),r(n),c;
    for (int i=0;i<n;++i){
        cin >> l[i] >> r[i];
        c.emplace_back(l[i]);
        c.emplace_back(r[i]);
    }

    map<int,int> mp=compress(c);
    int m=mp.size();
    BinaryIndexedTree<int> BL(m),BR(m);
    for (int i=0;i<n;++i){
        l[i]=mp[l[i]]; r[i]=mp[r[i]];
        BL.add(l[i],1);
        BR.add(r[i],1);
    }

    int ans=n;
    for (int i=0;i<n;++i){
        int sum=BR.query(0,l[i])+BL.query(r[i]+1,m);
        ans=min(ans,sum);
    }

    cout << ans << '\n';
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        solve();
    }
}