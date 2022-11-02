#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int t,n,c[233],vis[233];

int main()
{
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int cnt = 0;
		memset(vis,0,sizeof(vis));
		for(int i=1;i <= n;i++) scanf("%d",&c[i]);
		for(int i=1;i <= n;i++) for(int j=i+1;j <= n;j++)
			if(!vis[c[j]-c[i]]) vis[c[j]-c[i]] = 1 , cnt++;
		printf("%d\n",cnt);
	}
	
}