#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int i,j,k,n,m,t;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		if((n+m)&1){
			puts("-1");continue;
		}
		if(n==0&&m==0){
			puts("0");continue;
		}
		if(n==m){
			puts("1");continue;
		}
		puts("2");
	}
}