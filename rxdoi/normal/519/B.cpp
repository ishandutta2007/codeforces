#include<cstdio>
#include<cctype>
#include<algorithm>
using namespace std;

const int Maxn=1e5+19;
int A[Maxn],B[Maxn],C[Maxn];
int n;

int c;
void read(int &x)
{
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=x*10+c-'0';
}

int main()
{
	read(n);
	for (int i=1;i<=n;i++) read(A[i]);sort(A+1,A+n+1);
	for (int i=1;i<n;i++) read(B[i]);sort(B+1,B+n);B[n]=-1;
	for (int i=1;i<n-1;i++) read(C[i]);sort(C+1,C+n-1);C[n-1]=-2;
	for (int i=1;i<=n;i++)
		if (A[i]!=B[i]) {printf("%d\n",A[i]);break;}
	for (int i=1;i<n;i++)
		if (B[i]!=C[i]) {printf("%d\n",B[i]);break;}
}