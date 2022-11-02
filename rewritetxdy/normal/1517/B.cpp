#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t,n,m,c[110][110],ans[110][110],a[11000];
map<int,int>vis;

int main()
{
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		int k = 0,cnt = 0;
		for(int i=1;i <= n;i++) for(int j=1;j <= m;j++) scanf("%d",&c[i][j]) , a[++k] = c[i][j];
		sort(a+1,a+1+k);
		for(int i=1;i <= m;i++) vis[a[i]]++;
		for(int i=1;i <= n;i++){
			for(int j=1;j <= m;j++){
				if(vis[c[i][j]]){
					vis[c[i][j]]--;
					ans[i][++cnt] = c[i][j];
					c[i][j] = -1;
				}
			}
		}
		for(int i=1;i <= n;i++) for(int j=1;j <= m;j++){
			int x = 1;
			if(c[i][j] > 0) {
				while(ans[i][x]) x++;
				ans[i][x++] = c[i][j];
			}
		}
		for(int i=1;i <= n;i++){
			for(int j=1;j <= m;j++) printf("%d ",ans[i][j]);
			puts("");
		}
		for(int i=1;i <= n;i++) for(int j=1;j <= m;j++) ans[i][j] = 0;
	}
}