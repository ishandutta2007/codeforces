#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

int n;
int h[1010], w[1010];
int ans = INT_MAX;

int main() {
	cin >> n;
	int d = 0; 

	rep(i, n) {
		cin >> w[i] >> h[i];
		d = max(d, min(h[i], w[i]));
	}

	for (int i = 1000; i >= d; --i) {
		int cnt = 0;
		int sum = 0;
		vector<int> vec;

		rep(j, n) {
			if (h[j] > i) {
				++cnt;
				sum += h[j];
			} else {
				if (h[j] - w[j] < 0 && i >= w[j]) {
					vec.pb(h[j] - w[j]);
				}
				sum += w[j];
			}
		}

		sort(ALL(vec));
		if (cnt > n/2) break;

		rep(j, vec.size()) {
			if (cnt == n/2) break;
			++cnt;
			sum += vec[j];
		}

		ans = min(ans, sum * i);
	}
	cout << ans << endl;

	return 0;
}