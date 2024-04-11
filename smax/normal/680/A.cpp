
// Problem : A. Bear and Five Cards
// Contest : Codeforces Round #356 (Div. 2)
// URL : https://codeforces.com/problemset/problem/680/A
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> cnt;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int sum = 0;
	for (int i=0; i<5; i++) {
		int t;
		cin >> t;
		sum += t;
		cnt[t]++;
	}
	
	int ret = sum;
	for (auto p : cnt)
		if (p.second > 1)
			ret = min(ret, sum - min(p.second, 3) * p.first);
	
	cout << ret << "\n";
	
	return 0;
}