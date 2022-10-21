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
ostream &operator<< (ostream &os,const set<T> &s){
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

template<class T1,class T2> inline bool chmin(T1 &a,T2 b){
    if (a>b){a=b; return true;} return false;
}
template<class T1,class T2> inline bool chmax(T1 &a,T2 b){
    if (a<b){a=b; return true;} return false;
}

const int MAX_N=2e5+10;

int n,m,k;
vector<pair<int,int>> G[MAX_N];
vector<int> cand[MAX_N];

void bfs(){
    queue<int> que;
    vector<int> dep(n,-1);
    dep[0]=0; que.emplace(0);
    while(!que.empty()){
        int v=que.front(); que.pop();
        for (auto e:G[v]){
            int u=e.first;
            if (~dep[u]){
                if (dep[u]==dep[v]-1){
                    cand[v].emplace_back(e.second);
                }
                continue;
            }
            dep[u]=dep[v]+1;
            que.emplace(u);
        }
    }
}

void dfs(int v,set<int> &use){
    if (!k) return;
    if (v==n){
        int now=0; --k;
        for (int i=0;i<m;++i){
            if (use.count(i)) cout << '1',++now;
            else cout << '0';
        }
        cout << '\n'; return;
    }
    for (int u:cand[v]){
        use.emplace(u);
        dfs(v+1,use);
        if (!k) return;
        use.erase(u);
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i=0;i<m;++i){
        int a,b; cin >> a >> b; --a,--b;
        G[a].emplace_back(b,i);
        G[b].emplace_back(a,i);
    }
    bfs();
    ll sum=1; int ok=0;
    for (int i=1;i<n;++i){
        sum*=cand[i].size();
        if (k<sum){
            cout << k << '\n';
            ok=1; break;
        }
    }
    if (!ok) cout << sum << '\n';
    set<int> v;
    dfs(1,v);
}