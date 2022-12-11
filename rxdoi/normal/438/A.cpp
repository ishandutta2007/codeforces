#include<cstdio>
#include<algorithm>
using namespace std;

const int Maxn=1000+19;
struct note
{
	int num,v;
	bool operator < (const note& B) const {return v>B.v;}
} A[Maxn];
int n,m,x,y,z,Ans=0;
int B[Maxn][Maxn],cut[Maxn],s[Maxn];

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) scanf("%d",&A[i].v),A[i].num=i+1,s[i+1]=A[i].v;
	for (int i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		B[x][y]=B[y][x]=1;
	}
	sort(A,A+n);
	for (int i=0;i<n;i++)
	{
		x=A[i].num;
		cut[x]=1;
		for (int j=1;j<=n;j++) if (B[x][j]&&!cut[j]) Ans+=s[j];
	}
	printf("%d\n",Ans);
	return 0;
}