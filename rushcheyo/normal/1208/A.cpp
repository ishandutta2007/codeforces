#include<bits/stdc++.h>
using namespace std;

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int a,b,n;
		scanf("%d%d%d",&a,&b,&n);
		printf("%d\n",n%3==0?a:n%3==1?b:(a^b));
	}
	return 0;
}