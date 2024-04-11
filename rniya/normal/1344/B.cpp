#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(x) (x).begin(),(x).end()
const long long MOD=1e9+7;
// const long long MOD=998244353;
const int INF=1e9;
const long long IINF=1e18;
const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
const char dir[4]={'D','R','U','L'};
#define LOCAL

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
    cout << '(' << p.first << ',' << p.second << ')';
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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m; cin >> n >> m;
    vector<string> S(n); cin >> S;
    int check=0;
    vector<int> row(n,0),col(m,0);
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            if (S[i][j]=='#'){
                check=1; row[i]=1; col[j]=1;
            }
        }
    }
    if (!check){cout << 0 << '\n'; return 0;}
    for (int i=0;i<n;++i){
        int now=0;
        for (int j=0;j<m;++j){
            if (S[i][j]=='#'){
                if (now==0) now=1;
                if (now==2) now=3;
            } else {
                if (now==1) now=2;
            }
        }
        if (now==3){
            cout << -1 << '\n';
            return 0;
        }
    }
    for (int j=0;j<m;++j){
        int now=0;
        for (int i=0;i<n;++i){
            if (S[i][j]=='#'){
                if (now==0) now=1;
                if (now==2) now=3;
            } else {
                if (now==1) now=2;
            }
        }
        if (now==3){
            cout << -1 << '\n';
            return 0;
        }
    }
    vector<vector<int>> seen(n,vector<int>(m,0));
    auto dfs=[&](auto self,int x,int y)->void{
        seen[x][y]=1;
        for (int i=0;i<4;++i){
            int nx=x+dx[i],ny=y+dy[i];
            if (nx<0||n<=nx||ny<0||m<=ny) continue;
            if (seen[nx][ny]) continue;
            if (S[nx][ny]=='#') self(self,nx,ny);
        }
    };
    int ans=0;
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            if (S[i][j]=='#'&&!seen[i][j]){
                ++ans;
                dfs(dfs,i,j);
            }
        }
    }
    int allr=1,allc=1;
    for (int i=0;i<n;++i) if (!row[i]) allr=0;
    for (int j=0;j<m;++j) if (!col[j]) allc=0;
    for (int i=0;i<n;++i){
        if (!row[i]&&allc){
            cout << -1 << '\n';
            return 0;
        }
    }
    for (int j=0;j<m;++j){
        if (!col[j]&&allr){
            cout << -1 << '\n';
            return 0;
        }
    }
    cout << ans << '\n';
}