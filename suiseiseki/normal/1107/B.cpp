#include <cstdio>
#include <iostream>
using namespace std;
#define ll long long
int main(){
	int t;
	scanf("%d",&t);
	ll k;
	int x;
	while(t--){
		cin>>k;
		scanf("%d",&x);
		cout<<x+(k-1)*9<<endl;
	}
	return 0;
}