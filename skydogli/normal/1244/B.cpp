#include<bits/stdc++.h>
using namespace std;
/*void bfs(int x,int y){
	while(!Qx.empty())Qx.pop();
	while(!Qy.empty())Qy.pop();
	memset(vis,0,sizeof(vis));
	Qx.push(x);
	Qy.push(y);
	dis[x][y]=1;
	while(!Qx.empty()){
		int x=Qx.front(),y=Qy.front();
		ans=max(ans,vis[x][y]);
		if(x==1&&ch[y]=='1'&&!vis[0][y]){
			dis[0][y]=vis[x][y]+1;
			Qx.push(0);
			Qy.push(y);
		}
		if(!x&&ch[y]=='1'&&!vis[0][y]){
			
		}
	}
}*/
int T,n,vis[2][1005],ans;
char ch[1005];
/*void dfs(int x,int y){
	cout<<"HI "<<x<<" "<<y<<endl;
	ans=max(ans,vis[x][y]);
	if(ch[y]=='1'){
		if(!vis[x^1][y]){
			vis[x^1][y]=vis[x][y]+1;
			dfs(x^1,y);
			vis[x^1][y]=0;
		}
	}
	if(y>1&&!vis[x][y-1]){
		vis[x][y-1]=vis[x][y]+1;
		dfs(x,y-1);
		vis[x][y-1]=0;
	}
	if(y<n&&!vis[x][y+1]){
		vis[x][y+1]=vis[x][y]+1;
		dfs(x,y+1);
		vis[x][y+1]=0;
	}
}*/
int main(){
	scanf("%d",&T);
	while(T--){
		ans=0;
		scanf("%d",&n);
		scanf("%s",ch+1);
		ans=n;
		for(int i=1;i<=n;++i){
			if(ch[i]=='1')ans=max(max(ans,2*i),2*(n-i+1));
		}
		printf("%d\n",ans);
	}
	return 0;
}