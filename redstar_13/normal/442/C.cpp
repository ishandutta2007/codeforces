#include<bits/stdc++.h>

using namespace std;

typedef long long INT;
#define NN 500010

int arr[NN];
INT ans = 0;

auto solve = [&] (const int n) {
	if(n <= 2) return 0;
	if(arr[n-1] <= min(arr[n], arr[n-2])) {
		ans += min(arr[n], arr[n-2]); 
		arr[n-1] = arr[n];
		return 1;
	}
	return 0;
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int n;
	
	scanf("%d", &n);
	int nn = 0;
	
	for(int i=1, x; i<=n; i++) {
		scanf("%d", &x);
		arr[++nn] = x;
		while(solve(nn)) nn--;
	}
	
	sort(arr+1, arr+nn+1);
	
	for(int i=1; i<=nn-2; i++) ans += arr[i];
	printf("%I64d\n", ans);
}