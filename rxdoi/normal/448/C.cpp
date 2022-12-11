#include<cstdio>
#include<algorithm>
using namespace std;

const int Maxn=5000+19,oo=(1<<30)-1;
int A[Maxn],n;

inline int print_it(int L,int R)
{
	if (L>R) return 0;
	int Min=oo;
	for (int i=L;i<=R;i++) Min=min(Min,A[i]);
	for (int i=L;i<=R;i++) A[i]-=Min;
	int tmp=L,Ans=Min;
	for (int i=L;i<=R;i++) if (A[i]==0) Ans+=print_it(tmp,i-1),tmp=i+1;
	if (tmp<R+1) Ans+=print_it(tmp,R);
	return min(Ans,R-L+1);
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]);
	printf("%d\n",print_it(1,n));
}