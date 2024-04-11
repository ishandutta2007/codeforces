#include<cstdio>
#include<cctype>
#include<cstdlib>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

int n,k,c,A[2];

void S() {puts("Stannis");exit(0);}
void D() {puts("Daenerys");exit(0);}

int main()
{
	n=IN(),k=IN(),c=(n-k)/2;
	For(i,0,n) A[IN()&1]++;
	if (n==k) A[1]&1?S():D();
	if (n-k&1)
		if (k+1&1) c>=A[0]||c>=A[1]?D():S();else c>=A[1]?D():S();
	else
		if (k+1&1) D();else c>=A[0]?S():D();
}