#include<bits/stdc++.h>
using namespace std;

#define N 1000100

long long A, B, n, l, t, m, ans;

main(){
	scanf("%I64d%I64d%I64d",&A,&B,&n);
	while(n --){
		scanf("%I64d%I64d%I64d",&l,&t,&m);
		ans = (t - A) / B + 1;
		long long s = l, e = l + 10000000,mid, cnt = 80;
		while(cnt --){
			mid = (s + e)/2;
			if(A*(mid-l+1)+B*(l+mid-2)*(mid-l+1)/2 <= t*m) s = mid;
			else e = mid;
		}
		ans = min(ans,mid);
		if(ans < l) puts("-1");
		else printf("%I64d\n",ans);
	}
}