#include<bits/stdc++.h>
#define ll long long
using namespace std;
void print(ll n,ll k)
{
	if(n==1) {cout<<"()";return;}
	if(((n-1)*(n-2))/2<k) {cout<<"(";print(n-1,k-(n-1));cout<<")";}
	else {cout<<"()";print(n-1,k);}
}
int main()
{
	ll n,k;cin>>n>>k;if((n*(n-1))/2<k) {cout<<"Impossible";return 0;}
	print(n,k);
}