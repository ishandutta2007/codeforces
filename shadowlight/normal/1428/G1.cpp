#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int MAXN = 1e6 + 7;
const int T = 6;

int main(){
#ifdef LOCAL
	freopen("G_input.txt", "r", stdin);
	//freopen("G_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int k;
	cin >> k;

	vector <ll> res(MAXN, -1);
	vector <ll> f(T, 0);
	res[0] = 0;

	for (int i = 0; i < T; ++i) {
		cin >> f[i];
	}

	ll now = 1;

	vector <ll> vals(MAXN, 0);

	for (int j = 0; j < T; ++j) {
		int total = 3 * (k - 1);

		int mod = 3 * now;

		//cout << j << " " << mod << " " << f[j] << endl;

		for (int rem = 0; rem < mod; ++rem) {
			queue <pair <ll, int> > toDelete;
			set <pair <ll, int> > q;
			ll addq = 0;
			for (int i = rem; i < MAXN; i += mod) {
				ll was = res[i];
				//cout << j << " " << i << " " << was << " " << addq << " " << total <<  " " << toDelete.size() << endl;
				if (q.size()) {
					res[i] = max(res[i], q.rbegin()->x + addq);
				}
				if (was != -1) {
					q.insert({was - addq, i});
				}
				toDelete.push({was - addq, i});
				addq += f[j];
				if (toDelete.size() > total) {
					auto x = toDelete.front();
					toDelete.pop();
					q.erase(x);
				}
			}
		}

		now *= 10;
	}

	int q;
	cin >> q;

	for (int it = 0; it < q; ++it) {
		int sum;
		cin >> sum;
		ll now_res = 0;
		for (int i = 0; i <= sum; ++i) {
			ll cur = res[i];
			if (cur == -1) continue;
			//cout << i << " " << cur << endl;
			int rem = sum - i;
			for (int j = 0; j < T; ++j) {
				int x = rem % 10;
				rem /= 10;
				if (x % 3 == 0) {
					cur += (x / 3) * f[j]; 
				}
			}
			//cout << i << " " << res[i] << " " << cur << endl;
			now_res = max(now_res, cur);
		}
		cout << now_res << "\n";
	}

}