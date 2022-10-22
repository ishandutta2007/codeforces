#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;



int main(){
#ifdef LOCAL
	freopen("F_input.txt", "r", stdin);
	//freopen("F_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector <ll> h(n);
	for (int i = 0; i < n; ++i) {
		cin >> h[i];
	}

	if (n == 1) {
		cout << h[0] << " \n";
		return 0;
	}

	ll first = h[0];

	vector <ll> equals;

	ll d = (h[1] - h[0]) / 2;
	first += d;
	h[1] -= d, h[0] += d;
	if (h[0] == h[1]) {
		equals.pb(0);
	}

	for (int len = 1; len < n - 1; ++len) {
		/*cout << "CUR_LEN: " << len << "\n";
		cout << first << " " << equals.size() << "\n";
		for (int x : equals) {
			cout << x << " ";
		}
		cout << "\n";*/

		ll nxt = h[len + 1];
		ll last = first + (len - equals.size());
		while (equals.size() && nxt > last + 1) {
			ll d = equals.back();
			equals.pop_back();
			ll need = (len - d);
			//cout << nxt - last - 1 << " " << need << "\n";
			if (need <= (nxt - last - 1)) {
				nxt -= need;
				++last;
			} else {
				ll cur = (nxt - last - 1);
				nxt -= cur;
				d += cur;
				equals.pb(d);
				assert(d < len);
				break;
			}
		}
		//cout << "SZ: " << equals.size() << " " << last << " " << nxt << "\n";
		assert(nxt >= last);
		if (equals.size()) {
			if (nxt == last) {
				equals.pb(len);
			}
			continue;
		}
		ll step_len = len + 2;
		ll steps = (nxt - last) / step_len;
		nxt -= (len + 1) * steps;
		last += steps;
		assert(last <= nxt);

		first += steps;

		if (nxt - last > 1) {
			equals.pb(nxt - last - 2);
			++first;
		} else if (nxt == last) {
			equals.pb(len);
		}
	}

	cout << first << " ";
	int it = 0;
	for (int i = 1; i < n; ++i) {
		++first;
		while (it < (int) equals.size() && equals[it] < i) {
			--first;
			++it;
		}
		cout << first << " ";
	}
	cout << "\n";

}