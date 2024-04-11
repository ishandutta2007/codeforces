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
int a[200010], b[200010], c[200010], d[200010];
int pos;

int main() {
    cin >> n;
    rep(i, n) {
	cin >> a[i];
	if (a[i] == 1) pos = i;
    }

    int now = 0;
    for (int i = pos; i < n; ++i) if (a[i]) c[now++] = a[i];
    rep(i, pos) if (a[i]) c[now++] = a[i];

    now = 0;
    rep(i, n) {
	cin >> b[i];
	if (b[i] == 1) pos = i;
    }

    now = 0;
    for (int i = pos; i < n; ++i) if (b[i]) d[now++] = b[i];
    rep(i, pos) if (b[i]) d[now++] = b[i];

    rep(i, n - 1) {
	if (c[i] != d[i]) {
	    puts("NO");
	    return 0;
	}
    }
    puts("YES");
    return 0;
}