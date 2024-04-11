#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int t;
long long n,x,y; 

int main()
{
	scanf("%d",&t);
	while(t--){
		scanf("%lld%lld%lld",&n,&x,&y);
		if(x >= y)
			printf("%lld\n",n);
		else{
			long long p = n;
			n = (n+1)/2;
			printf("%lld\n",max(p,n/x*(x+y)+n%x-(n%x ? 0 : y)));
		}
	}
}