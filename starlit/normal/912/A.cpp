#include<bits/stdc++.h>
using namespace std;
long long A,B,aa,bb,x;
int main()
{
	scanf("%lld%lld",&A,&B);
	scanf("%lld",&x),aa+=2*x;
	scanf("%lld",&x),aa+=x,bb+=x;
	scanf("%lld",&x),bb+=3*x;
	printf("%lld",max(0LL,aa-A)+max(0LL,bb-B));
}