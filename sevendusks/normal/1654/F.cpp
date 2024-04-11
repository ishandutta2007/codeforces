/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
const int N=(1<<18)+100;
int n,w;
char s[N];
vector <int> rk[N];
struct node
{
	int a,b,wh,id;
}sh[N];
bool operator <(node a,node b)
{
	if (a.a!=b.a) return a.a<b.a;
	return a.b<b.b;
}
bool operator ==(node a,node b){return a.a==b.a&&a.b==b.b;}
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
signed main()
{
	n=read();
	scanf("%s",s);
	for (int i=0;i<(1<<n);i++) rk[i].resize(1);
	for (int i=0;i<(1<<n);i++) sh[++w]=(node){s[i]-'a',0,i,0};
	sort(sh+1,sh+1+w);
	for (int i=1;i<=w;)
	{
		int j=i;
		while (j<=w&&sh[i]==sh[j]) j++;
		for (int k=i;k<j;k++) rk[sh[k].wh][sh[k].id]=i;
		i=j;
	}
	for (int i=1;i<=n;i++)
	{
		int d=(1<<i);w=0;
		for (int j=0;j<(1<<n);j+=d)
		{
			int a=j,b=j+(1<<(i-1));
			for (int k=0;k<(1<<(i-1));k++)
			{
				sh[++w]=(node){rk[a][k],rk[b][k],a,k};
				sh[++w]=(node){rk[b][k],rk[a][k],a,k|(1<<(i-1))};
			}
			rk[a].resize(1<<i);
		}
		sort(sh+1,sh+1+w);
		for (int j=1;j<=w;)
		{
			int k=j;
			while (k<=w&&sh[j]==sh[k]) k++;
			for (int p=j;p<k;p++) rk[sh[p].wh][sh[p].id]=j;
			j=k;
		}
	}
	int j=find(rk[0].begin(),rk[0].end(),1)-rk[0].begin();
	for (int i=0;i<(1<<n);i++) printf("%c",s[i^j]);
	printf("\n");
}