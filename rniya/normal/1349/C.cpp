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
    int n,m,t; cin >> n >> m >> t;
    vector<string> S(n); cin >> S;
    vector<vector<bool>> seen(n,vector<bool>(m,false));
    vector<vector<int>> d(n,vector<int>(m,INF));
    deque<pair<int,int>> deq;
    auto dfs=[&](auto self,int x,int y)->void{
        seen[x][y]=true;
        for (int k=0;k<4;++k){
            int nx=x+dx[k],ny=y+dy[k];
            if (nx<0||n<=nx||ny<0||m<=ny) continue;
            if (seen[nx][ny]) continue;
            if (S[nx][ny]!=S[x][y]) continue;
            self(self,nx,ny);
        }
    };
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            if (!seen[i][j]){
                bool ok=false;
                for (int k=0;k<4;++k){
                    int nx=i+dx[k],ny=j+dy[k];
                    if (nx<0||n<=nx||ny<0||m<=ny) continue;
                    if (S[nx][ny]==S[i][j]) ok=true;
                }
                if (!ok) continue;
                dfs(dfs,i,j);
                d[i][j]=0;
                deq.emplace_back(i,j);
            }
        }
    }
    while(!deq.empty()){
        auto p=deq.front(); deq.pop_front();
        int x=p.first,y=p.second;
        for (int k=0;k<4;++k){
            int nx=x+dx[k],ny=y+dy[k];
            if (nx<0||n<=nx||ny<0||m<=ny) continue;
            if (S[nx][ny]==S[x][y]&&chmin(d[nx][ny],d[x][y])){
                deq.emplace_front(nx,ny);
            }
            if (S[nx][ny]!=S[x][y]&&chmin(d[nx][ny],d[x][y]+1)){
                deq.emplace_back(nx,ny);
            }
        }
    }
    for (;t--;){
        int i,j; ll p; cin >> i >> j >> p; --i,--j;
        int now=S[i][j]-'0';
        if (d[i][j]!=INF&&d[i][j]<p&&(p-d[i][j])%2==1) now^=1;
        cout << now << '\n';
    }
}