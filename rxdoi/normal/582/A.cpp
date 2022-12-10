#include<map>
#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

const int N=500+19;
map<int,int> M;
int A[N*N],B[N];
int n,tot;

int main()
{
	n=IN();
	For(i,0,n*n) M[A[i]=IN()]++;
	sort(A,A+n*n);
	for (int i=n*n-1;~i;i--)
		if (M[A[i]])
		{
			printf("%d ",A[i]);
			M[A[i]]--;
			For(j,0,tot) M[__gcd(A[i],B[j])]-=2;
			B[tot++]=A[i];
		}
}