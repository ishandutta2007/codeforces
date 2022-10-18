#include <cstdio>
using namespace std;
int a,b,c,d;
bool O(int a,int b){return (a^b);}
bool A(int a,int b){return (a&b);}
bool X(int a,int b){return (a|b);}
int main()
{
	scanf("%d%d%d%d",&a,&b,&c,&d);
	printf("%d\n",O(A(O(a,b),X(c,d)),X(A(b,c),O(a,d))));
	return 0;
}