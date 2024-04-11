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

const int MAX_A=1e6;

void solve(int k){
    if (k<=MAX_A){
        int x=MAX_A/1998*1998-k%1998-1998,y=(k+x)/1998+1;

        vector<int> ans(2000,0);
        ans[0]=x,ans[1]=-(x+1),ans[1998]=-1,ans[1999]=y;

        cout << 2000 << '\n';
        cout << ans << '\n';
        // int s=max({x,(y-1)*1998,(y-2)*2000})-max(x,y)-k;
        // if (s!=0){debug(k);}
    } else {
        int x=MAX_A/2000*2000-k%2000-2000,y=(k+x)/2000+2;

        vector<int> ans(2000,0);
        ans[0]=x,ans[1]=-(x+1),ans[1998]=-1,ans[1999]=y;

        cout << 2000 << '\n';
        cout << ans << '\n';
        debug(x,y);
        // int s=max({x,(y-1)*1998,(y-2)*2000})-max(x,y)-k;
        // if (s!=0){debug(k);}
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int k; cin >> k;
    solve(k);
    // for (int i=0;i<2*MAX_A;++i) solve(i);
}