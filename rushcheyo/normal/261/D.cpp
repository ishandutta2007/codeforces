#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int T,n,m,t,b[N],dp[N];
bool vis[N];
int main() {
	scanf("%d%d%d%d",&T,&n,&m,&t);
	while (T--) {
		int dif=0;
		for (int i=0;i<n;i++) {
			scanf("%d",b+i);
			if (!vis[b[i]]) vis[b[i]]=true,dif++;
		}
		if (t>dif) printf("%d\n",dif);
		else {
			for (int i=1;i<=m;i++) dp[i]=0;
			for (int i=0;i<n*t;i++) {
				int c=b[i%n],v=dp[c-1]+1;
				for (int j=c;j<=m&&v>dp[j];j++) dp[j]=v;
			}
			printf("%d\n",dp[m]);
		}
		for (int i=0;i<n;i++) vis[b[i]]=false;
	}
}