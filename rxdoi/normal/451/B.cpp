#include<cstdio>
using namespace std;

const int Maxn=1e5+19;
int A[Maxn],n,rev,can=1,L,R;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]);
	A[n+1]=(1<<30)-1;
	for (int i=1;i<=n;i++)
	{
		if (!can&&A[L]>A[i]) {puts("no");return 0;}
		if (rev)
		{
			if (A[i]<A[i+1]) 
				if (A[i]<A[L-1]) {puts("no");return 0;}
					else R=i,rev=0,can=0;
		} else
		{
			if (A[i]>A[i+1]) 
				if (!can) {puts("no");return 0;}
					else rev=1,L=i;
		}
	}
	puts("yes");
	printf("%d %d\n",!L?1:L,!R?1:R);			
}