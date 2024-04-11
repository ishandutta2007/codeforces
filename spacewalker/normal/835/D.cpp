#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

typedef long long ll;
using namespace std;

ll FMD(ll x, ll m) {
	return ((x % m) + m) % m;
}

class SubstringHash {
	int n;	
	int b, m;
	vector<ll> bPow, hashPref;
public:
	SubstringHash(string s, int base, int mod) : n(s.size()), b(base), m(mod) {
		bPow = hashPref = vector<ll>(n, 0);
		bPow[0] = 1;
		hashPref[0] = s[0];
		for (int i = 1; i < n; ++i) {
			bPow[i] = (bPow[i-1] * b) % m;
			hashPref[i] = (hashPref[i-1] * b + s[i]) % m;
		}
	}
	int getHash(int i, int j) {
		if (i == 0) {
			return hashPref[j];
		} else {
			return FMD(hashPref[j] - bPow[j-i+1]*hashPref[i-1], m);
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s; cin >> s;
	int n = s.size();
	SubstringHash h1(s, 43, 1000000007);
	SubstringHash h2(s, 43, 1000000009);
	reverse(s.begin(), s.end());
	SubstringHash h1rev(s, 43, 1000000007);
	SubstringHash h2rev(s, 43, 1000000009);
	reverse(s.begin(), s.end());
	vector<vector<int>> maxPC(n, vector<int>(n, -1));
	for (int i = 0; i < n; ++i) {
		maxPC[i][i] = 1;
	}
	for (int len = 2; len <= n; ++len) {
		for (int s = 0; s + len - 1 < n; ++s) {
			maxPC[s][s+len-1] = 0;
			int e = s+len-1;
			if (h1.getHash(s, e) == h1rev.getHash(n-1-e, n-1-s) && h2.getHash(s, e) == h2rev.getHash(n-1-e, n-1-s)) {
				int pEnd = s + len/2 - 1;
				int sStart = e - len/2 + 1;
				if (h1.getHash(s, pEnd) == h1.getHash(sStart, e) && h2.getHash(s, pEnd) == h2.getHash(sStart, e)) {
					maxPC[s][s+len-1] = min(maxPC[s][pEnd], maxPC[sStart][e]) + 1;
				} else {
					maxPC[s][s+len-1] = 1;
				}
			}
			//printf("string %d-%d is %d-palindrome\n", s, e, maxPC[s][s+len-1]);
			//printf("%d %d %d %d are the hashes\n", h1.getHash(s, e), h1rev.getHash(n-1-e, n-1-s), h2.getHash(s, e), h2rev.getHash(n-1-e, n-1-s));
		}
	}
	vector<int> ans(n+1, 0);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i; ++j) {
			++ans[maxPC[j][i]];
		}
	}
	for (int i = n - 2; i >= 0; --i) {
		ans[i] = ans[i] + ans[i+1];
	}
	for (int i = 1; i <= n; ++i) {
		printf("%s%d", (i == 1 ? "" : " "), ans[i]);
	}
	printf("\n");
	return 0;
}