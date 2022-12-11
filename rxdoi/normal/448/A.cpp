#include<cstdio>
#include<cmath>
using namespace std;

int a,b,x;

int main()
{
	for (int i=0;i<3;i++) scanf("%d",&x),a+=x;
	for (int i=0;i<3;i++) scanf("%d",&x),b+=x;
	scanf("%d",&x);
	printf("%s\n",ceil(double(a)/5.)+ceil(double(b)/10.)<=x?"YES":"NO");
}