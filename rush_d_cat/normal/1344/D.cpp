#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 10;
typedef long long LL;
int n;  LL k, a[N], ans[N];
LL solve(LL A, LL lim) {
	// a - (3*x*x - 3*x + 1) >= lim
	if (A < lim) return 0;
	LL lef = 0, rig = A + 1;
	while (rig - lef > 1) {
		LL mid = (lef + rig) >> 1;
		if (A - (3*mid*mid - 3*mid + 1) >= lim) lef = mid;
		else rig = mid;
	}
	return lef;
}
bool cac(LL lim) {
	LL sum1 = 0;
	for (int i = 1; i <= n; i ++) {
		LL x = solve(a[i], lim);
		sum1 += x;
	}
	return sum1 >= k;
}
int main() {
	scanf("%d%lld", &n, &k);
	for (int i = 1; i <= n; i ++) 
		scanf("%lld", &a[i]);
	//cac(- 32); return 0;
	LL lef = -3e18, rig = 1e18;
	while(rig - lef > 1) {
		LL mid = (lef + rig) >> 1;
		if (cac(mid) == true) lef = mid;
		else rig = mid;
	}
	//printf("lef = %lld\n", lef);
	LL sum = 0;
	for (int i = 1; i <= n; i ++) {
		ans[i] = solve(a[i], lef);
		sum += ans[i];
	}
	//printf("sum = %lld\n", sum);
	LL rem = sum - k;
	LL lim = lef;
	vector< pair<int,int> > vec;
	for (int i = 1; i <= n; i ++) {
		LL lef = 0, rig = a[i] + 1;
		while (rig - lef > 1) {
			LL mid = (lef + rig) >> 1;
			if (a[i] - (3*mid*mid - 3*mid + 1) >= lim) lef = mid;
			else rig = mid;
		}		
		if (a[i] - (3*lef*lef-3*lef+1) == lim) {
			vec.push_back(make_pair(a[i], i));
		}
	}
	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());
	for (int i = 0; i < rem; i ++) {
		ans[ vec[i].second ] --;
	}
	//LL s = 0;
	for (int i = 1; i <= n; i ++) {
		printf("%lld ", ans[i]);
	//	s += ans[i] * (a[i] - ans[i] * ans[i]);
	}
	//cout << s << endl;
}

/*
b(a-b*b) 


*/