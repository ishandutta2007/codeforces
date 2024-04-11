#include<cstdio>
#include<algorithm>

using namespace std;

int i,j,k,l,m,n,o,p,a[101],now,ans,b[101];

int gcd(int a,int b)
{
	if(a%b==0)return b;
	return gcd(b,a%b);
}

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		int bo=1;
		for(j=1;j<i;j++)
		if(i!=j)if(a[i]==a[j]){bo=0;break;}
		if(bo)b[++o]=a[i];
	}
	now=b[1];
	for(i=2;i<=o;i++)
	now=gcd(now,b[i]);
	ans=b[o]/now-o;
	if(ans&1)printf("Alice");
	else printf("Bob");
}