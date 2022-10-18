#include <cstdio>
#include <iostream>
using namespace std;
int main(){
	int t;
	int a,b,k;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&a,&b,&k);
		cout<<((k+1)>>1)*1ll*a-(k>>1)*1ll*b<<endl;
	}
	return 0;
}