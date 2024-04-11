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

const ll MAX=1e10;
ll a,b,c; int nxt;

int OUT_F(ll y){
    cout << y << endl;
    int res; cin >> res;
    if (res<=0) exit(0);
    return res;
}

ll OUT_S(int i){
    cout << i << endl;
    ll res; cin >> res;
    if (res<=0) exit(0);
    return res;
}

void solve_F(){
    cout << "First" << endl;
    nxt=OUT_F(MAX);
    ll sum;
    if (nxt==1){
        a+=MAX;
        sum=2*a-b-c;
    } else if (nxt==2){
        b+=MAX;
        sum=2*b-a-c;
    } else {
        c+=MAX;
        sum=2*c-a-b;
    }
    nxt=OUT_F(sum);
    if (nxt==1){
        a+=sum;
        sum=min(a-b,a-c);
    } else if (nxt==2){
        b+=sum;
        sum=min(b-a,b-c);
    } else {
        c+=sum;
        sum=min(c-a,c-b);
    }
    OUT_F(sum);
}

void solve_S(){
    cout << "Second" << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> a >> b >> c;
    solve_F();
}