#include<cstdio>

using namespace std;

long double now;
int a,b,c,d,e,f,t;

int main()
{
		now=1.0;
		scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
		if(!a&&d&&b)
		{
			puts("Ron");
			return 0;
		}
		if(!c&&d)
		{
			puts("Ron");
			return 0;
		}
		if(!a)now=now*b/1e-5;
		else now=now*b/a;
		if(!c)now=now*d/1e-5;
		else now=now*d/c;
		if(!e)now=now*f/1e-5;
		else now=now*f/e;
		if(now>1.0)puts("Ron");
		else puts("Hermione");
}