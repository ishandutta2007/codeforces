#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
#define ll long long
#define mp make_pair
#define X first
#define Y second
const ll M=1000000007;
ll a,b;
int main(void)
{
	ll i,k;
	cin>>a>>b;
	k=0;
	for(i=1;i<=b-1;i++)
	{
		k=(k+a*i%M+(1+a)*a/2%M*i%M*b%M)%M;
	}
	cout<<k;
	return 0;
}