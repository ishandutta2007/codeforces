#include <iostream>
#include <string>
#include <cstring>
#include <string.h>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

vector <int> a[101000];
int n,m;
int prev[101000];
int used[101000];
int dp[101000];
int rtp=-1;

void dfs(int x){
	if (rtp != -1)
		return ;

	used[x] = 1;
	for (int i = 0; i < (int)a[x].size() && rtp == -1; i ++)
	{
		if (used[a[x][i]] == 2) continue;
		if (used[a[x][i]] == 1) {rtp = a[x][i]; prev[a[x][i]] = x; return ;}
		if (used[a[x][i]] == 0) prev[a[x][i]] = x, dfs(a[x][i]);
	}
	used[x] = 2;
}

int find_cycle(){
	prev[1]=-1;
	dfs(1);
	if (rtp==-1) return -1; else
	{
		for (int i = 1; i <= n; i ++)
			used[i] = 0;
		int v = rtp;
		int res = 0;
		while (!used[v])
		{
			used[v] = true;
			v = prev[v];
			res ++;
		}
		return res;
	}
}

int tt;
int okk=1;

void dfs2(int x,int p){
	if (!okk) return;
	if (dp[x]==p) return;
	if (dp[x]==-1) dp[x]=p; else
		if (dp[x]!=p){
			okk=0;
			return;
		}
	for (int i=0; i<(int)(a[x].size()); i++){
		if (p+1==tt) dfs2(a[x][i],0); else
			dfs2(a[x][i],p+1);
	}
}

int isGood(int t){
	okk=1;
	memset(used,0,sizeof(used));
	memset(dp,-1,sizeof(dp));
	tt=t;
	dfs2(1,0);
	return okk;
}

void print(int t){
	memset(used,0,sizeof(used));
	memset(dp,-1,sizeof(dp));
	okk=1;
	tt=t;
	dfs2(1,0);
	printf("%d\n",t);
	int rs=0;
	for (int i=1; i<=n; i++)
		if (dp[i]==0) rs++;
	printf("%d\n",rs);
	for (int i=1; i<=n; i++)
		if (dp[i]==0) printf("%d ",i);
	printf("\n");
}

int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	scanf("%d%d",&n,&m);

	for (int i=0; i<m; i++){
		int x,y;
		scanf("%d%d",&x,&y);
		a[x].push_back(y);
	}

	int p=find_cycle();
	if (p==-1){
		print(1);
		return 0;
	}
	int res=1;

	for (int i=p; i>=1; i--)
		if (p%i==0)
			if (isGood(i)){ 
				print(i);
				return 0;
			}

	return 0;
}