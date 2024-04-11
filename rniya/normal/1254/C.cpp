#include <bits/stdc++.h>
using namespace std;
#define LOCAL
#pragma region Macros
typedef long long ll;
#define ALL(x) (x).begin(),(x).end()
const long long MOD=1e9+7;
// const long long MOD=998244353;
const int INF=1e9;
const long long IINF=5e18;
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

ll query(int t,int i,int j,int k){
    cout << t << ' ' << i+1 << ' ' << j+1 << ' ' << k+1 << endl;
    ll res; cin >> res;
    return res;
}

void answer(vector<int> v){
    int s,n=v.size();
    for (int i=0;i<n;++i) if (!v[i]) s=i;
    cout << 0;
    for (int i=0;i<n;++i) cout << ' ' << v[(s+i)%n]+1;
    cout << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<ll> area(n),sign1(n),sign2(n);
    area[0]=area[1]=0;
    int p=0,q=0;
    for (int i=2;i<n;++i){
        area[i]=query(1,0,1,i);
        sign1[i]=query(2,0,1,i);
        if (sign1[i]==1&&area[p]<area[i]) p=i;
        if (sign1[i]==-1&&area[q]<area[i]) q=i;
    }
    for (int i=0;i<n;++i){
        if (i==p||i==q) continue;
        sign2[i]=query(2,p,i,q);
    }
    vector<vector<pair<ll,int>>> P(4);
    for (int i=0;i<n;++i){
        if (i==0||i==1||i==p||i==q) continue;
        if (sign1[i]==1&&sign2[i]==1) P[0].emplace_back(area[i],i);
        if (sign1[i]==-1&&sign2[i]==1) P[1].emplace_back(area[i],i);
        if (sign1[i]==-1&&sign2[i]==-1) P[2].emplace_back(area[i],i);
        if (sign1[i]==1&&sign2[i]==-1) P[3].emplace_back(area[i],i);
    }
    vector<int> ans,f={p,0,q,1};
    for (int i=0;i<4;++i){
        if (!(i&&f[i]==f[i-1])) ans.emplace_back(f[i]);
        sort(ALL(P[i]));
        if (!(i&1)) reverse(ALL(P[i]));
        for (auto x:P[i]) ans.emplace_back(x.second);
    }
    answer(ans);
}