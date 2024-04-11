#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 1000000
char s[MN+5];
int n,ans,l[MN+5],r[MN+5],u[MN+5];
queue<int> q,qq;
int gf(int*f,int k){return f[k]!=k?f[k]=gf(f,f[k]):k;}
bool ok(int x)
{
	int L=gf(l,x-1),R=gf(r,x+1);
	return (L&&s[L]!=s[x])||(R<=n&&s[R]!=s[x]);
}
int main()
{
	scanf("%s",s+1);n=strlen(s+1);
	for(int i=1;i<=n+1;++i)l[i]=r[i]=i;
	for(int i=1;i<=n;++i)if(ok(i))u[i]=1,q.push(i);
	while(!q.empty())
	{
		++ans;
		while(!q.empty())
		{
			int x=q.front();q.pop();
			l[x]=x-1;r[x]=x+1;qq.push(x);
		}
		while(!qq.empty())
		{
			int x=qq.front(),y;qq.pop();
			y=gf(l,x);if(y&&!u[y]&&ok(y))u[y]=1,q.push(y);
			y=gf(r,x);if(y<=n&&!u[y]&&ok(y))u[y]=1,q.push(y);
		}
	}
	printf("%d",ans);
}