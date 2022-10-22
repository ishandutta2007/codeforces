#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int n;
string s;

ll res = 0;

void solve(int l, int r) {
	if (r - l == 1) {
		res += (s[l] == '1');
		return;
	}
	int mid = (l + r) / 2;
	solve(l, mid);
	solve(mid, r);

	//cout << l << " "  << r << "\n";
	//cout << "WAS: " << res << "\n";

	vector <int> suf(r - l, 0);
	bool prefix = true;
	int current = 0;
	int prefix_size = 0;
	for (int i = mid; i < r; ++i) {
		if (s[i] == '0') {
			if (prefix) {
				prefix_size = current;
			}
			current = 0;
			prefix = false;
		} else {
			++current;
		}
		if (!prefix) {
			suf[i - l] = max(suf[i - l - 1], current);
		} else {
			prefix_size = current;
		}		
	}
	int now = prefix_size + mid - l;

	bool suffix = true;
	int suffix_size = 0;

	vector <ll> suffix_sum(r - l + 1, 0);

	for (int i = r - l - 1; i >= now; --i) {
		suffix_sum[i] = suf[i] + suffix_sum[i + 1];
	}

	current = 0;

	for (int i = mid - 1; i >= l; --i) {
		if (s[i] == '0') {
			current = 0;
			suffix = false;
		} else {
			++current;
		}
		if (i != mid - 1 && !suffix) {
			suf[i - l] = max(suf[i - l + 1], current);
		}

		if (suffix) {
			suffix_size = current;
		}

		int vala = suf[i - l];
		int valb = suffix_size + prefix_size;

		if (valb <= vala) {
			res += prefix_size * (ll) vala;
		} else {
			int la, ra = prefix_size;
			if (suffix_size >= vala) {
				la = 0;
			} else {
				la = vala - suffix_size;
			}
			res += suffix_size * (ll) (ra - la);
			res += ra * (ll) (ra + 1) / 2 - la * (ll) (la + 1) / 2;
			res += la * (ll) vala;
		}

		int val = max(vala, valb);

		while (now < (int) suf.size() && suf[now] < val) {
			++now;
		}

		res += suffix_sum[now];
		int ra = mid + prefix_size - l;
		//cout << "RA NOW: " << ra << " " << now << endl;
		res += (now - ra) * (ll) val;
	}
	//cout << "NOW: " << res << "\n";
}

int main(){
#ifdef LOCAL
	freopen("F_input.txt", "r", stdin);
	//freopen("F_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	cin >> s;

	solve(0, n);
	cout << res << "\n";
}