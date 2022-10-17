#include <cstdio>
#include <iostream>
using namespace std;
#define ll long long
int main(){
	int t;
	scanf("%d",&t);
	ll n;
	int a,b;
	while(t--){
		cin>>n;
		scanf("%d%d",&a,&b);
		if((a<<1)<=b){
			cout<<n*a<<endl;
		}
		else{
			cout<<(n>>1)*b+(n&1)*a<<endl;
		}
	}
	return 0;
}