#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 5000
int a[MN+5][MN+5],f[MN+5][MN+5];
int main()
{
	int n=read(),i,j;
	for(i=1;i<=n;++i)a[0][i]=read();
	for(i=1;i<=n;++i)for(j=1;j<=n;++j)a[i][j]=a[i-1][j]^a[i-1][j+1];
	for(j=0;j<n;++j)for(i=1;i+j<=n;++i)f[i][i+j]=max(max(f[i][i+j-1],f[i+1][i+j]),a[j][i]);
	for(n=read();n--;)i=read(),j=read(),printf("%d\n",f[i][j]);
}