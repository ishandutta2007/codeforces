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

int num[4][3];

pii pos(int x)
{
    if (!x) return mp(3, 1);
    --x;
    return mp(x / 3, x % 3);
}

int n;
string s;
pii po[9], ve[9];
int cnt;

int main() {
    rep(i, 4) rep(j, 3) num[i][j] = -1;
    rep(i, 3) rep(j, 3) num[i][j] = i * 3 + j + 1;
    num[3][1] = 0;

    cin >> n >> s;

    if (n == 1) {
	puts("NO");
	return 0;
    }

    rep(i, n) po[i] = pos(s[i] - '0');
    rep(i, n - 1) ve[i] = mp(po[i + 1].fi - po[i].fi, po[i + 1].se - po[i].se); 

    rep(i, 10) {
	int x, y;
	x = pos(i).fi;
	y = pos(i).se;

	bool ok = 1;

	rep(j, n - 1) {
	    x = x + ve[j].fi;
	    y = y + ve[j].se;

	    if (x < 0 || x > 3 || y < 0 || y > 2) {
		ok = 0;
		break;
	    }

	    if (num[x][y] == -1) {
		ok = 0;
		break;
	    }
	}

	cnt += ok;
    }

    puts(cnt == 1 ? "YES" : "NO");

    return 0;
}