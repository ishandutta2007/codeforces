#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		j=k=(n+2)/3;
		if((n%3)==1){k--;}
		if((n%3)==2){j--;}
		printf("%d %d\n",j,k);
	}
}