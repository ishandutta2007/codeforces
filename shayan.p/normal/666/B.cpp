// Phoenix

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=3010,mod=1e9+7;
const ll inf=1e18;

vector<int>v[maxn];
pii fr[2][3][maxn];// u -> sth // sth -> u
int h[maxn];
queue<int>q;
pair<int,pair<pii,pii> >ans;

void Push(int a,int b,pii p){
    if(fr[a][0][b]<p) fr[a][2][b]=fr[a][1][b],fr[a][1][b]=fr[a][0][b],fr[a][0][b]=p;
    else if(fr[a][1][b]<p) fr[a][2][b]=fr[a][1][b],fr[a][1][b]=p;
    else if(fr[a][2][b]<p) fr[a][2][b]=p;
}

void bfs(int u,bool is=0){
    int rt=u;
    memset(h,0,sizeof h);
    h[u]=1;
    q.push(u);
    while(!q.empty()){
	u=q.front();
	q.pop();
	if(is){
	    for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
		    if(fr[1][i][rt].S!=rt && fr[1][i][rt].S!=u && fr[1][i][rt].S!=fr[0][j][u].S && rt!=u && rt!=fr[0][j][u].S && u!=fr[0][j][u].S)
			ans=max(ans,{fr[1][i][rt].F+h[u]+fr[0][j][u].F-3,{{fr[1][i][rt].S,rt},{u,fr[0][j][u].S}}});
	}
	else{
	    Push(0,rt,{h[u],u});
	    Push(1,u,{h[u],rt});
	}
	for(int y:v[u]){
	    if(h[y]==0){
		h[y]=h[u]+1;
		q.push(y);
	    }
	}
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
	int a,b;cin>>a>>b;
	v[a].PB(b);
    }
    for(int i=1;i<=n;i++){
	bfs(i);
    }
    for(int i=1;i<=n;i++){
	bfs(i,1);
    }
    cout<<ans.S.F.F<<" "<<ans.S.F.S<<" "<<ans.S.S.F<<" "<<ans.S.S.S<<endl;
    return 0;
}