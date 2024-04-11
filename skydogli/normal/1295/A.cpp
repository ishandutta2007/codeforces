#include<bits/stdc++.h>
using namespace std;
int T,n,m;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		if(n&1) putchar('7'),n-=3;
		while(n){
			n-=2;
			putchar('1');
		}
		puts("");
	}
}