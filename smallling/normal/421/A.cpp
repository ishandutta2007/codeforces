#include<cstdio>

using namespace std;

int n,an,bn,a[101],b[101],o;

int main()
{
	scanf("%d%d%d",&n,&an,&bn);
	for(int i=1;i<=an;i++)
		scanf("%d",&o),a[o]=1;
	for(int i=1;i<=bn;i++)
		scanf("%d",&o),b[o]=1;
	for(int i=1;i<=n;i++)
		if(a[i])printf("1 ");
		else if(b[i])printf("2 ");
}