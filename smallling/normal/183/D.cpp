#include<queue>
#include<cstdio>
#include<algorithm>

#define mp make_pair
#define fi first
#define se second

using namespace std;

priority_queue<pair<double,int> >a;
pair<double,int>now;
int n,m,p,cnt[3030];
double f[3030][2][330],g[3030][330],Ans,F[3030];

inline void read(int &x)
{
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			read(p);
			g[i][j]=p/1000.;
		}
	for(int i=1;i<=m;i++)
		f[0][0][i]=1.;
	for(int i=1;i<=n;i++)
		for(int k=1;k<=m;k++)
			f[i][0][k]+=f[i-1][0][k]*(1-g[i][k]);
	for(int i=1;i<=m;i++)F[i]=1-f[n][0][i],a.push(mp(F[i],i));
	for(int i=1;i<=n;i++)
	{
		Ans+=(a.top()).first;
		now=a.top();
		a.pop();
		cnt[now.se]++;
		int last=(cnt[now.se]-1)%2,New=cnt[now.se]%2;
		f[0][New][now.se]=0;
		for(int j=1;j<=n;j++)
			f[j][New][now.se]=f[j-1][New][now.se]*(1-g[j][now.se])+f[j-1][last][now.se]*g[j][now.se];
		F[now.se]-=f[n][New][now.se];
		a.push(mp(F[now.se],now.se));
	}
	printf("%.12lf\n",Ans);
}