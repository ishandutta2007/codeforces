#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	scanf("%d",&n);
	if(n%2==0){
		puts("NO");
		return 0;
	}
	puts("YES");
	for(int i=1;i<=n;++i){
		printf("%d ",i*2-(i&1));
	}
	for(int i=1;i<=n;++i)
		printf("%d ",i*2-(!(i&1)));
	return 0;
}