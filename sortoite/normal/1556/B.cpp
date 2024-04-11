#include<bits/stdc++.h>

using namespace std;

const int NN = 1e5 + 10;
int a[NN], n;

long long calc(int b, int can) {
	long long res = 0;
	for(int i = 1; i <= n; i++) if((a[i] & 1) == can) {
		if(i > b) res += i - b;
		b += 2;
	}
	return res;
}

long long solve() {
	long long ans; cin >> n;
	int t0 = 0, t1 = 0;
	for(int i = 1; i <= n; i ++) {
		scanf("%d", a + i);
		a[i] &= 1;
		if(a[i] == 0) t0 ++;
		else t1 ++;
	}
	if(t0 > t1 + 1 || t1 > t0 + 1) return - 1;
	int can = 0;
	if(t0 + 1 == t1) can = 1;
	ans = calc(1, can) + calc(2, can ^ 1);
	if(t0 == t1) return min(ans, calc(1, can ^ 1) + calc(2, can));
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
#endif
	int T; cin >> T;
	while(T --) {
		cout << solve() << endl;
	}
	return 0;
}