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
int a, b, c, d;
int u[1010], v[1010];

int main() {
    cin >> n >> k;
    cin >> a >> b >> c >> d;

    if (k <= n || n == 4) {
	puts("-1");
	return 0;
    }

    if (n >= 5) {
	u[0] = a;
	u[1] = c;
	u[n - 2] = d;
	int now = 1;

	for (int i = 2; i < n - 2; ++i) {
	    while (now == a || now == b || now == c || now == d) ++now;
	    u[i] = now++;
	}
	u[n - 1] = b;

	int j = 1;

	rep(i, n) {
	    v[i] = u[j];

	    if (j == 1) j = 0;
	    else if (j == 0) j = 2;
	    else if (j == n - 3) j = n - 1;
	    else if (j == n - 1) j = n - 2;
	    else ++j;
	}

	rep(i, n) cout << u[i] << (i == n - 1 ? '\n' : ' ');
	rep(i, n) cout << v[i] << (i == n - 1 ? '\n' : ' ');
    }

    return 0;
}