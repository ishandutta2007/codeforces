#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define max_N 55
typedef long long ll;

int n;

ll k,f[2][max_N];

int main(){
	scanf("%d%I64d",&n,&k);
	f[0][0]=1;
	for(int i=1;i<=n;++i){
		f[0][i]=f[0][i-1]+f[1][i-1];
		if(i>=2){
			f[1][i]=f[0][i-2]+f[1][i-2];
		}
	}
	int i=1;
	while(i<=n){
		if(k<=f[0][n-i+1]){
			printf("%d ",i);
			++i;
		}	
		else{
			k-=f[0][n-i+1];
			printf("%d %d ",i+1,i);
			i+=2;
		}
	}
	return puts(""),0;
}