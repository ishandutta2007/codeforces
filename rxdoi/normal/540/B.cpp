#include<cstdio>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

const int N=1000+19;
int A[N],B[N];
int n,k,p,x,y,sum,tot,cnt;

int main()
{
	scanf("%d%d%d%d%d",&n,&k,&p,&x,&y);tot=k;
	For(i,1,k+1) scanf("%d",&A[i]),sum+=A[i];
	sort(A+1,A+k+1);
	if (sum+n-k>x) return puts("-1"),0;
	if (k>=(n+1)/2&&A[(n+1)/2]<y) return puts("-1"),0;
	int t=lower_bound(A+1,A+k+1,y)-A;
	t=(n+1)/2-t;
	while (t--&&tot<n) A[++tot]=1,B[++cnt]=1,sum++;
	while (tot<n) A[++tot]=y,B[++cnt]=y,sum+=y;
//		sort(A+1,A+tot+1);
	if (sum>x) return puts("-1"),0;
	For(i,1,cnt+1) printf("%d ",B[i]);puts("");
}