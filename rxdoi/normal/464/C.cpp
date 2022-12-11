#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

const int Maxn=1e5+19,Mod=1e9+7;
typedef long long LL;
struct Edge {int y,nxt;} E[Maxn];
char s[Maxn],c[Maxn];
int Q,Last[Maxn],cnt,d[Maxn];
LL Ans,tn,tL,Len[19],to[19];

inline void Add_Edge(int x,int y)
{
	E[cnt]=(Edge){y,Last[x]};Last[x]=cnt++;
}

int main()
{
	memset(Last,-1,sizeof(Last));
	scanf("%s",c);
	scanf("%d",&Q);
	for (int i=1;i<=Q;i++)
	{
		scanf("%s",s);
		d[i]=s[0]-'0';
		int Len=strlen(s);
		for (int j=Len-1;j>=3;j--) Add_Edge(i,s[j]-'0');
	}
	for (int i=0;i<=9;i++) to[i]=i,Len[i]=10;
	for (int i=Q;i>=1;i--)
	{
		tL=1;tn=0;
		int x=d[i];
		for (int j=Last[i];j!=-1;j=E[j].nxt)
		{
			int y=E[j].y;
			(tL*=Len[y])%=Mod;
			tn=(tn*Len[y]%Mod+to[y])%Mod;
		}
		to[x]=tn;
		Len[x]=tL;
	}
	int L=strlen(c);
	for (int i=0;i<L;i++)
	{
		int x=c[i]-'0';
		Ans=(Ans*Len[x]%Mod+to[x])%Mod;
	}
	printf("%I64d\n",Ans);
}