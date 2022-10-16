#include <cstdio>
#include <algorithm>

using namespace std;

const int N=1e5+5;

int T;

int n;
char s[2][N];
int f[N];
int mex(int a,int b)
{
	if (a!=0&&b!=0)
		return 0;
	if (a==0||b==0)
		if (a!=1&&b!=1)
			return 1;
	return 2;
}
int mex4(int a,int b,int c,int d)
{
	if (a!=0&&b!=0&&c!=0&&d!=0)
		return 0;
	if (a==0||b==0||c==0||d==0)
		if (a!=1&&b!=1&&c!=1&&d!=1)
			return 1;
	return 2;
}
int cal1(int i)
{
	return mex(s[0][i]-'0',s[1][i]-'0');
}
int cal2(int i)
{
	return mex4(s[0][i]-'0',s[1][i]-'0',s[0][i-1]-'0',s[1][i-1]-'0');
}
void solve()
{
	scanf("%d",&n);
	scanf("%s",s[0]+1);
	scanf("%s",s[1]+1);
	for (int i=1;i<=n;i++)
	{
		f[i]=0;
		f[i]=max(f[i],f[i-1]+cal1(i));
		if (i>=2)
			f[i]=max(f[i],f[i-2]+cal2(i));
	}
	printf("%d\n",f[n]);
}

int main()
{
	scanf("%d",&T);
	while (T--)
		solve();
	return 0;
}