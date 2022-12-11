#include<cstdio>
#include<cctype>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

const int N=100+3;
double f[N][N][N],a,b,c;
int r,s,p;

int main()
{
	scanf("%d%d%d",&r,&s,&p);
	f[r][s][p]=1.0;
	for (int i=r;i>=0;i--)
		for (int j=s;j>=0;j--)
			for (int k=p;k>=0;k--)
			{
				int S=i+j+k,P=S*(S-1)/2-i*(i-1)/2-j*(j-1)/2-k*(k-1)/2;
				if (P)
				{
					if (i) f[i-1][j][k]+=f[i][j][k]*i*k/(1.0*P);
					if (j) f[i][j-1][k]+=f[i][j][k]*i*j/(1.0*P);
					if (k) f[i][j][k-1]+=f[i][j][k]*j*k/(1.0*P);
				}
				if (i&&!j&&!k) a+=f[i][j][k];
				if (!i&&j&&!k) b+=f[i][j][k];
				if (!i&&!j&&k) c+=f[i][j][k];
			}
	printf("%.12lf %.12lf %.12lf\n",a,b,c);
}