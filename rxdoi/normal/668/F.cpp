#include<cstdio>
#include<map>
using namespace std;
const int N=10010,P=1e9+7;
int i,j,k,n,m,ch,t,ans;
int a[N][6];
map <int,int> f[N];
void R(int &x)
{
	x=0;ch=getchar();
	while (ch<'0' || '9'<ch) ch=getchar();
	while ('0'<=ch && ch<='9') x=x*10+ch-'0',ch=getchar();
}
int ksm(int x,int y)
{
	int z=1;
	for (;y;y>>=1,x=1ll*x*x%P) if (y&1) z=1ll*z*x%P;
	return z;
}
int main()
{
	R(n);R(m);
	for (i=2;i<=m;i++)
		for (j=1;j<i;j++)
		{
			a[i][++a[i][0]]=j;
			f[i][j]=f[j][i]=P-1;
			f[i][i]++;
			f[j][j]++;
		}
	for (i=m+1;i<=n;i++)
	{
		a[i][0]=m;
		for (j=1;j<=m;j++)
		{
			R(a[i][j]);
			f[i][a[i][j]]=f[a[i][j]][i]=P-1;
			f[i][i]++;
			f[a[i][j]][a[i][j]]++;
		}
	}
	ans=1;
	for (i=n;i>1;i--)
	{
		if (!f[i][i]){
			puts("FUCK");
			exit(0);
		}
		//assert(f[i][i]);
		t=ksm(f[i][i],P-2);
		for (j=1;j<=a[i][0];j++)
			for (k=1;k<=a[i][0];k++) (f[a[i][j]][a[i][k]]+=P-1ll*f[a[i][j]][i]*f[i][a[i][k]]%P*t%P)%=P;
		ans=(1ll*ans*f[i][i])%P;
	}
	printf("%d\n",ans);
}