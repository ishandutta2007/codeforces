#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, m, k, ans = 0x3f3f3f3f;
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; i++){
		int t; scanf("%d", &t);
		if(t && t <= k && abs(m - i) * 10 <  ans)
			ans = abs(m - i) * 10;
	}
	printf("%d\n", ans);
	return 0;
}