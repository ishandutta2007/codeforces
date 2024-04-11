#include<bits/stdc++.h>
using namespace std;
int T,a,b,c,d,k;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
		if((a/c)+(a%c!=0)+b/d+(b%d!=0)>k)puts("-1");
			else printf("%d %d\n",a/c+(a%c!=0),b/d+(b%d!=0));
	}
	return 0;
}