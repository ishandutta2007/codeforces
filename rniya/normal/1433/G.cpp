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

template<typename T>
struct Dijkstra{
    struct edge{
        int to; T cost;
        edge(int to,T cost):to(to),cost(cost){}
        bool operator<(const edge &e) const {
            return cost>e.cost;
        }
    };
    vector<vector<edge>> G;
    vector<T> dp;
    vector<int> pre;
    Dijkstra(int n):G(n),dp(n),pre(n){}
    void add_edge(int u,int v,T c){
        G[u].emplace_back(v,c);
    }
    vector<int> build(int s){
        int n=G.size();
        fill(dp.begin(),dp.end(),numeric_limits<T>::max());
        fill(pre.begin(),pre.end(),-1);
        priority_queue<edge> pq;
        dp[s]=0;
        pq.emplace(s,dp[s]);
        while(!pq.empty()){
            auto p=pq.top(); pq.pop();
            int v=p.to;
            if (dp[v]<p.cost) continue;
            for (auto e:G[v]){
                if (dp[v]+e.cost<dp[e.to]){
                    dp[e.to]=dp[v]+e.cost;
                    pre[e.to]=v;
                    pq.emplace(e.to,dp[e.to]);
                }
            }
        }
        return dp;
    }
    vector<int> restore(int t){
        vector<int> res;
        if (pre[t]<0) return res;
        while(~t){
            res.emplace_back(t);
            t=pre[t];
        }
        reverse(res.begin(),res.end());
        return res;
    }
    T operator[](int to){return dp[to];}
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m,k; cin >> n >> m >> k;

    Dijkstra<int> D(n);
    vector<int> x(m),y(m),w(m);
    for (int i=0;i<m;++i){
        cin >> x[i] >> y[i] >> w[i]; --x[i],--y[i];
        D.add_edge(x[i],y[i],w[i]);
        D.add_edge(y[i],x[i],w[i]);
    }
    vector<vector<int>> dp(n);
    for (int i=0;i<n;++i) dp[i]=D.build(i);

    vector<int> a(k),b(k);
    for (int i=0;i<k;++i) cin >> a[i] >> b[i],--a[i],--b[i];
    ll ans=IINF;
    for (int i=0;i<m;++i){
        ll sum=0;
        for (int j=0;j<k;++j){
            int cost=dp[a[j]][b[j]];
            chmin(cost,dp[a[j]][x[i]]+dp[y[i]][b[j]]);
            chmin(cost,dp[a[j]][y[i]]+dp[x[i]][b[j]]);
            sum+=cost;
        }
        chmin(ans,sum);
    }

    cout << ans << '\n';
}