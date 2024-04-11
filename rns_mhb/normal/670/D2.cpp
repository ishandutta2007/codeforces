#include<bits/stdc++.h>
using namespace std;

#define N 101000

long long n, k, a[N], b[N], ans, cnt = 300, s, e = 2000000001, mid, sum, i;
main(){
	scanf("%I64d%I64d",&n,&k);
	for(i = 0;i < n;i ++) scanf("%I64d",a + i);
	for(i = 0;i < n;i ++) scanf("%I64d",b + i);
	while(cnt --){
		mid = (s + e) / 2;
		sum = 0;
		for(i = 0;i < n;i ++) if(a[i] * mid > b[i]) {
				sum += (a[i]*mid-b[i]);
				if(sum > k) break;
		}
		if(sum > k) e = mid;
		else s = mid;
	}
	printf("%I64d",mid);
}