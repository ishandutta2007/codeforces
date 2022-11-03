#include<cstdio>
#include<cmath>
using namespace std;

int main(){
	long long n;scanf("%I64d",&n);
	int m=0;
	while((long long)2*m+(long long)3*m*(m-1)/2<=n)m++;m--;
	while(((2*m)%3+3)%3!=n%3)
		m--;
	printf("%d\n",(m+2)/3);
	return 0;
}