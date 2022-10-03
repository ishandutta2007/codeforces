#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=1000000007,MAX=200005;
const ll INF=1LL<<60;
vector<pair<int,ll>> G[MAX];
ll dis[MAX];
int N,L;
vector<pair<int,int>> use;
void dijkstra(int u){
    dis[u]=0;
    vector<priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>> PQ(N);
    
    PQ[0].push(mp(0,u));
    for(int q=0;q<N;q++){
        while(!PQ[q].empty()){
            ll a=PQ[q].top().fi,b=PQ[q].top().se;PQ[q].pop();
            if(dis[b]<a) continue;
            for(int i=0;i<G[b].size();i++){
                int c=G[b][i].first;
                ll d=G[b][i].second;
                if(dis[c]>dis[b]+d){
                    dis[c]=dis[b]+d;
                    PQ[use[c].fi].push(make_pair(dis[c],c));
                }
            }
        }
    }
    return;
}//a,d

int main() {
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int M,K;cin>>N>>M>>K;
        vector<ll> x(N);
        for(int i=0;i<N;i++) cin>>x[i];
        vector<vector<int>> que(K);
        use.clear();
        use.push_back(mp(0,0));
        use.push_back(mp(N-1,M-1));
        for(int i=0;i<K;i++){
            int a,b,c,d,h;cin>>a>>b>>c>>d>>h;a--;b--;c--;d--;
            que[i]={a,b,c,d,-h};
            use.push_back(mp(a,b));
            use.push_back(mp(c,d));
        }
        sort(all(use));
        use.erase(unique(all(use)),use.end());
        
        L=si(use);
        for(int i=0;i<L;i++){
            G[i].clear();
            dis[i]=INF;
        }
        for(int i=0;i<K;i++){
            int a=lower_bound(all(use),mp(que[i][0],que[i][1]))-use.begin();
            int b=lower_bound(all(use),mp(que[i][2],que[i][3]))-use.begin();
            G[a].push_back(mp(b,que[i][4]));
        }
        for(int i=0;i+1<L;i++){
            if(use[i].fi==use[i+1].fi){
                G[i].push_back(mp(i+1,x[use[i].fi]*(use[i+1].se-use[i].se)));
                G[i+1].push_back(mp(i,x[use[i].fi]*(use[i+1].se-use[i].se)));
            }
        }
        dijkstra(0);
        if(dis[L-1]==INF) cout<<"NO ESCAPE\n";
        else cout<<dis[L-1]<<"\n";
    }
}