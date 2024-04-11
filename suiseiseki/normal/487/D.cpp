#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn=100100;
int n,m,q;
int kuai,kn;
char str[maxn][12];
int dp[maxn][12];
int dfs(int k,int x,int y){
	if(dp[x][y]){
		return dp[x][y];
	}
	if(str[x][y]=='^'){
		int nx=x-1,ny=y;
		if(nx<1+(k-1)*kuai){
			dp[x][y]=nx*(m+2)+ny;
		}
		else{
			dp[x][y]=dfs(k,nx,ny);
		}
	}
	else if(str[x][y]=='>'){
		int nx=x,ny=y+1;
		if(ny==m+1){
			dp[x][y]=nx*(m+2)+ny;
		}
		else if(str[nx][ny]=='<'){
			dp[x][y]=-1;
			dp[nx][ny]=-1;
		}
		else{
			dp[x][y]=dfs(k,nx,ny);
		}
	}
	else if(str[x][y]=='<'){
		int nx=x,ny=y-1;
		if(ny==0){
			dp[x][y]=nx*(m+2)+ny;
		}
		else if(str[nx][ny]=='>'){
			dp[x][y]=-1;
			dp[nx][ny]=-1;
		}
		else{
			dp[x][y]=dfs(k,nx,ny);
		}
	}
	return dp[x][y];
}
void getPOS(int x){
	for(int r=1+(x-1)*kuai;r<=min(x*kuai,n);r++){
		for(int c=1;c<=m;c++){
			dfs(x,r,c);
		}
	}
}
void changeIt(int k,int x,int y,char c){
	for(int r=1+(k-1)*kuai;r<=min(k*kuai,n);r++){
		for(int c=1;c<=m;c++){
			dp[r][c]=0;
		}
	}
	str[x][y]=c;
	getPOS(k);
}
int FindIt(int k,int x,int y){
	if(dp[x][y]==-1){
		return -1;
	}
	if(k==1){
		return dp[x][y];
	}
	int temp=dp[x][y];
	int nx=temp/(m+2);
	int ny=temp%(m+2);
	if(ny!=0&&ny!=m+1){
		return FindIt(k-1,nx,ny);
	}
	return temp;
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++){
		scanf("%s",str[i]+1);
	}
	kuai=int(sqrt(n))+1;
	kn=n/kuai;
	if(n%kuai){
		kn++;
	}
	for(int i=1;i<=kn;i++){
		getPOS(i);
	}
	char cmd[20],ch[10];
	int X,Y;
	while(q--){
		scanf("%s",cmd);
		if(cmd[0]=='A'){
			scanf("%d%d",&X,&Y);
			int nn=(X-1)/kuai+1;
			int ID=FindIt(nn,X,Y);
			if(ID>=0){
				printf("%d %d\n",ID/(m+2),ID%(m+2));
			}
			else{
				puts("-1 -1");
			}
		}
		else if(cmd[0]=='C'){
			scanf("%d%d%s",&X,&Y,ch);
			int nn=(X-1)/kuai+1;
			changeIt(nn,X,Y,ch[0]);
		}
	}
	return 0;
}