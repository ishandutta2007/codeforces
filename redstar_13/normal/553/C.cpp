#include <bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define mod 1000000007
using namespace std;
int power(int a, int b, int m, int ans=1) {
    for (; b; b>>=1, a=1LL*a*a%m) if (b&1) ans=1LL*ans*a%m;
    return ans;
}
typedef pair<int,int> pii;
typedef vector<pii> VI;

#define NN 100010
VI adj[NN];
int vst[NN];
int flag;

void dfs(int u){
	for(int i=0;i<adj[u].size();i++){
		int v=adj[u][i].x;
		int r=adj[u][i].y;
		if(vst[v]){
			if((r==1&&vst[u]==vst[v])||(r==0&&vst[v]+vst[u]==3)) continue;
			else{
				flag=1;
				return;
			}
		}
		if(!r) vst[v]=3-vst[u];
		else vst[v]=vst[u];
		dfs(v);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v,c;
		scanf("%d%d%d",&u,&v,&c);
		adj[u].pb(pii(v,c));
		adj[v].pb(pii(u,c));
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(!vst[i]){
			cnt++;
			vst[i]=1;
			dfs(i);
			if(flag){
				puts("0");
				return 0;
			}
		}
	}
	printf("%d\n",power(2,cnt-1,mod));
    return 0;
}