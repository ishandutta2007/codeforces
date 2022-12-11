#include<cstdio>
#include<algorithm>
using namespace std;

const int M=3e5+19,oo=(1<<30)-1;
struct Edge
{
	int x,y,z;
	bool operator < (const Edge& B) const {return z<B.z;}
} E[M];
int F[M],pre[M],to[M];
int n,m,Ans,cnt;

inline void Check(int &a,int b) {a=a>b?a:b;}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++) scanf("%d%d%d",&E[i].x,&E[i].y,&E[i].z);
	sort(E,E+m);
	for (int i=0;i<m;i++)
	{
		pre[0]=F[E[i].x]+1;to[0]=E[i].y;
		cnt=1;
		for (;E[i].z==E[i+1].z;i++) pre[cnt]=F[E[i+1].x]+1,to[cnt++]=E[i+1].y;
		while (--cnt>=0) Check(F[to[cnt]],pre[cnt]);
	}
	for (int i=1;i<=n;i++) Check(Ans,F[i]);
	printf("%d\n",Ans);
}