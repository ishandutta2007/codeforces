#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<functional>
#include<cmath>
#include<string>
#include<cstring>
#include<map>
#include<set>
#define logn 20;
using namespace std;

int n,c[200005],next[200005][22],ans[200005][22];
int dp[200005],p[200005],l[200005];

void change(int x,int y){
	while(x<=n){
		c[x]=max(c[x],y);
		x+=x&(-x);
	}
}
int get(int x){
	int ans=0;
	while(x>0){
		ans=max(ans,c[x]);
		x-=x&(-x);
	}
	return ans;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
		scanf("%d%d",&p[i],&l[i]);
	for(int i=n;i>=1;i--){
		dp[i]=max(p[i]+l[i],get(upper_bound(p+1,p+n+1,p[i]+l[i])-p-1));
		next[i][0]=upper_bound(p+1,p+n+1,dp[i])-p;
		ans[i][0]=max(0,p[next[i][0]]-dp[i]);
		change(i,dp[i]);
	}
	next[n+1][0]=n+1;
	for(int i=1;i<=20;i++){
		next[n+1][i]=n+1; 
		for(int j=n;j>=1;j--){
			next[j][i]=next[next[j][i-1]][i-1];
			ans[j][i]=ans[j][i-1]+ans[next[j][i-1]][i-1];
		}
	}
	int q;
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		int x,y,res=0;
		scanf("%d%d",&x,&y);
		for(int j=20;j>=0;j--)
		{
			if(next[x][j]<=y){
				res=res+ans[x][j];
				x=next[x][j];
			}
		}
		printf("%d\n",res);
	}
	return 0;
}