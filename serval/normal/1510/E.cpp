#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const int N=18+2;
const int S=153+2;
const int XS=2754+2;
const int U=1;
const int R=2;

int n,n2;
double x,y;
int s,xs,ys;
bool f[N][N][S][XS];
char fr[N][N][S][XS];
int ds[N][N],dxs[N][N];
int pds[N][N],pdxs[N][N];
char ans[N*2];
int sf[N*2];

bool check()
{
	long double xx=0,yy=0,ss=0;
	int p=0;
	for (int i=1;i<=n;i++)
	{
		if (ans[i]==')')
			p--;
		sf[i]=p;
		if (ans[i]=='(')
			p++;
		ss+=sf[i];
		yy+=0.5*sf[i]+1.0/6+0.5*sf[i]*sf[i];
	}
	ss+=0.5*n;
	yy/=ss;
	if (abs(yy-y)<1e-7)
		return 1;
	return 0;
}

bool dfs(int ii,int jj,int ss,int xss,int d=2)
{
	if (d==n)
	{
		return check();
	}
	if (fr[ii][jj][ss][xss]&U)
	{
		ans[d]='(';
		if (dfs(ii-1,jj,ss-pds[ii][jj],xss-pdxs[ii][jj],d+1))
			return 1;
	}
	if (fr[ii][jj][ss][xss]&R)
	{
		ans[d]=')';
		if (dfs(ii,jj+1,ss-ds[ii][jj],xss-dxs[ii][jj],d+1))
			return 1;
	}
	return 0;
}

int main()
{
	scanf("%d",&n);
	scanf("%lf%lf",&x,&y);
	for (int i=1;i<=n;i+=2)
	{
		s++;
		xs+=i;
	}
	n2=n/2;
	for (int i=1;i<n2;i++)
	{
		ds[i][1]=1;
		dxs[i][1]=n2-i+1;
		for (int j=2;j<=n2-i;j++)
		{
			ds[i][j]=1;
			dxs[i][j]=dxs[i][j-1]+1;
		}
	}
	for (int i=1;i<n2;i++)
		for (int j=n2-i;j;j--)
		{
			pds[i][j]=pds[i][j+1]+ds[i][j];
			pdxs[i][j]=pdxs[i][j+1]+dxs[i][j];
		}
	f[1][n2][0][0]=1;
	for (int i=1;i<=n2;i++)
		for (int j=n2-i+2;j;j--)
			for (int ss=0;ss<S;ss++)
				for (int xss=0;xss<XS;xss++)
					if (f[i][j][ss][xss])
					{
						f[i+1][j][ss+pds[i+1][j]][xss+pdxs[i+1][j]]=1;
						fr[i+1][j][ss+pds[i+1][j]][xss+pdxs[i+1][j]]|=U;
						f[i][j-1][ss+ds[i][j-1]][xss+dxs[i][j-1]]=1;
						fr[i][j-1][ss+ds[i][j-1]][xss+dxs[i][j-1]]|=R;
					}
	for (int ts=0;ts<S;ts++)
	{
		int tss=ts*2+s;
		int xx=round(x*tss);
		if (abs(1.0*xx/tss-x)>1e-7)
			continue;
		xx-=xs;
		if (xx%2!=0||xx<0)
			continue;
		xx/=2;
		if (xx>=XS)
			continue;
		if (!f[n2][1][ts][xx])
			continue;
		int ii=n2,jj=1,ss=ts,xss=xx;
		ans[1]='(';
		ans[n]=')';
		if (dfs(ii,jj,ss,xss))
		{
			printf("%s\n",ans+1);
			break;
		}
		//printf("%d\n",f[n2][1][s][xs]);
	}
	return 0;
}