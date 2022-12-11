#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

const int Maxn=(2e5+19)*2;
struct note 
{
	int x,Dis;
	bool operator < (const note& B) const {return x<B.x;}
};
struct Edge {int y,nxt;} E[Maxn*2];
vector<note> A;
int n,m,x,cnt,tot;
int Ans[Maxn],Last[Maxn],Ind[Maxn],can[Maxn],_can[Maxn],ccnt,_ccnt;

inline void Add_Edge(int x,int y)
{
	E[cnt]=(Edge){y,Last[x]};Last[x]=cnt++;
	Ind[y]++;
}

int main()
{
	memset(Last,-1,sizeof(Last));
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) 
	{
		A.clear();
		for (int j=1;j<=m;j++) scanf("%d",&x),A.push_back((note){x,j});
		sort(A.begin(),A.end());
		int uni=0;
		for (int j=0;j<m;j++)
			if (A[j].x!=-1) 
			{
				if (A[j].x!=A[j-1].x) uni++;
				Add_Edge(A[j].Dis,uni+i*(m+1));
				Add_Edge(uni+i*(m+1)+1,A[j].Dis);
			}
	}
	m=(n+1)*(m+1)+1;
	for (int i=1;i<=m;i++)
		if (Ind[i]==0) _can[_ccnt++]=i;
	while (tot<m)
	{
		memcpy(can,_can,sizeof(_can));
		ccnt=_ccnt;_ccnt=0;
		if (ccnt==0) {printf("-1\n");return 0;}
		for (int i=0;i<ccnt;i++)
		{
			int x=can[i];
			Ans[tot++]=x;
			for (int j=Last[x];j!=-1;j=E[j].nxt)
			{
				int y=E[j].y;
				if (--Ind[y]==0) _can[_ccnt++]=y;
			}
		}
	}
	for (int i=tot-1;i>=0;i--)
		if (Ans[i]<=(m-1)/(n+1)-1) printf("%d ",Ans[i]);puts("");
}