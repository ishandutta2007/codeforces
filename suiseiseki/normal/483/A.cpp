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
int main(){
	ll left,right;
	cin>>left>>right;
	for(ll a=left;a<=right;a++){
		for(ll b=a+1;b<=right;b++){
			for(ll c=b+1;c<=right;c++){
				if(gcd(a,b)==1&&gcd(b,c)==1&&gcd(a,c)!=1){
					cout<<a<<" "<<b<<" "<<c<<endl;
					return 0;
				}
			}
		}
	}
	cout<<"-1"<<endl;
	return 0;
}