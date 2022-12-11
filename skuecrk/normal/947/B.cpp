#include<cstdio>
#include<queue>
#define ll long long
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 100000
int v[MN+5];ll d,s;
priority_queue<ll> pq;
int main()
{
	int n=read(),i,t;
	for(i=1;i<=n;++i)v[i]=read();
	for(i=1;i<=n;++i)
	{
		t=read();s=0;
		pq.push(-v[i]-d);
		while(pq.size()&&-pq.top()-d<=t)s+=-pq.top()-d,pq.pop();
		s+=1LL*t*pq.size();d+=t;
		printf("%I64d ",s);
	}
}