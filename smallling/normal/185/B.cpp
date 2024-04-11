#include<cstdio>

using namespace std;

int a,b,c,s;

int main()
{
	scanf("%d",&s);
	scanf("%d%d%d",&a,&b,&c);
	if(!a&&!b&&!c)puts("0.0 0.0 0.0");
	else printf("%.10lf %.10lf %.10lf",1.*a/(a+b+c)*s,1.*b/(a+b+c)*s,1.*c/(a+b+c)*s);
}