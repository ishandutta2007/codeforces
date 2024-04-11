#include<cstdio>
#include<vector>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 100000
int d[MN+5],s[MN+5];
int main()
{
	int n=read(),i,ans=1;
	for(i=2;i<=n;++i)++s[d[i]=d[read()]+1];
	for(i=1;i<n;++i)ans+=s[i]&1;
	printf("%d",ans);
}