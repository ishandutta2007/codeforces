#include<cstdio>
#include<cctype>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

const int N=1e5+19;
int A[N],pos[N];
int n,m,k,x;
long long Ans;

int main()
{
	n=IN(),m=IN(),k=IN();
	For(i,0,n) A[i]=IN(),pos[A[i]]=i;
	For(i,0,m)
	{
		x=IN();
		Ans+=pos[x]/k+1;
		if (pos[x]==0) continue;
			else
			{
				int t=A[pos[x]-1];
				swap(A[pos[x]],A[pos[x]-1]);
				swap(pos[x],pos[t]);
			}
	}
	printf("%I64d\n",Ans);
}