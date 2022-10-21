#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(v) (v).begin(),(v).end()
#define debug(x) cout << #x << '=' << x << '\n'
const long long MOD=1e9+7;
//const long long MOD=998244353;
const int INF=1e9;
const long long IINF=1e18;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
const char dir[4]={'D','R','U','L'};

template<typename T>
istream &operator>>(istream &is,vector<T> &v){
    for (T &x:v) is >> x;
    return is;
}
template<typename T>
ostream &operator<<(ostream &os,const vector<T> &v){
    for (int i=0;i<v.size();++i){
        os << v[i] << (i+1==v.size()?'\n':' ');
    }
    return os;
}
template<typename T,typename U>
ostream &operator<<(ostream &os,const pair<T,U> &p){
    cout << '(' << p.first << ',' << p.second << ')';
    return os;
}

template<class T> inline bool chmin(T &a,T b){
    if (a>b){a=b; return true;} return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){a=b; return true;} return false;
}

template<typename T>
struct Dijkstra{
    const T inf=numeric_limits<T>::max();
    using P=pair<T,int>;
    int n;
    vector<vector<pair<int,T>>> G;
    vector<T> d;
    Dijkstra(int n):n(n),G(n),d(n){}
    void add_edge(int u,int v,T w){
        G[u].emplace_back(v,w);
    }
    vector<T> build(int s){
        fill(d.begin(),d.end(),inf);
        d[s]=0;
        priority_queue<P,vector<P>,greater<P>> pq;
        pq.emplace(d[s],s);
        while(!pq.empty()){
            P p=pq.top(); pq.pop();
            int v=p.second;
            if (d[v]<p.first) continue;
            for (auto &e:G[v]){
                int u=e.first; T c=e.second;
                if (d[v]+c<d[u]){
                    d[u]=d[v]+c;
                    pq.emplace(d[u],u);
                }
            }
        }
        return d;
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n);
    cin >> a;
    Dijkstra<int> D(n+1);
    for (int i=0;i<n;++i){
        if (0<=i-a[i]){
            if ((a[i]^a[i-a[i]])&1){
                D.add_edge(n,i,1);
            } else D.add_edge(i-a[i],i,1);
        }
        if (i+a[i]<n){
            if ((a[i]^a[i+a[i]])&1){
                D.add_edge(n,i,1);
            } else D.add_edge(i+a[i],i,1);
        }
    }
    vector<int> ans=D.build(n);
    for (int i=0;i<n;++i)
        if (INF<ans[i]) ans[i]=-1;
    for (int i=0;i<n;++i) cout << ans[i] << (i+1==n?'\n':' ');
}