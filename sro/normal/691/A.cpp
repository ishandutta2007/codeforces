#include <bits/stdc++.h>
using namespace std;

int n,a[1005];

int main(){
	scanf("%d",&n);
	int x=0;
	for(int i=0;i<n;i++){
		scanf("%d",a+i);
		if(!a[i]){
			x++;
		}
	}
	if(n==1){
		x++;
	}
	if(x==1){
		puts("YES");
	}else{
		puts("NO");
	}
	return 0;
}