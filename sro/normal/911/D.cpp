#include <bits/stdc++.h>
using namespace std;

int a[1555];
int n;
int ss;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]>a[j]){
				ss^=1;
			}
		}
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int l,r;
		scanf("%d%d",&l,&r);
		ss^=((r-l+1)*(r-l)/2)&1;
		if(ss){
			puts("odd");
		}else{
			puts("even");
		}
	}
	return 0;
}