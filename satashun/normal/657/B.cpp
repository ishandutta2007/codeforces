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

const ll INF = 1LL << 60;

int n, k;
int ret;
int a[200010];
ll lo[200010], hi[200010];

int main() {
    cin >> n >> k;
    for (int i = 0; i <= n; ++i) cin >> a[i];

    ll cur = 0;

    for (int i = 0; i <= n; ++i) {
	if (abs(cur) & 1) {
	    for (int j = i; j <= n; ++j) lo[j] = INF;
	    break;
	}

	cur /= 2;
	cur += a[i];
	lo[i] = cur;
    }

    cur = 0;
    for (int i = n; i >= 0; --i) {
	cur = cur * 2;
	hi[i] = cur;

	cur = cur + a[i];

	if (abs(cur) >= INF) {
	    for (int j = i; j >= 0; --j) hi[j] = INF;
	    break;
	}
    }

    for (int i = 0; i  <= n; ++i) {
	if (hi[i] == INF || lo[i] == INF) continue;

	ll c = lo[i] + hi[i];
	ll na = a[i] - c;
	//cout << i << " " << na << endl;

	if (abs(na) <= k && c != 0 && !(i == n && na == 0)) {
	    ++ret;
	}
    }
    cout << ret << endl;

    return 0;
}