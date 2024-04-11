#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define b(x) (1<<((x)-1))
int i,j,k,n,m,t,x,y,tmp;
int res;

int main() {
    scanf("%d",&t);
    while(t--){
    	scanf("%d",&n);
    	if(n==1){
    		puts("a");continue;
		}
		if(n==2){
			puts("sb");continue;
		}
    	if(n&1){
    		m=n/2;
    		for(i=1;i<=m;i++){
    			putchar('a');
			}
			printf("bc");
			for(i=1;i<m;i++){
    			putchar('a');
			}
			puts("");
		}
		else{
			m=n/2;
    		for(i=1;i<=m;i++){
    			putchar('a');
			}
			printf("b");
			for(i=1;i<m;i++){
    			putchar('a');
			}
			puts("");
		}
	}
}