#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int dptable[100001];
int fibo(int n) {
	if (dptable[n] != -1) return dptable[n];
	if (n == 0 || n == 1) return dptable[n] = 1;
	return dptable[n] = (fibo(n - 1) + fibo(n - 2)) % 1000000007;
}
int main() {
	fill_n(dptable, 100001, -1);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string str;
	cin >> str;
	for (char i: str) {
		if (i == 'm' || i == 'w') {
			printf("0");
			return 0;
		}
	}
	int cur = 1;
	vector<int> regret;
	for (int i = 1; i < str.length(); ++i) {
		if ((str[i] == 'n' || str[i] == 'u') && str[i] == str[i - 1]) ++cur;
		else {
			if (cur != 1) regret.push_back(cur);
			cur = 1;
		}
	}
	if (cur != 1) regret.push_back(cur);
	long long ans = 1;
	for (int i: regret) ans = ans * fibo(i) % 1000000007;
	printf("%lld", ans);
	return 0;
}