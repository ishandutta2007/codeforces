#include<cmath>
#include<cstdio>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

typedef long long LL;
LL n,a,b,A1,B1,S=1LL<<60;

void Check(LL a1,LL b1) {if (a1*b1<S) S=a1*b1,A1=a1,B1=b1;}

int main()
{
	scanf("%I64d%I64d%I64d",&n,&a,&b);n*=6;
	for (LL a1=a,_=sqrt(max(n,a*b))+1;a1<=_;a1++) Check(a1,max(n/a1+(n%a1!=0),b));
	for (LL b1=b,_=sqrt(max(n,a*b))+1;b1<=_;b1++) Check(max(n/b1+(n%b1!=0),a),b1);
	printf("%I64d\n",S);
	printf("%I64d %I64d\n",A1,B1);
}