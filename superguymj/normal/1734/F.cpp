#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
typedef long long LL;
LL n,m,f[100][2][2][2][2],ans;
int a[100],b[100];
//f[100][0/1][0/1][0/1][0/1]
// 

void inc(LL &x,LL y)
{
	x+=y;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&m),--m;
		rep(i,1,61) a[i]=(bool)(m&(1ll<<i-1));
		rep(i,1,61) b[i]=(bool)(n&(1ll<<i-1));
		memset(f,0,sizeof(f)),ans=0;
		f[0][0][0][0][0]=1;
		rep(i,0,63) rep(j,0,1) rep(k,0,1) rep(t,0,1) rep(c,0,1)
			if(f[i][j][k][t][c])
			{
				LL tmp=f[i][j][k][t][c];
				rep(x,0,1)
				{
					int y=x^b[i+1]^c;
					int _c=(x+b[i+1]+c)>1;
					int _t=(x>a[i+1]?1:(x==a[i+1]?t:0));
					int _j=j^x;
					int _k=k^y;
					inc(f[i+1][_j][_k][_t][_c],tmp);
				}
			}
		rep(i,0,1) inc(ans,f[64][i][i^1][0][0]);
		printf("%lld\n",ans); 
	}
	return 0;
}