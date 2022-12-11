#include<cstdio>
#include<algorithm>
using namespace std;

const int Maxn=2e5+19;
int A[Maxn],B[Maxn],n,Q,L,R;
long long Ans;

int main()
{
	scanf("%d%d",&n,&Q);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]);
	while (Q--)
	{
		scanf("%d%d",&L,&R);
		B[L]++;B[R+1]--;
	}
	for (int i=1;i<=n;i++) B[i]+=B[i-1];
	sort(B+1,B+n+1);
	sort(A+1,A+n+1);
	for (int i=1;i<=n;i++) Ans+=1LL*A[i]*B[i];
	printf("%I64d\n",Ans);
}