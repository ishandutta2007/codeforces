#include <cstdio>
#include <iostream>
using namespace std;
#define ll long long
ll gcd(ll a,ll b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}
ll mn(ll a,ll b){
	return a<b?a:b;
}
int main(){
	ll a,b,c,d;
	cin>>a>>b>>c>>d;
	ll t=gcd(c,d);
	c/=t,d/=t;
	cout<<mn(a/c,b/d)<<endl;
	return 0;
}