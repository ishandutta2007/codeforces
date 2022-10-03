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
const int mod=1000000007,MAX=200005,INF=1<<30;

vector<int> G[MAX];
int par[MAX],cntch[MAX],depth[MAX];
set<pair<int,int>> SE;

void init(int sz){
    for(int i=0;i<sz;i++){
        G[i].clear();
        par[i]=-1;
        depth[i]=0;
        cntch[i]=0;
    }
    SE.clear();
}

void make(int u,int p){
    par[u]=p;
    for(int to:G[u]){
        if(to==p) continue;
        cntch[u]++;
        depth[to]=depth[u]+1;
        make(to,u);
    }
    if(cntch[u]==0){
        SE.insert(mp(depth[u],u));
    }
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        init(N);
        for(int i=0;i<N-1;i++){
            int a,b;cin>>a>>b;
            a--;b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        make(0,-1);
        int ans=si(SE),X=0,sum=0;
        //cout<<si(SE)<<" ";
        while(1){
            if(si(SE)==0) break;
            auto a=*SE.rbegin();
            if(a.fi==0){
                break;
            }
            if(a.fi==1){
                for(auto v:SE){
                    if(v.fi==1) X++;
                }
                break;
            }
            int p=par[a.se];
            sum+=cntch[p];
            sum--;
            for(int to:G[p]){
                if(SE.count(mp(depth[to],to))) SE.erase(mp(depth[to],to));
            }
            int pp=par[p];
            cntch[pp]--;
            if(cntch[pp]==0){
                SE.insert(mp(depth[pp],pp));
            }
        }
        
        sum=sum+max(X,1);
        
        cout<<min(ans,sum)<<"\n";
    }
}