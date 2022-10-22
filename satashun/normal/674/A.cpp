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
int c[5010];
int cnt[5010];
int res[5010];

int main() {
    cin >> n;
    rep(i, n) cin >> c[i];

    rep(i, n) {
	memset(cnt, 0, sizeof(cnt));

	int idx = -1, ma = -1;

	for (int j = i; j < n; ++j) {
	    ++cnt[c[j]];

	    if (cnt[c[j]] > ma || (cnt[c[j]] == ma && c[j] < idx)) {
		ma = cnt[c[j]];
		idx = c[j];
	    }

	    ++res[idx];
	}
    }

    rep(i, n) cout << res[i + 1] << (i == n - 1 ? '\n' : ' ');

    return 0;
}