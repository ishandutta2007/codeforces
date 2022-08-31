#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define res(i,n) for(int i=0;i<=n;++i)
using namespace std;
typedef long long ll;
const int N=2005,inf=1000000;
int a[N],b[N],c[10],d[10],n;
int dp[2][10][10][10][10];
void upd(int&x,int y){if(x>y)x=y;}
int main(){
	scanf("%d",&n);
	rep(i,n)scanf("%d%d",a+i,b+i);
	memset(dp,0x3f,sizeof dp);
	a[0]=1;
	dp[0][0][0][0][0]=0;
	int r=0;
	for(int i=0;i<n;++i){
		//printf("I:%d\n",i);
		r^=1;memset(dp[r],0x3f,sizeof dp[r]);
		for(int j=0;j<10000;++j){
		int tp=j;
		rep(k,4)c[k]=tp%10,tp/=10;
		tp=dp[r^1][c[1]][c[2]][c[3]][c[4]];
		if(tp>=inf)continue;
		//printf("%d %d %d %d %d\n",c[1],c[2],c[3],c[4],tp);
		int cur=0;
		rep(k,4)if(c[k])++cur;
		if(cur<4){
			rep(k,cur)d[k]=c[k];
			d[cur+1]=b[i+1];
			for(int k=cur+2;k<=4;++k)d[k]=0;
			sort(d+1,d+cur+1+1);
			dp[r][d[1]][d[2]][d[3]][d[4]]=tp+abs(a[i]-a[i+1]);
		}
		rep(k,cur)for(int p=k;p<=cur;++p){

			int top=0;
			rep(l,cur)if(l<k||p<l)d[++top]=c[l];
			d[++top]=b[i+1];
			for(int l=top+1;l<=4;++l)d[l]=0;
			if(top>1)sort(d+1,d+top+1);
			//if(i==3&&c[1]==4&&c[2]==0)printf("FUCK:%d %d %d %d\n",d[1],d[2],d[3],d[4]);
			//a[i]<a[i+1]?tp+abs(a[i]-c[k])+c[p]-c[k]+abs(a[i+1]-c[p]):tp+abs(a[i+1]-c[k])+c[p]-c[k]+abs(a[i]-c[p]));
			if(a[i]<a[i+1])upd(dp[r][d[1]][d[2]][d[3]][d[4]],tp+abs(a[i]-c[k])+c[p]-c[k]+abs(a[i+1]-c[p]));
			else upd(dp[r][d[1]][d[2]][d[3]][d[4]],tp+abs(a[i+1]-c[k])+c[p]-c[k]+abs(a[i]-c[p]));
		}
	}}

	int ans=inf;
	for(int j=0;j<10000;++j){
		int tp=j;
		rep(k,4)c[k]=tp%10,tp/=10;
		tp=dp[r][c[1]][c[2]][c[3]][c[4]];
		if(tp>=inf)continue;
		//printf("%d %d %d %d %d\n",c[1],c[2],c[3],c[4],tp);
		int cur=0;
		rep(k,4)if(c[k])++cur;
		ans=min(ans,tp+min(abs(a[n]-c[cur])+c[cur]-c[1],abs(a[n]-c[1])+c[cur]-c[1]));
	}
	printf("%d\n",ans+2*n);
	//system("pause");
	return 0;
}