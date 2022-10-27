#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100000 + 10;
int t, n, p[N];
int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) scanf("%d", &p[i]);
		bool flag = true;
		vector<int> vec;
		for (int i = 1, j = 1; i <= n; i = j) {
			vec.push_back(p[i]);
			while (j <= n && p[j] - p[i] == j - i) j ++;
		}
		for (int i = 0; i + 1 < vec.size(); i ++) {
			if (vec[i] < vec[i+1]) flag = false;
		}
		sort(p + 1, p + 1 + n);
		for (int i = 1; i <= n; i ++) if (p[i] != i) {
			flag = false;
		}
		printf("%s\n", flag ? "Yes" : "No");
	}
}