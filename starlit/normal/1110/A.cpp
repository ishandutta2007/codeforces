#include<bits/stdc++.h>
using namespace std;
int b,n,x,tp;
int main(){
	scanf("%d%d",&b,&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		if((b&1)||i==n)tp+=(x&1);
	}
	if(tp&1)puts("odd");
	else puts("even");
}