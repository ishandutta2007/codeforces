#include <cstdio>
#include <iostream>
using namespace std;
#define ll long long
int main(){
	int t;
	ll len,v,l,r;
	scanf("%d",&t);
	while(t--){
		cin>>len>>v>>l>>r;
		cout<<(len/v)-(r/v)+((l-1)/v)<<endl;
	}
	return 0;
}