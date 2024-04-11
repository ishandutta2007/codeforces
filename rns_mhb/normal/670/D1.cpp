#include<bits/stdc++.h>
using namespace std;

int n, k, ans, a[1010], b[1010];

main(){
	scanf("%d%d",&n,&k);
	for(int i = 0;i < n;i ++) scanf("%d",a + i);
	for(int i = 0;i < n;i ++) scanf("%d",b + i);
	while(1){
		int sum = 0;
		for(int i = 0;i < n;i ++) if(a[i] * ans > b[i]) sum += (a[i] * ans - b[i]);
		if(sum > k) break;
		ans ++;
	}
	printf("%d",ans - 1);
}