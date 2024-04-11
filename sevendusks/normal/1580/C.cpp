/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
const int N=2*1e5+100,M=200;
int n,m,x[N],y[N],t[M+10][M+10],last[N];
int sum[N];
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
void change(int d,int nd,int id,int v)
{
	int s=x[id]+y[id];
	if (s<M)
	{
		int pos=(d+x[id])%s;
		for (int i=1;i<=y[id];i++)
		{
			t[s][pos]+=v;pos++;
			if (pos==s) pos=0;
		}
		return;
	}
	for (int i=d;i<=m;i+=s)
	{
		int l=i+x[id],r=min(i+x[id]+y[id],m+1);
		if (l<=r&&r>=nd)
		{
			if (nd<=r&&nd>=l) l=nd;
			sum[l]+=v;sum[r]-=v;
		}
	}
}
signed main()
{
	n=read();m=read();
	for (int i=1;i<=n;i++) x[i]=read(),y[i]=read();
	for (int i=1;i<=m;i++)
	{
		int op=read(),id=read(),ans=0;
		if (op==1)
		{
			last[id]=i;
			change(i,i,id,1);
		}
		else change(last[id],i,id,-1);
		// int lim=min(M-1,i);
		// for (int l=1,r;l<=lim;l=r+1)
		// {
		// 	r=i/(i/l);r=min(r,M-1);
		// 	int now=i/l;
		// 	for (int j=l;j<=r;j++) ans+=t[j][i-j*now];
		// }
		for (int j=1;j<M;j++) ans+=t[j][i%j];
		sum[i]+=sum[i-1];
		ans+=sum[i];
		printf("%d\n",ans);
	}
}