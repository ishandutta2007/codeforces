#include<bits/stdc++.h>
using namespace std;
#define nn 1010
char s[nn];
int a[nn],ans[nn][2];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n,m,x,y;cin>>n>>m>>x>>y;
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		for(int j=1;j<=m;j++) if(s[j]=='.') a[j]++;
	}
	for(int i=2;i<=m;i++) a[i]+=a[i-1];
	y=min(m,y);
	for(int i=1;i<=m;i++) for(int j=0;j<2;j++) ans[i][j]=1000010000;
	ans[x][0]=a[x];
	ans[x][1]=n*x-a[x];
	for(int i=x+1;i<=m;i++){
		for(int j=x;j<=y;j++) if(i>=j){
			ans[i][0]=min(ans[i][0],ans[i-j][1]+a[i]-a[i-j]);
			ans[i][1]=min(ans[i][1],ans[i-j][0]+n*j-(a[i]-a[i-j]));
		}
	}
	int W=min(ans[m][0],ans[m][1]);
	printf("%d",W);
	return 0;
}