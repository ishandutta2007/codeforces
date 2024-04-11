#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define P 1000000007
#define N 1000010
char s[N];int p[N],a[N],n,S=0;
inline int hh(int x,int y)
{
	return a[y]-a[x-1]*p[y-x+1];
}
int ff(int x)
{
	int L=1,R=n-x;
	while(L<=R)
	{
		int M=(L+R)/2;
		if(hh(1,M)==hh(x,x+M-1))L=M+1;else R=M-1;
	}
	return R;
}
int main()
{
	scanf("%s",s+1);n=strlen(s+1);
	p[0]=1;for(int i=1;i<n+5;i++)p[i]=p[i-1]*P;
	for(int i=1;i<=n;i++)a[i]=a[i-1]*P+s[i];
	for(int i=2;i<=n;i++)S=max(S,ff(i));
	for(int i=S;i>=1;i--)if(hh(1,i)==hh(n-i+1,n))
		{for(int j=1;j<=i;j++)putchar(s[j]);puts("");return 0;}
	puts("Just a legend");
	return 0;
}