#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,n2,m,i,j,k;
unsigned int f[100005];
char s[100005];

int main()
{
	scanf("%d",&n);n2=n>>1;
	if(n&1){printf("0\n");return 0;}
	scanf("%s",s+1);
	for(i=1;i<=n;++i)if(s[i]=='?')++m;
	if(m<n/2){printf("0\n");return 0;}
	f[0]=1;
	for(i=1;i<=n;++i)
	if(s[i]=='?')
	for(j=i>>1;j>=i-n2&&j;--j)
	f[j]+=f[j-1];
	for(i=n2-n+m;i;--i)f[n2]*=25;
	printf("%u\n",f[n2]);
}