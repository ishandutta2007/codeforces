#include<cstdio>
#define MN 2000
char a[MN+5],b[MN+5],c[MN+5];
int n,u[26],t[MN+5];
void solve(int x)
{
	printf("%d\n",x);
	for(int i=1;i<=n;++i)c[i]=a[i];
	for(int i=1;i<=x;++i)a[i]=c[n-i+1];
	for(int i=x;++i<=n;)a[i]=c[i-x];
}
int main()
{
	int i,j,k;
	scanf("%d%s%s",&n,a+1,b+1);
	for(i=1;i<=n;++i)++u[a[i]-'a'],--u[b[i]-'a'];
	for(i=0;i<26;++i)if(u[i])return 0*puts("-1");
	printf("%d\n",3*n);
	for(i=n,j=1;i>0;i-=2)t[i]=j++;
	for(i=1-i;i<=n;i+=2)t[i]=j++;
	for(i=1,j=n;i<=n;++i)for(k=1;k<=j;++k)if(a[k]==b[t[i]]){solve(n-k);solve(1);solve(--j);break;}
}