#include<cstdio>
#include<algorithm>
#define Lsn (x<<1)
#define Rsn (x<<1|1)
using namespace std;

const int Maxn=1e6+19;
struct note
{
	int LM,RM,Max,pos;
} S[Maxn*4];
int n,Q,opt,x,NEW,pos;
int Map[Maxn];

inline void Build_Tree(int x,int L,int R)
{
	S[x]=(note){(R-L+1),(R-L+1),(R-L+1),L};
	if (L==R) return;
	int Mid=(L+R)>>1;
	Build_Tree(Lsn,L,Mid);
	Build_Tree(Rsn,Mid+1,R);
}
inline void Get_Max(int x,int v,int pos)
{
	if (v>S[x].Max) S[x].Max=v,S[x].pos=pos;
}
inline void Update(int x,int L,int R)
{
	if (L==R) {S[x].LM=S[x].RM=S[x].Max=NEW;return;}
	int Mid=(L+R)>>1;
	if (pos<=Mid) Update(Lsn,L,Mid);else Update(Rsn,Mid+1,R);
	S[x].LM=S[Lsn].LM;if (S[Lsn].LM==Mid-L+1) S[x].LM+=S[Rsn].LM;
	S[x].RM=S[Rsn].RM;if (S[Rsn].RM==R-Mid)   S[x].RM+=S[Lsn].RM;
	S[x].Max=0;
	Get_Max(x,S[Lsn].Max,S[Lsn].pos);
	Get_Max(x,S[Lsn].RM+S[Rsn].LM,Mid-S[Lsn].RM+1);
	Get_Max(x,S[Rsn].Max,S[Rsn].pos);
}
inline int Find(int x,int L,int R,int Len)
{
	if (L==R) return L;
	if (L==1&&S[x].LM>=Len) return 1;
	int Mid=(L+R)>>1;
	if (S[Lsn].Max>=Len*2-1) return Find(Lsn,L,Mid,Len);
	if (S[Lsn].RM+S[Rsn].LM>=Len*2-1) return Mid-S[Lsn].RM+Len;
	return Find(Rsn,Mid+1,R,Len);
}

int main()
{
	scanf("%d%d",&n,&Q);
	Build_Tree(1,1,n);
	while (Q--)
	{
		scanf("%d%d",&opt,&x);
		if (opt==1)
		{
			pos=Find(1,1,n,max((S[1].Max+1)/2,max(S[1].LM,S[1].RM)));
			NEW=0;Update(1,1,n);
			Map[x]=pos;
			printf("%d\n",pos);
		} else
		{
			pos=Map[x];
			NEW=1;Update(1,1,n);
		}
	}
}