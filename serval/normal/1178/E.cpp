#include <cstdio>
using namespace std;
const int N=1e6+5;
int n,cntl,cntr;
char s[N];
char ansl[N],ansr[N];
char fi(char a,char b,char c,char d)
{
	if (a==b||a==c||a==d) return a;
	if (b==c||b==d) return b;
	if (c==d) return c;
}
int main()
{
	scanf("%s",s+1);
	for (n=1;s[n+1];n++);
	for (int l=1,r=n;l<=r;l+=2,r-=2)
	{
		if (l+2<r)
		{
			cntl++;
			cntr++;
			ansl[cntl]=fi(s[l],s[l+1],s[r],s[r-1]);
			ansr[cntr]=ansl[cntl];
		}
		else
		{
			cntl++;
			if (l==r)
				ansl[cntl]=s[l];
			else
				ansl[cntl]=fi(s[l],s[l+1],s[r],s[r-1]);
		}
	}
	for (int i=1;i<=cntl;i++)
		printf("%c",ansl[i]);
	for (int i=cntr;i;i--)
		printf("%c",ansr[i]);
	printf("\n");
	return 0;
}