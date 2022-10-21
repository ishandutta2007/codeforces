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
    int n; cin >> n;
    vector<vector<int>> cnt(n,vector<int>(3,0));
    for (int i=0;i<n;++i){
        string S; cin >> S;
        for (char c:S) ++cnt[i][(c=='N')];
        cnt[i][2]=cnt[i][0]-cnt[i][1];
    }
    int B,N;
    auto check=[&](int mid){
        vector<vector<int>> range(3,vector<int>(2,-INF));
        for (int i=0;i<3;++i) range[i][1]=INF;
        for (int i=0;i<n;++i){
            for (int j=0;j<3;++j){
                range[j][0]=max(range[j][0],cnt[i][j]-mid);
                range[j][1]=min(range[j][1],cnt[i][j]+mid);
            }
        }
        range[2][0]=max(range[2][0],range[0][0]-range[1][1]);
        range[2][1]=min(range[2][1],range[0][1]-range[1][0]);
        for (int j=0;j<3;++j){
            if (range[j][0]>range[j][1]){
                return false;
            }
        }
        int diff=range[2][0];
        if (range[2][0]==0) diff=range[2][1];
        if (diff<=range[0][1]-range[1][1]) N=range[1][1],B=diff+N;
        else B=range[0][1],N=B-diff;
        if (B==0&&N==0) return false;
        return true;
    };
    int ub=5e5+10,lb=-1,mid;
    while(ub-lb>1){
        mid=(ub+lb)>>1;
        (check(mid)?ub:lb)=mid;
    }
    cout << ub << '\n';
    for (int i=0;i<B;++i) cout << 'B';
    for (int i=0;i<N;++i) cout << 'N';
    cout << '\n';
}