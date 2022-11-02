#include<bits/stdc++.h>
using namespace std;
#define N 1000000007
int n,x[300010],f[300010],sum;
main(){
	f[0]=1;
	for(int i = 1; i <= 300000; i ++) f[i]=f[i-1]*2,f[i]%=N;
	scanf("%d",&n);
	for(int i = 0; i < n; i ++) scanf("%d",x+i);
	sort(x,x+n);
	for(int i = 0; i < n; i ++) sum=(sum+1ll*(f[i]-f[n-i-1]+N)*x[i])%N;
	printf("%d",sum);
}