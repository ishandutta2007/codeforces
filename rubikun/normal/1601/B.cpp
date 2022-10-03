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
const int mod=1000000007,MAX=300005,INF=1<<29;

int dis[MAX];
pair<int,int> par[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<int> A(N+1),B(N+1),to(N+1);
    for(int i=1;i<=N;i++) cin>>A[i];
    for(int i=1;i<=N;i++) cin>>B[i];
    for(int i=1;i<=N;i++) to[i]=i+B[i];
    for(int i=0;i<MAX;i++){
        dis[i]=INF;
        par[i]=mp(-1,-1);
    }
    
    set<pair<int,int>> alive;
    for(int i=0;i<N;i++) alive.insert(mp(i,to[i]));
    
    dis[N]=0;
    queue<int> Q;Q.push(N);
    
    while(!Q.empty()){
        int u=Q.front();Q.pop();
        if(u-A[u]==0){
            chmin(dis[0],dis[u]+1);
            par[0]=mp(u,0);
            break;
        }
        auto it=alive.lower_bound(mp(u-A[u],to[u-A[u]]));
        while(it!=alive.end()&&(*it).fi<=u){
            int a=(*it).se;
            if(chmin(dis[a],dis[u]+1)){
                par[a]=mp(u,(*it).fi);
                Q.push(a);
            }
            it=alive.erase(it);
        }
    }
    
    if(dis[0]==INF) cout<<-1<<"\n";
    else{
        cout<<dis[0]<<"\n";
        int now=0;
        vector<int> ans;
        while(now!=N){
            ans.push_back(par[now].se);
            now=par[now].fi;
        }
        reverse(all(ans));
        for(int a:ans) cout<<a<<" ";
        cout<<"\n";
    }
}