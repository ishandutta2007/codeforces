#include <bits/stdc++.h>
using namespace std;
long long a,b,c,d,e;
int main(){
	scanf("%lld",&a);
	for(int i=1;i<=a;i++){
		scanf("%lld%lld%lld",&b,&c,&d);
		e=abs(c-d);
		e+=d;
		if(b<e){
			cout<<1<<'\n';
		}else if(b>e){
			cout<<2<<'\n';
		}else{
			cout<<3<<'\n';
		}
	}
	return 0;
}