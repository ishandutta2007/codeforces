#include<bits/stdc++.h>
using namespace std;
#define N 101000

long long  n, k, a[N], t;

main(){
	scanf("%I64d%I64d",&n,&k);
	for(int i = 1;i <= n;i ++) scanf("%I64d",a + i);
	t = sqrt(2 * k);
	if(t*(t+1) == 2 * k) printf("%I64d",a[t]);
	else if(t*(t+1)/2 < k)printf("%I64d",a[k - t*(t+1)/2]);
	else printf("%I64d",a[k-t*(t-1)/2]);
}