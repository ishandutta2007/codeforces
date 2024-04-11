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
#define dump(x) cout << #x << " = " << (x) << endl

const int MN = 500010;
int cnt[MN][2];

int main() {
	int n; cin >> n;

	int c0 = 0;

	rep(i, n) {
		string s; cin >> s;
		int mini = 0;
		int sum = 0;

		rep(j, s.size()) {
			if (s[j] == '(') {
				++sum;
			} else {
				--sum;
			}
			mini = min(mini, sum);
		}
		if (sum == 0) {
			if (mini >= 0) {
				++c0;
			}
		} else if (sum > 0) {
			if (mini >= 0) {
				++cnt[sum][0];
			}
		} else {
			if (mini >= sum) {
				++cnt[-sum][1];
			}
		}
	}

	int ans = c0 / 2;

	for (int i = 1; i < MN; ++i) {
		ans += min(cnt[i][0], cnt[i][1]);
	}

	cout << ans << endl;

	return 0;
}