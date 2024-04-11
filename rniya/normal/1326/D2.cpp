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

vector<int> Manacher(const string &s){
    int n=s.size();
    vector<int> res(n);
    for (int i=0,j=0;i<n;){
        while(i-j>=0&&i+j<n&&s[i-j]==s[i+j]) ++j;
        res[i]=j;
        int k=1;
        while(i-k>=0&&i+k<n&&k+res[i-k]<j) res[i+k]=res[i-k],++k;
        i+=k,j-=k;
    }
    return res;
}

void solve(){
    string S; cin >> S;
    int n=S.size();
    string ret="";
    int palin=1;
    for (int i=0;i<n;++i){
        if (S[i]!=S[n-1-i]) palin=0;
    }
    if (palin){cout << S << '\n'; return;}
    for (int _=0;_<2;++_){
        string T=S,U="";
        reverse(ALL(T));
        for (int i=0;i<n;++i){
            U+=S[i];
            if (i+1!=n) U+='$';
        }
        vector<int> odd=Manacher(S),even=Manacher(U);
        int pre=0;
        while(pre<n&&S[pre]==T[pre]) ++pre;
        int ans,len=0;
        for (int i=0;i<n;++i){
            if (i-odd[i]+1<=pre&&(i-odd[i]+1)*2<=n){
                if ((i-odd[i]+1)*2+odd[i]*2-1>n) continue;
                if (chmax(len,(i-odd[i]+1)*2+odd[i]*2-1)){
                    ans=i;
                }
            }
        }
        for (int i=1;i<2*n-1;i+=2){
            if (i/2-even[i]/2+1<=pre&&(i/2-even[i]/2+1)*2<=n){
                if ((i/2-even[i]/2+1)*2+even[i]/2*2>n) continue;
                if (chmax(len,(i/2-even[i]/2+1)*2+even[i]/2*2)){
                    ans=i+n;
                }
            }
        }
        string res="";
        if (ans<n){
            for (int i=0;i<ans+odd[ans];++i) res+=S[i];
            for (int i=ans-odd[ans];i>=0;--i) res+=S[i];
        } else {
            ans-=n;
            for (int i=0;i<ans/2+even[ans]/2+1;++i) res+=S[i];
            for (int i=ans/2-even[ans]/2;i>=0;--i) res+=S[i];
        }
        if (_) reverse(ALL(res));
        if (ret.size()<res.size()) ret=res;
        reverse(ALL(S));
    }
    cout << ret << '\n';
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        solve();
    }
}