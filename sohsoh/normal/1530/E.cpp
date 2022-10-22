// Um_nlk :)))))
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

int cnt[MAXN], n;
string s;

inline void Clear() {
	for (char c = 'a'; c <= 'z'; c++) {
		while (cnt[c]) {
			cout << c;
			cnt[c]--;
		}
	}
}

inline int solve() {
	cin >> s;
	n = s.size();
	for (char c : s) cnt[c]++;	
	if (cnt[s.front()] == n) return cout << s << endl, 0;

	for (char c = 'a'; c <= 'z'; c++) {
		if (cnt[c] == 1) {
			s.erase(find(all(s), c));
			cout << c;
			sort(all(s));
			cout << s << endl;
			return 0;
		}
	}

	for (char c = 'a'; c <= 'z'; c++) {
		if (cnt[c]) {
			if (n - cnt[c] >= cnt[c] - 2) {
				char ind = c + 1;
				cout << c << c;
				cnt[c] -= 2;

				while (cnt[c]) {
					while (!cnt[ind]) ind++;
					cout << ind;
					cnt[ind]--;
					cout << c;
					cnt[c]--;
				}

				Clear();
				cout << endl;
			}  else {
				char c2 = c + 1;
				while (!cnt[c2]) c2++;	
				if (cnt[c2] + cnt[c] == n) {
					cout << c;
					cnt[c]--;
					while (cnt[c2]) {
						cout << c2;
						cnt[c2]--;
					}

					while (cnt[c]) {
						cout << c;
						cnt[c]--;
					}

					cout << endl;
				} else {
					char c3 = c2 + 1;
					while (!cnt[c3]) c3++;
					cout << c << c2;
					cnt[c]--;
					cnt[c2]--;

					while (cnt[c]) {
						cout << c;
						cnt[c]--;
					}

					cout << c3;
					cnt[c3]--;
					Clear();

					cout << endl;
				}
			}

			return 0;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		for (int i = 'a'; i <= 'z'; i++) cnt[i] = 0;
		solve();
	}
	return 0;
}