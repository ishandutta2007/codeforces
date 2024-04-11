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

vector<int> Zalgorithm(const string &s){
    int n=s.size();
    vector<int> z(n);
    z[0]=n;
    int i=1,j=0;
    while(i<n){
        while(i+j<n&&s[j]==s[i+j]) ++j;
        z[i]=j;
        if (j==0){++i; continue;}
        int k=1;
        while(i+k<n&&k+z[k]<j) z[i+k]=z[k],++k;
        i+=k,j-=k;
    }
    return z;
}

vector<int> LCP(const string &s,const string &t){
    vector<int> Z=Zalgorithm(t+s);
    for (int &i:Z) i=min(i,(int)t.size());
    return vector<int>(Z.begin()+t.size(),Z.end());
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S,T; cin >> S >> T;

    vector<int> z=Zalgorithm(T);
    int len;
    for (len=1;len<T.size();++len){
        if (len+z[len]==T.size()) break;
    }
    string U=T.substr(0,len),W=T.substr(len,T.size()-len);

    vector<int> cnt(2,0),u(2,0),w(2,0);
    for (char c:S) ++cnt[c-'0'];
    for (char c:U) ++u[c-'0'];
    for (char c:W) ++w[c-'0'];
    if (cnt[0]<w[0]||cnt[1]<w[1]){
        cout << S << '\n';
        return 0;
    }

    int Max=min((u[0]?(cnt[0]-w[0])/u[0]:INF),(u[1]?(cnt[1]-w[1])/u[1]:INF));
    string ans="";
    for (int i=0;i<Max;++i) ans+=U;
    ans+=W;
    for (char c:ans) --cnt[c-'0'];
    for (int i=0;i<cnt[0];++i) ans+='0';
    for (int i=0;i<cnt[1];++i) ans+='1';

    cout << ans << '\n';
}