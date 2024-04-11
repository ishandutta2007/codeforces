#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2002;
int n, p, a[N], b[N];
int check(int x){
	for (int i = 1; i <= n; i ++) {
		if (x >= a[i]) b[i] = n;
		else b[i] = n + (x - a[i]);
		if (b[i] < 0) return 0;
	}
	sort(b + 1, b + 1 + n);
	LL ans = 1 % p;
	for (int i = 1; i <= n; i ++) {
		if (b[i] - (i-1) <= 0) return 0;
		ans = ans * (b[i] - (i - 1)) % p;
	}
	return ans;
}
int main() {
	scanf("%d%d",&n,&p);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	vector<int> v;
	for (int x = 1; x <= 2000; x ++) {
		if (check(x)) v.push_back(x);
	}
	printf("%d\n", v.size());
	for (auto x: v) printf("%d ", x);
}