#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int Maxn=1e5+19;
char s[Maxn];
int z[Maxn],y[Maxn],x[Maxn],n,L,R;

int main()
{
	scanf("%s",s+1);n=strlen(s+1);
	for (int i=1;i<=n;i++) 
		z[i]=z[i-1]+(s[i]=='z'),
		y[i]=y[i-1]+(s[i]=='y'),
		x[i]=x[i-1]+(s[i]=='x');
	scanf("%d",&n);
	while (n--)
	{
		scanf("%d%d",&L,&R);
		if (R-L<2) {puts("YES");continue;}
		int Max=max(z[R]-z[L-1],max(y[R]-y[L-1],x[R]-x[L-1]));
		int Min=min(z[R]-z[L-1],min(y[R]-y[L-1],x[R]-x[L-1]));
		puts(Max-Min<2?"YES":"NO");
	}
}