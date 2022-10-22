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

int n, k;
int a[300010];
int ac[300010];
int u[300010];

bool ok(int x)
{
    for (int i = 0; i <= n - x; ++i) {
	int ns = x - (ac[i + x] - ac[i]);
	if (ns <= k) {
	    rep(j, n) u[j] = a[j];
	    for (int j = i; j < i + x; ++j) u[j] = 1;
	    return true;
	}
    }
    return false;
}

int main() {
    cin >> n >> k;
    rep(i, n) {
	cin >> a[i];
	ac[i + 1] = ac[i] + a[i];
    }

    int lo = 0, hi = n;
    if (ok(hi)) lo = n;

    while (hi - lo > 1) {
	int m = (hi + lo) / 2;
	if (ok(m)) lo = m;
	else hi = m;
    }

    cout << lo << endl;
    rep(i, n) cout << u[i] << (i == n - 1 ? '\n' : ' ');

    return 0;
}