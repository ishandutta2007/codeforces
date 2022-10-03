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
const int mod=998244353,MAX=200005;
const ll INF=1LL<<60;

vector<int> preG[MAX],G[MAX];
int par[MAX],dis[MAX];
bool leaf[MAX];

void pre(int u,int p){
    bool ch=false;
    par[u]=p;
    for(int to:preG[u]){
        if(to==p) continue;
        dis[to]=dis[u]+1;
        G[u].push_back(to);
        pre(to,u);
        ch=true;
    }
    if(!ch) leaf[u]=true;
}

set<int> SE[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll N,K;cin>>N>>K;
    ll ans=-INF;
    
    for(int i=0;i<N-1;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        preG[a].push_back(b);
        preG[b].push_back(a);
    }
    dis[0]=1;
    pre(0,-1);
    
    for(int i=0;i<N;i++){
        if(leaf[i]){
            SE[dis[i]].insert(i);
        }
    }
    int h=N;
    ll rem=N;
    
    for(int q=1;q<=K;q++){
        while(h>=1&&si(SE[h])==0) h--;
        if(h==0){
            chmax(ans,(N-q)*q);
        }else{
            int a=*(SE[h].begin());
            rem-=h;
            queue<int> Q;
            SE[h].erase(a);
            while(a>=0&&dis[a]){
                Q.push(a);
                dis[a]=0;
                a=par[a];
            }
            
            while(!Q.empty()){
                int u=Q.front();Q.pop();
                for(int to:G[u]){
                    int x=dis[to];
                    if(chmin(dis[to],dis[u]+1)){
                        if(leaf[to]){
                            SE[x].erase(to);
                            SE[dis[to]].insert(to);
                        }
                        Q.push(to);
                    }
                }
            }
            
            ll op;
            if(rem>=N/2) op=N/2;
            else op=rem;
            chmax(ans,(N-q-op)*(q-op));
        }
        
        //cout<<q<<" "<<ans<<endl;
    }
    
    cout<<ans<<endl;
}