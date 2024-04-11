#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

int main() {
//	freopen("in.txt", "r", stdin);
	int t, k, n, mk, cnt[26], i, j, minm, r, sum, num;
	string s1, s2;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		cin >> s1;
		s2 = s1;
		if (n % k)
			cout << -1 << endl;
		else {
			memset(cnt, 0, sizeof(cnt));
			sum = 0;
			num = 0;
			for (i = 0; i < n; ++i) {
				r = n - i;
				if (s1[i] != 'z') {
					if (r + sum >= (num + 1) * k)
						mk = i;
					else if (r + sum >= num * k) {
						for (j = s1[i] - 'a' + 1; j < 26; ++j) {
							if (cnt[j] % k) {
								mk = i;
								break;
							}
						}
					}
				}
				++cnt[s1[i] - 'a'];
				++sum;
				if (cnt[s1[i] - 'a'] % k == 1) {
					++num;
				}
				if (cnt[s1[i] - 'a'] % k == 0) {
					sum -= k;
					--num;
				}
			}
			if (!sum) {
				cout << s2 << endl;
			} else {
				memset(cnt, 0, sizeof(cnt));
				sum = 0;
				num = 0;
				for (i = 0; i < mk; ++i) {
					++cnt[s1[i] - 'a'];
					++sum;
					if (cnt[s1[i] - 'a'] % k == 1) {
						++num;
					}
					if (cnt[s1[i] - 'a'] % k == 0) {
						sum -= k;
						--num;
					}
				}
				if (r = n - mk, r + sum >= (num + 1) * k) {
					++s2[mk];
					++cnt[s2[mk] - 'a'];
				} else {
					bool f = true;
					++s2[mk];
					while (cnt[s2[mk] - 'a'] % k == 0) {
						++s2[mk];
						if (s2[mk] > 'z') {
							s2[mk] = s1[mk] + 1;
							++cnt[s2[mk] - 'a'];
							f = false;
							break;
						}
					}
					if (f)
						++cnt[s2[mk] - 'a'];
				}
				j = 0;
				for (i = mk + 1; i < n; ++i) {
					while (cnt[j] % k == 0)
						++j;
					if (j >= 26)
						break;
					s2[i] = 'a' + j;
					++cnt[j];
				}
				for (i; i < n; ++i) {
					s2[i] = 'a';
				}
				sort(s2.begin() + mk + 1, s2.end());
				cout << s2 << endl;
			}
		}
	}
	return 0;
}