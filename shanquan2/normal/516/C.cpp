#include<cstdio>
#include<algorithm>
#define inf (1LL<<60)
using namespace std;

struct nod{
	long long x,y,r;
}st1[200000][20],st2[200000][20];
long long b[200000],c[200000],d[200000],x[100000],h[100000];
nod max1(nod x,nod y){
	nod ans;
	ans.x=max(x.x,y.x);
	ans.r=(ans.x==x.x)?x.r:y.r;
	if(ans.x==x.x)ans.y=max(y.x,x.y);else ans.y=max(x.x,y.y);
	return ans;
}
long long getans(int x,int y){
	int j=0;
	while(x+(1<<j)<=y)j++;j--;
	nod tp1=st1[x][j],tp2=st2[x][j];
	x+=(1<<j);
	while(x<=y){
		if(x+(1<<j)<=y+1){
			tp1=max1(tp1,st1[x][j]);
			tp2=max1(tp2,st2[x][j]);
			x+=(1<<j);
		}
		j--;
	}
	if(tp1.r!=tp2.r)return tp1.x+tp2.x;
	return max(tp1.x+tp2.y,tp1.y+tp2.x);
}
int main(){
	int n,m;scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%I64d",&x[i]);
	d[0]=0;
	for(int i=1;i<n;i++)d[i]=d[i-1]+x[i-1];
	d[n]=d[n-1]+x[n-1];
	for(int i=n+1;i<n*2;i++)d[i]=d[i-1]+x[i-n-1];
	for(int i=0;i<n;i++)scanf("%I64d",&h[i]);
	for(int i=0;i<n*2;i++)
		c[i]=2*h[i%n]-d[i],
		b[i]=2*h[i%n]+d[i],
		st1[i][0].x=c[i],st1[i][0].y=-inf,st1[i][0].r=i,
		st2[i][0].x=b[i],st2[i][0].y=-inf,st2[i][0].r=i;
	for(int j=1;j<20;j++)
		for(int i=0;i<n*2;i++)
			if(i+(1<<(j-1))<n*2){
				st1[i][j]=max1(st1[i][j-1],st1[i+(1<<(j-1))][j-1]);
				st2[i][j]=max1(st2[i][j-1],st2[i+(1<<(j-1))][j-1]);
			}
			else{
				st1[i][j]=st1[i][j-1];
				st2[i][j]=st2[i][j-1];
			}
	for(int i=0;i<m;i++){
		int l,r;scanf("%d%d",&l,&r);l--,r--;
		if(l>r)r+=n;
		int x=r+1,y=l+n-1;
		long long ans=getans(x,y);
		printf("%I64d\n",ans);
	}
	return 0;
}