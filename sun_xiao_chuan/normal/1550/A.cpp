#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,n,m,t,sb,k;


int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		k=0;j=0;
		for(i=1;;i+=2){
			j+=i;k++;
			if(j>=n){break;}
		}
		printf("%d\n",k);
	}
}