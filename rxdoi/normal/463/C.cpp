#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

const int Maxn=2000+19;
typedef long long LL;
typedef LL two[Maxn][Maxn];
two A,t1,t2;
LL sum[Maxn*2],Ans;
struct note 
{
	LL num,x,y;
	bool operator < (const note& B) const {return num>B.num;}
} A1,A2;
vector<note> V[Maxn*2];
int n;

int main()
{
	Ans=-1LL;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) scanf("%I64d",&A[i][j]);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) t1[i][j]=t1[i-1][j-1]+A[i][j];
	for (int i=n;i;i--) 
		for (int j=n;j;j--) t2[i][j]=t2[i+1][j+1]+A[i][j];	
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) sum[i-j+Maxn]=t1[i][j]+t2[i][j]-A[i][j];
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) t1[i][j]=t1[i-1][j+1]+A[i][j];
	for (int i=n;i;i--) 
		for (int j=n;j;j--) t2[i][j]=t2[i+1][j-1]+A[i][j];
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) V[i-j+Maxn].push_back((note){t1[i][j]+t2[i][j]-A[i][j]*2LL,i,j});
	for (int i=1-n+Maxn;i<=n-1+Maxn;i++) sort(V[i].begin(),V[i].end());
	for (int i=1-n+Maxn;i<=n-1+Maxn;i++) 
		for (int j=i+1;j<=n-1+Maxn;j++) 
			if ((j-i)%2==1) 
			{
				LL tmp=sum[i]+V[i][0].num+sum[j]+V[j][0].num;
				if (tmp>Ans) {Ans=tmp;A1=V[i][0];A2=V[j][0];}
			}
	printf("%I64d\n",Ans);
	printf("%I64d %I64d %I64d %I64d\n",A1.x,A1.y,A2.x,A2.y);
}