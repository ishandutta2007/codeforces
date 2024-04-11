#include<cstdio>
#include<cstring>
using namespace std;
const int jsb=1000000007;
inline void plus(int &x,int y){x+=y;if(x>=jsb)x-=jsb;}
inline void pmul(int &x,int y,int z){y=y*1ll*z%jsb;x+=y;if(x>=jsb)x-=jsb;}
struct ww{int a[105][105];};
int N;
inline ww operator *(const ww &a,const ww &b){
	ww c;memset(c.a,0,sizeof c.a);
	for(int k=0;k<=N;k++)
	for(int i=0;i<=N;i++)
	for(int j=0;j<=N;j++)
	pmul(c.a[i][j],a.a[i][k],b.a[k][j]);
	return c;
}
long long n;int k;
int C[55][55];
int main(){
	scanf("%I64d%d",&n,&k);N=2*k+2;
	for(int i=0;i<=k;i++){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++)plus(C[i][j],C[i-1][j]),plus(C[i][j],C[i-1][j-1]);
	}
	ww a,c;memset(a.a,0,sizeof a.a);memset(c.a,0,sizeof c.a);
	for(int i=0;i<=N;i++)c.a[i][i]=1;
	for(int i=0;i<=k;i++)for(int j=0;j<=i;j++)a.a[j][i]=a.a[j+k+1][i]=C[i][j];
	for(int i=k+1;i<=k+1+k;i++)for(int j=0;j<=i-k-1;j++)a.a[j][i]=C[i-k-1][j];
	a.a[k][2*k+2]=a.a[2*k+2][2*k+2]=1;
	for(;n;n>>=1,a=a*a)if(n&1)c=c*a;
	ww u;memset(u.a,0,sizeof u.a);
	for(int i=0;i<=2*k+1;i++)u.a[0][i]=1;
	u=u*c;
	printf("%d\n",u.a[0][N]);
	return 0;
}