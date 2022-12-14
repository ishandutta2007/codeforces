#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 200005;
const int P = 998244353;
const int inf = 0x3f3f3f3f;

int power(int a, ll x) {
	int ans = 1;
	for (; x; x >>= 1, a = 1ll * a * a % P)
		if (x & 1) ans = 1ll * ans * a % P;
	return ans;
}
int gcd(int a, int b) {
	return !b ? a : gcd(b, a % b);
}

char s[N];
bool del[N];

int main() {
	cin >> (s + 1);
	int left = strlen(s + 1);
	vector<vector<int>> output;
	for (;;) {
		vector<int> posl, posr;
		for (int i = 1; i <= left; ++i) del[i] = false;
		for (int i = 1; i <= left; ++i)
			if (s[i] == '(') posl.push_back(i);
			else posr.push_back(i);
		reverse(posr.begin(), posr.end());
		if (posl.empty() || posr.empty() || posl[0] > posr[0]) break;
		int i = 0;
		while (i + 1 < (int)posl.size() && i + 1 < (int)posr.size() && posl[i + 1] < posr[i + 1]) ++i;
		vector<int> res;
		for (int j = 0; j <= i; ++j) del[posl[j]] = del[posr[j]] = true, res.push_back(posl[j]), res.push_back(posr[j]);
		sort(res.begin(), res.end());
		output.push_back(res);
		static char t[N];
		int tot = 0;
		for (int i = 1; i <= left; ++i) if (!del[i]) t[++tot] = s[i];
		t[tot + 1] = 0;
		strcpy(s + 1, t + 1);
		left = tot;
	}
	printf("%d\n", (int)output.size());
	for (const auto &p : output) {
		printf("%d\n", (int)p.size());
		for (int x : p) printf("%d ", x);
		puts("");
	}
}