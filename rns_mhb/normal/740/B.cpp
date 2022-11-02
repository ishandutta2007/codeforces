#include <bits/stdc++.h>
using namespace std;

int m, n, a[105], b, l, r, ans, i;

int main(){
	scanf("%d %d", &n, &m);
	for(i = 1; i <= n; i++){
		scanf("%d", &b);
		a[i] = a[i - 1] + b;
	}
	while(m--){
		scanf("%d %d", &l, &r);
		if(a[r] > a[l - 1]) ans += a[r] - a[l - 1];
	}
	cout << ans;
}