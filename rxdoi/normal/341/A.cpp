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

const int N=100000+19;
typedef long long LL;
LL A,B,t,tmp;
int D[N],n;

LL gcd(LL a,LL b) {return !b?a:gcd(b,a%b);}

int main()
{
	B=n=IN();
	For(i,0,n) D[i]=IN();
	sort(D,D+n);
	for (int i=0;i<n;i++) A+=1LL*i*D[i]-tmp,tmp+=D[i];A*=2;
	For(i,0,n) A+=D[i];
	t=gcd(A,B);
	printf("%I64d %I64d\n",A/t,B/t);
}