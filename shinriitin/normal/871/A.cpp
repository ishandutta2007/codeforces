#include <bits/stdc++.h>

int n,q;

inline void solve_odd(){
	if(n==9){
		puts("1");
		return;
	}
	if(n<=11){
		puts("-1");
		return;
	}
	n-=9;
	int res=n/4+1;
	printf("%d\n",res);
}

inline void solve_even(){
	if(n==2){
		puts("-1");
		return;
	}
	int res=n/4;
	printf("%d\n",res);
}

int main(){
	scanf("%d",&q);
	while(q--){
		scanf("%d",&n);	
		if(n&1)solve_odd();
		else solve_even();
	}
	return 0;	
}