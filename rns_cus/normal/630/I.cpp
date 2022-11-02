#include <bits/stdc++.h>
using namespace std;

int n;

long long exp(int a, int b) {
	long long rlt = 1;
	for (int i = 1; i <= b; i ++) rlt *= a;
	return rlt;
}

int main() {
//	freopen("i.in", "r", stdin);
	cin >> n;
	cout << 4ll * (6ll * exp(4, n - 3) + 9ll * (n - 3) * exp(4, n - 4)) << endl;
	return 0;
}