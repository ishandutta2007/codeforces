#include<cstdio>
#include<algorithm>
using namespace std;

const int Maxn=5000+19;
struct note {int a,b;} A[Maxn];
int n,x,Ans;

inline int cmp(note a,note b) {return a.a<b.a||a.a==b.a&&a.b<b.b;}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d%d",&A[i].a,&A[i].b);
	sort(A+1,A+n+1,cmp);
	for (int i=1;i<=n;i++) 
	{
		if (A[i].b>=x) x=A[i].b,Ans=max(Ans,A[i].b);
			else x=A[i].a,Ans=max(Ans,A[i].a);
	}
	printf("%d\n",Ans);
}