#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
using namespace std;

int n;
inline int LowBit(int x) {return x & -x;}
struct BIT {
	int c[100005];
	void Update(int i, int x) {
		for (int j = i;j <= n;j += LowBit(j)) c[j] += x;
	}
	int Query(int i) {
		int ans = 0;
		for (int j = i;j >= 1;j -= LowBit(j)) ans += c[j];
		return ans;
	}
};
BIT b[26];
string s;

void Read() {
	cin >> s;
	n = s.length();
}

void Solve() {
	for (int i = 0;i < n;i++) {
		b[s[i] - 'a'].Update(i + 1, 1);
	}
	int q;
	scanf("%d", &q);
	while (q--) {
		int op;
		scanf("%d", &op);
		if (op == 1) {
			int pos;
			char c;
			cin >> pos >> c;
			b[s[pos - 1] - 'a'].Update(pos, -1);
			b[c - 'a'].Update(pos, 1);
			s[pos - 1] = c;
		} else {
			int l, r;
			scanf("%d%d", &l, &r);
			int sum = 0;
			for (int i = 0;i < 26;i++) {
				if (b[i].Query(r) - b[i].Query(l - 1) > 0) sum++;
			}
			printf("%d\n", sum);
		}
	}
}

int main() {
	Read();
	Solve();
	return 0;
}