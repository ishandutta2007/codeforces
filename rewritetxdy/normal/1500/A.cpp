#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 5e6+10;

int n,m = 2500000,c[N],cnt[N],x,y,ans[N],top;
struct osc{
	int x,y;
	osc(int xx=0,int yy=0){
		x = xx , y = yy;
	}
}vis[N];

int main()
{
	scanf("%d",&n);
	for(int i=1;i <= n;i++) scanf("%d",&c[i]), cnt[c[i]]++;
	for(int i=1;i <= m;i++){
		if(cnt[i] >= 4){
			for(int j=1;j <= n;j++) if(c[j] == i) ans[++top] = j;
			puts("YES");
			printf("%d %d %d %d\n",ans[1],ans[3],ans[2],ans[4]);
			return 0;
		}
		else if(cnt[i] >= 2) 
			!x ? (x = i) : (y = i);
	}
	if(x && y){
		for(int j=1;j <= n;j++) if(c[j] == x && top < 2) ans[++top] = j;
		for(int j=1;j <= n;j++) if(c[j] == y && top < 4) ans[++top] = j;
		puts("YES");
		printf("%d %d %d %d\n",ans[1],ans[3],ans[2],ans[4]);
		return 0;
	}
	if(x){
		for(int j=1;j <= n;j++) if(c[j] == x && top < 2) ans[++top] = j;
		for(int i=1;i <= n;i++) if(c[i] == x) c[i] = -1;
		c[ans[1]] = x;
		vis[x<<1] = osc(ans[1],ans[2]);
	}
	for(int i=1;i <= n;i++) for(int j=i+1;j <= n;j++) if(c[i] > 0 && c[j] > 0){
		if(vis[c[i]+c[j]].x){
			puts("YES");
			printf("%d %d %d %d\n",vis[c[i]+c[j]].x,vis[c[i]+c[j]].y,i,j);
			return 0;
		}
		vis[c[i]+c[j]] = osc(i,j);
	}
	puts("NO");
	return 0;
}