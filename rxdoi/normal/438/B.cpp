#include<cstdio>
#include<algorithm>
using namespace std;

const int Maxm=100000+19;
struct Edge
{
	int x,y,Dis;
	bool operator < (const Edge& B) const {return Dis>B.Dis;}
} E[Maxm];
int n,m,x,y,z;
int Fa[Maxm],Size[Maxm],A[Maxm];
double Ans=0.;

inline int Getf(int x) {return Fa[x]==x?x:Fa[x]=Getf(Fa[x]);}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]);
	for (int i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		E[i]=(Edge){x,y,min(A[x],A[y])};
	}
	sort(E,E+m);
	for (int i=1;i<=n;i++) Fa[i]=i,Size[i]=1;
	for (int i=0;i<m;i++)
	{
		x=E[i].x;y=E[i].y;
		int Fx=Getf(x),Fy=Getf(y);
		if (Fx==Fy) continue;
		Ans+=double(Size[Fx])*double(Size[Fy])*double(E[i].Dis);
		Fa[Fx]=Fy;Size[Fy]+=Size[Fx];
	}
	printf("%.6lf\n",2.*double(Ans)/double(n)/double(n-1));
	return 0;
}