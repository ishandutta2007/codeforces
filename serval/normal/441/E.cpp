#include <cstdio>
using namespace std;
int x,k,l,b,c,d;
double p,ans;
double f[205][256][2][255];
int main()
{
	scanf("%d%d%lf",&x,&k,&p);
	p=p/100.0;
	l=x&255;
	x>>=8;
	b=x&1;
	if (x>0)
		c=1;
	x>>=1;
	while (x)
	{
		if ((x&1)==b)
			c++;
		else
			break;
		x>>=1;
	}
	f[0][l][b][c]=1.0;
	for (x=0;x<k;x++)
		for (l=0;l<256;l++)
			for (b=0;b<=1;b++)
				for (c=0;c<=250;c++)
					if (f[x][l][b][c]>0)
					{
						if ((l>>7)==b)
							f[x+1][(l<<1)&255][l>>7][c==0?(l>=128):c+1]+=f[x][l][b][c]*p;
						else
							f[x+1][(l<<1)&255][l>>7][c==0?(l>=128):1]+=f[x][l][b][c]*p;
						if (l+1<256)
							f[x+1][l+1][b][c]+=f[x][l][b][c]*(1-p);
						else
							if (b==1)
								f[x+1][0][0][c]+=f[x][l][b][c]*(1-p);
							else
								f[x+1][0][1][1]+=f[x][l][b][c]*(1-p);
					}
	for (l=0;l<256;l++)
		for (b=0;b<=1;b++)
			for (c=0;c<=250;c++)
				if (f[k][l][b][c]>0)
				{
					x=l;
					d=0;
					while (x)
					{
						if (x&1)
							break;
						d++;
						x>>=1;
					}
					if (b==0&&l==0&&c>0)
						d=c+8;
					if (b==1&&l==0&&c>0)
						d=8;
					ans+=f[k][l][b][c]*d;
				}
	printf("%.13lf\n",ans);
	return 0;
}