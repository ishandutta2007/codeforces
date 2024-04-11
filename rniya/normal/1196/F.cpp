#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define debug(x) cout << #x << '=' << x << '\n'
const long long MOD=1e9+7;
//const long long MOD=998244353;
const int INF=1e9;
const long long IINF=1e15;
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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m,k; cin >> n >> m >> k;
    vector<vector<pair<int,ll>>> G(n);
    for (int i=0;i<m;++i){
        int x,y; ll w; cin >> x >> y >> w; --x,--y;
        G[x].emplace_back(y,w);
        G[y].emplace_back(x,w);
    }
    vector<ll> ans;
    for (int i=0;i<n;++i){
        unordered_map<int,ll> d;
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq2;
        d[i]=0; pq2.emplace(d[i],i);
        int update=0;
        vector<pair<ll,int>> res;
        while(!pq2.empty()){
            auto p=pq2.top(); pq2.pop();
            int v=p.second;
            if (d[v]<p.first) continue;
            if (!ans.empty()&&ans.back()<=p.first) break;
            if (v!=i){
                res.emplace_back(d[v],v); ++update;
                if (update==k) break;
            }
            for (auto e:G[v]){
                int u=e.first,cost=e.second;
                if (!ans.empty()&&ans.back()<=d[v]+cost) continue;
                if (!d.count(u)||d[v]+cost<d[u]){
                    d[u]=d[v]+cost;
                    pq2.emplace(d[u],u);
                }
            }
        }
        for (auto p:res) if (i<p.second) ans.emplace_back(p.first);
        sort(ans.begin(),ans.end());
        if (k<ans.size()) ans.resize(k);
    }
    cout << ans.back() << '\n';
}