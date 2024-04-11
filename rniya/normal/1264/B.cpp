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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int a,b,c,d; cin >> a >> b >> c >> d;
    int even=a+c,odd=b+d,n=a+b+c+d;
    vector<int> con(4),ans;
    iota(ALL(con),0);
    if (n&1){
        if (odd==n/2+1&&even==n/2){
            swap(con[0],con[3]); swap(a,d);
            swap(con[1],con[2]); swap(b,c);
        } else if (!(even==n/2+1&&odd==n/2)){
            cout << "NO" << '\n';
            return 0;
        }
    } else {
        if (!(even==n/2&&odd==n/2)){
            cout << "NO" << '\n';
            return 0;
        }
    }
    if (a>b){
        if (c||d){cout << "NO" << '\n'; return 0;}
        cout << "YES" << '\n';
        for (int i=0;i<n;++i) ans.emplace_back(i&1);
        for (int i=0;i<n;++i) cout << con[ans[i]] << (i+1==n?'\n':' ');
        return 0;
    }
    if (!a){
        for (int i=0;i<n;++i){
            if (!(i&1)) ans.emplace_back(2);
            else {
                ans.emplace_back(b?1:3);
                if (b) --b;
            }
        }
        cout << "YES" << '\n';
        for (int i=0;i<n;++i) cout << con[ans[i]] << (i+1==n?'\n':' ');
        return 0;
    }
    debug(a,b,c,d);
    for (int i=0;i<2*a-1;++i) ans.emplace_back(i&1);
    b-=max(0,a-1);
    debug(ans,b,c,d);
    for (int i=0;i<2*b-1;++i) ans.emplace_back((i&1)+1);
    c-=max(0,b-1);
    for (int i=0;i<c+d;++i) ans.emplace_back((i&1)+2);
    cout << "YES" << '\n';
    for (int i=0;i<n;++i) cout << con[ans[i]] << (i+1==n?'\n':' ');
}