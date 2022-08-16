#include <stdio.h>

long long f(int x)
{
	long long r = 0;
	while(x){
		if(x%10!=0) r=r*10+(x%10);
		x/=10;
	}
	while(r){ x=x*10+(r%10); r/=10; }
	return x;
}

int main()
{
	long long a, b;
	scanf("%lld %lld",&a,&b);	
	puts(f(a)+f(b)==f(a+b)?"YES":"NO");	
	return 0;
}