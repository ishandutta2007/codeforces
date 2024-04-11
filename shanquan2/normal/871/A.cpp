#include<bits/stdc++.h>
using namespace std;

int main(){
	int T;scanf("%d",&T);
	while(T--){
		int n;scanf("%d",&n);
		if(n%4==0)printf("%d\n",n/4);
		else if(n%4==1){
			if(n<9)printf("-1\n");else printf("%d\n",(n-9)/4+1);
		}else if(n%4==2){
			if(n<6)printf("-1\n");else printf("%d\n",(n-6)/4+1);
		}else if(n%4==3){
			if(n<15)printf("-1\n");else printf("%d\n",(n-15)/4+2);
		}
	}
	return 0;
}