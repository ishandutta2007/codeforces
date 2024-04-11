#include<cstdio>
#include<iostream>
#include<algorithm>
#include<map>
#include<string>
#include<queue>
#include<cstring>
using namespace std;

const int Maxn=100000+19;
typedef long long LL;
map<string,int> Map;
struct note 
{
	LL cnt,len;
	bool operator < (const note& B) const {return cnt<B.cnt||cnt==B.cnt&&len<B.len;}
} Dis[Maxn];
struct Edge {int y,nxt;} E[Maxn];
queue<int> Q;
int tot,n,m,cnt,Ecnt,Last[Maxn],inQ[Maxn];
string s[Maxn],a,b;
LL Cnt,Len;

inline void Link(int x,int y)
{
	E[Ecnt]=(Edge){y,Last[x]};Last[x]=Ecnt++;
}
inline int get_ID(string t,int x)
{
	int Len=t.length();
	for (int i=0;i<Len;i++) if (t[i]<'a') t[i]=t[i]+'a'-'A';
	if (!Map[t]) Map[t]=++tot;else return Map[t];
	if (x) return Map[t];
	int tmp=Map[t];
	for (int i=0;i<Len;i++) Dis[tmp].cnt+=(t[i]=='r');
	Dis[tmp].len=Len;
	return tmp;
}

int main()
{
	ios::sync_with_stdio(false);
	memset(Last,-1,sizeof(Last));
	cin>>n;
	for (int i=1;i<=n;i++) 
	{
		cin>>s[i];
		int x=get_ID(s[i],0);
		if (!inQ[x]) Q.push(x),inQ[x]=1;
	}
	cin>>m;
	for (int i=1;i<=m;i++) 
	{
		cin>>a>>b;
		int x=get_ID(a,0),y=get_ID(b,0);
		if (!inQ[x]) Q.push(x);
		if (!inQ[y]) Q.push(y);Link(y,x);
		inQ[x]=inQ[y]=1;
	}
	while (!Q.empty())
	{
		int x=Q.front();Q.pop();
		for (int i=Last[x];i!=-1;i=E[i].nxt) 
		{
			int y=E[i].y;
			if (Dis[x]<Dis[y]) 
			{
				Dis[y]=Dis[x];
				if (!inQ[y]) Q.push(y),inQ[y]=1;
			}
		}
		inQ[x]=0;
	}
	for (int i=1;i<=n;i++) 
	{
		int x=get_ID(s[i],1);
		Cnt+=Dis[x].cnt,Len+=Dis[x].len;
	}
	cout<<Cnt<<" "<<Len<<endl;
}