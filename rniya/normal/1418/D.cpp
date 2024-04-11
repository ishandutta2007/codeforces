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
template<typename T>
ostream &operator<<(ostream &os,const multiset<T> &s){
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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,q; cin >> n >> q;
    vector<int> p(n); cin >> p;
    sort(ALL(p));

    set<int> piles;
    multiset<int> dist;
    for (int i=0;i<n;++i){
        piles.emplace(p[i]);
        if (i) dist.emplace(p[i]-p[i-1]);
    }

    auto query=[&](){
        if (piles.size()<=2) return 0;
        int M=*piles.rbegin(),m=*piles.begin();
        int Max=*dist.rbegin();
        return M-m-Max;
    };
    auto add=[&](int x){
        int l=-1,r=-1;
        auto itr=piles.upper_bound(x);
        if (itr!=piles.end()) r=*itr;
        if (itr!=piles.begin()) l=*(--itr);
        if (~l&&~r) dist.erase(dist.lower_bound(r-l));
        if (~l) dist.emplace(x-l);
        if (~r) dist.emplace(r-x);
        piles.emplace(x);
    };
    auto del=[&](int x){
        int l=-1,r=-1;
        auto itr=piles.upper_bound(x);
        if (itr!=piles.end()) r=*itr;
        if ((--itr)!=piles.begin()) l=*(--itr);
        if (~l) dist.erase(dist.lower_bound(x-l));
        if (~r) dist.erase(dist.lower_bound(r-x));
        if (~l&&~r) dist.emplace(r-l);
        piles.erase(x);
    };

    cout << query() << '\n';
    for (;q--;){
        int t,x; cin >> t >> x;
        if (t) add(x);
        else del(x);
        cout << query() << '\n';
    }
}