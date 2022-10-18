/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
const int N=1e5+100;
int TT,n,id[50][800],cnt,ok[50][800];
vector <pair<int,int> > cir[50];
vector <int> s[50];
char ch[20]; 
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
struct dsu
{
	int fa[N];
	void init(int n)
	{
		for (int i=1;i<=n;i++) fa[i]=i;
	}
	int find(int x){return fa[x]==x?fa[x]:fa[x]=find(fa[x]);}
	void merge(int a,int b)
	{
		a=find(a);b=find(b);
		if (a==b) return;
		fa[a]=b;
	}
	bool check(int a,int b){return find(a)==find(b);}
}T;
void prework()
{
	id[0][0]=++cnt;
	for (int i=1;i<=41;i++)
	{
		for (int j=0;j<720;j++) id[i][j]=++cnt;
	}
}
signed main()
{
	prework();
	TT=read();
	while (TT--)
	{
		n=read();
		T.init(cnt);
		for (int i=1;i<=40;i++) cir[i].clear(),s[i].clear();
		for (int i=1;i<=n;i++)
		{
			scanf("%s",ch);
			if (ch[0]=='C')
			{
				int x=read()*2,L=read()*2,R=read()*2;
				cir[x].emplace_back(L,R);
			}
			else
			{
				int x=read()*2,y=read()*2,th=read()*2;
				for (int i=x;i<=y;i++) s[i].push_back(th);
			}
		}
		for (int i=1;i<=41;i++)
		{
			memset(ok[i],0,sizeof(ok[i]));
			for (auto [l,r]:cir[i])
			{
				if (l<=r) ok[i][l]++,ok[i][r+1]--;
				else ok[i][l]++,ok[i][0]++,ok[i][r+1]--;
			}
			for (int x:s[i]) ok[i][x]++,ok[i][x+1]--;
			for (int j=1;j<720;j++) ok[i][j]+=ok[i][j-1];
			for (int j=0;j<720;j++) ok[i][j]=(ok[i][j]==0);
			for (int j=0;j<719;j++) if (ok[i][j]&&ok[i][j+1]) T.merge(id[i][j],id[i][j+1]);
			if (ok[i][719]&&ok[i][0]) T.merge(id[i][719],id[i][0]);
		}
		for (int j=0;j<720;j++) if (ok[1][j]) T.merge(id[0][0],id[1][j]);
		for (int i=2;i<=41;i++)
		{
			for (int j=0;j<720;j++) if (ok[i][j]&&ok[i-1][j]) T.merge(id[i][j],id[i-1][j]);
		}
		bool bl=0;
		for (int j=0;j<720;j++) if (T.check(id[0][0],id[41][j])) bl=1;
		if (bl) puts("YES");
		else puts("NO");
	}
}