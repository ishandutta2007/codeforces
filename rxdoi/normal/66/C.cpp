#include<map>
#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

const int N=10000+19;
struct Edge {int y,nxt;} E[N*2];
int Last[N],vis[N],S2[N],S[N],cnt,tot,pre,M1,M2;
map<string,int> M;
string s;

void Add_Edge(int x,int y)
{
	E[cnt]=(Edge){y,Last[x]};Last[x]=cnt++;
}

void DFS(int x,int Fa)
{
	S[x]=S2[x]^1;vis[x]=1;
	for (int i=Last[x];~i;i=E[i].nxt)
		if (E[i].y!=Fa)
		{
			DFS(E[i].y,x);
			S[x]+=S[E[i].y],S2[x]+=S2[E[i].y];
		}
	M1=max(M1,S[x]),M2=max(M2,S2[x]);
}

int main()
{
	memset(Last,-1,sizeof(Last));
	while (cin>>s)
	{
		pre=-1;
		For(i,0,s.length()+1)
			if (i==s.length()||s[i]=='\\'&&i!=2)
			{
				if (!M.count(s.substr(0,i)))
				{
					M[s.substr(0,i)]=++tot;
					if (~pre) Add_Edge(pre,tot);
				}
				pre=M[s.substr(0,i)];
			}
		S2[pre]=1;
	}
	For(i,1,tot+1) if (!vis[i]) DFS(i,-1);
	printf("%d %d\n",M1-1,M2);
}