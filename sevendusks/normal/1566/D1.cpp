/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
const int N=310;
int t,n,m;
struct node
{
	int v,id;
}sh[N];
bool cmp(node a,node b){return a.v<b.v||(a.v==b.v&&a.id>b.id);}
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
signed main()
{
	t=read();
	while (t--)
	{
		n=read();m=read();
		for (int i=1;i<=m;i++) sh[i]=(node){read(),i};
		sort(sh+1,sh+1+m,cmp);
		int ans=0;
		for (int i=1;i<=m;i++) for (int j=1;j<i;j++) if (sh[j].id<sh[i].id) ans++;
		printf("%d\n",ans);
	}
}