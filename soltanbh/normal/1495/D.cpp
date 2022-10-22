#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=502,mod=998244353;

int n,m,dist[N][N],ans[N][N];
vector<int> g[N];

void bfs(int x){
    fill(dist[x],dist[x]+N,N);
    dist[x][x]=0;
    queue<int> q;
    q.push(x);
    while(q.size()){
        int u=q.front();
        q.pop();
        f(i,0,g[u].size())
            if(dist[x][g[u][i]]==N){
                q.push(g[u][i]);
                dist[x][g[u][i]]=dist[x][u]+1;
            }
    }
}
int solve(int u,int v){
    int ans=1,d=dist[u][v];
    f(i,1,n+1)
        if(i!=u){
            int c1=0,c2=0;
            f(j,0,g[i].size()){
                if(dist[u][g[i][j]]+1==dist[u][i] && dist[v][g[i][j]]+1==dist[v][i])
                    c1++;
                if(dist[u][g[i][j]]+1==dist[u][i] && dist[v][g[i][j]]-1==dist[v][i])
                    c2++;
            }
            if(d<dist[u][i]+dist[v][i]){
                ans=1ll*ans*c1%mod;
            }
            else
                if(1!=c2)
                    ans=0;
        }
    return ans;
}

int main(){
    cin>>n>>m;
    f(i,0,m){
        int x,y;
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    f(i,1,n+1) 
        bfs(i);
    f(i,1,n+1)
        f(j,1,n+1)
            ans[i][j]=solve(i,j);
    f(i,1,n+1){
        f(j,1,n+1)
            cout<<min(ans[i][j],ans[j][i])<<" ";
        cout<<endl;
    }
}
/*
1 0 0 0 0 0 0 0 
0 2 0 0 0 0 2 0 
0 0 1 0 1 1 0 0 
0 0 0 2 0 0 0 2 
0 0 1 0 1 1 0 0 
0 0 1 0 1 1 0 0 
0 2 0 0 0 0 2 0 
*/