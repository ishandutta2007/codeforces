#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<queue>
#include<stack>
#define pb push_back
#define mp make_pair
#define mod 1000000007
using namespace std;

int n,x[5005],y[5005],dis[5005][5005];
vector<int> f[5005];
int col[5005],mid;
inline int cabs(int x){
	if(x>0) return x; else return -x;
}
bool vis[10005],isok=true;;
inline bool dfs(int x,int c){
	vis[x]=true;
	col[x]=c;
	for(int i=1;i<=n;i++)
		if(dis[x][i]>mid){
			if(!vis[i]) {if(!dfs(i,c^1)) return false; }
			else if(col[i]==col[x]) {isok=false;return false;}
		}
	return true;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&x[i],&y[i]);
		col[i]=-1;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			int t=cabs(x[i]-x[j])+cabs(y[i]-y[j]);
			dis[i][j]=t;
		}
	int p=0;
	int l=0,r=10001;
	while(l<r){
		mid=(l+r)>>1;
		isok=true;
		for(int i=1;i<=n;i++) col[i]=-1,vis[i]=false;
		for(int i=1;i<=n;i++){
			if(!vis[i]) dfs(i,0);
			if(!isok) break;
		}
		if(isok) r=mid; else l=mid+1;
	}
	int tot=0;
	mid=r; 
	isok=true;
	for(int i=1;i<=n;i++) col[i]=-1,vis[i]=false;
	for(int i=1;i<=n;i++){
			if(!vis[i]) {dfs(i,0);tot++;}
			if(!isok) break;
	}
	//cout<<isok<<endl;
	int ans=1;
	for(int i=1;i<=tot;i++) ans=(ans*2)%mod;
	printf("%d %d\n",r,ans);
	return 0;
}