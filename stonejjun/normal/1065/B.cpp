#include <bits/stdc++.h>
using namespace std;
#define mod 1e9+7
const int maxn = 200005;
const int maxm = 200005;
long long int arr[1000000];


int main() 
{
	long long int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
	scanf("%lld %lld",&a,&b);
	
	if(b*2>=a) printf("0 \n");
	else printf("%lld ",a-(b*2));
	
	for(i=0;i<=100000;i++)
	{
		if(((i-1)*(i))>=b*2) 
		{
			break;
		}
	}
	
	
	if(i>=a) printf("0");
	else printf("%lld",a-i);
	return 0;
}