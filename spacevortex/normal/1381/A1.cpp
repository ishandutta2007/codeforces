#include<bits/stdc++.h>
using namespace std;
const int N=4e5+50;
int n,num;
char s[N];
int a[N],b[N],p[N];
void act(int len)
{
	int i;
	p[++num]=len;
	for(i=1;i<=len;i++) a[i]^=1;
	reverse(a+1,a+len+1);
}
void Solve()
{
	int i;
	scanf("%d",&n);
	scanf("%s",s+1);for(i=1;i<=n;i++) a[i]=s[i]-48;
	scanf("%s",s+1);for(i=1;i<=n;i++) b[i]=s[i]-48;
	num=0;
	for(i=n;i>=1;i--)
	{
		if(a[1]!=(b[i]^1)) act(1);
		act(i);
	}
	printf("%d ",num);
	for(i=1;i<=num;i++) printf("%d ",p[i]);
	putchar('\n');
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--) Solve();
}