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

const int MAX_N=5010;
int n,a[MAX_N],b[MAX_N];

int query(int i,int j){
    cout << "? " << i << ' ' << j << endl;
    int res; cin >> res;
    if (res==-1) exit(0);
    return res;
}

void answer(ll a,vector<int> v){
    cout << "!\n";
    cout << a << '\n';
    for (int i=0;i<v.size();++i) cout << v[i] << (i+1==v.size()?"":" ");
    cout << endl;
}

int XOR(int p,int i,int q,int j){
    if (p==0&&q==0) return b[i]^b[j];
    if (p==1&&q==1) return a[i]^a[j];
    if (p>q) swap(i,j);
    return b[i]^b[0]^a[j];
}

vector<int> check(int x){
    vector<int> p(n); p[0]=x;
    for (int i=1;i<n;++i) p[i]=XOR(0,0,0,i)^p[0];

    vector<bool> cnt(n,false);
    vector<int> c(n);
    for (int i=0;i<n;++i){
        if (p[i]<0||n<=p[i]) return {};
        if (cnt[p[i]]) return {};
        cnt[p[i]]=true; c[p[i]]=i;
    }

    for (int i=0;i<n;++i){
        if (a[i]!=(p[0]^c[i])){
            return {};
        }
    }
    return p;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;

    for (int i=0;i<n;++i) a[i]=query(0,i);
    b[0]=a[0];
    for (int i=1;i<n;++i) b[i]=query(i,0);

    vector<int> ans;
    int cnt=0;
    for (int i=0;i<n;++i){
        if (a[i]!=i) continue;
        vector<int> res=check(i);
        if (res.empty()) continue;
        if (cnt++==0) ans=res;
    }

    answer(cnt,ans);
}