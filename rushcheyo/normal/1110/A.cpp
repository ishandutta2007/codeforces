#include<bits/stdc++.h>
using namespace std;

int main(){
	int b,k,a,ans=0;
	scanf("%d%d",&b,&k);
	while(k--){
		scanf("%d",&a);
		ans^=a%2*(k==0?1:b%2);
	}
	puts(ans?"odd":"even");
}