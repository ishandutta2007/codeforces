#include <bits/stdc++.h>
using namespace std;

int n, ans, x, y, xx, yy, u, v, uu, vv;

int ask(int x, int y, int xx, int yy) {
	if (x > xx || y > yy) return 0;
	printf("? %d %d %d %d\n", x, y, xx, yy);
	fflush(stdout);
    scanf("%d", &ans);
    return ans;
}

void solve(int &x, int &y, int &xx, int &yy) {
    int st, en, mid;
    st = x - 1, en = xx;
    while (st < en - 1) {
        mid = (st + en) / 2;
        if (ask(x, y, mid, yy)) en = mid;
        else st = mid;
	}
	xx = en;
	st = x, en = xx + 1;
	while (st < en - 1) {
		mid = (st + en) / 2;
		if (ask(mid, y, xx, yy)) st = mid;
		else en = mid;
	}
    x = st;
    st = y - 1, en = yy;
    while (st < en - 1) {
		mid = (st + en) / 2;
		if (ask(x, y, xx, mid)) en = mid;
		else st = mid;
    }
    yy = en;
    st = y, en = yy + 1;
    while (st < en - 1) {
		mid = (st + en) / 2;
		if (ask(x, mid, xx, yy)) st = mid;
		else en = mid;
    }
    y = st;
}

int main() {
	scanf("%d", &n);
	x = y = 1, xx = yy = n;
	solve(x, y, xx, yy);//printf("%d %d %d %d\n", x, y, xx, yy);
    if (ask(1, 1, xx - 1, n)) u = 1, v = 1, uu = xx - 1, vv = n;
    else if (ask(1, 1, n, yy - 1)) u = 1, v = 1, uu = n, vv = yy - 1;
    else if (ask(x + 1, 1, n, n)) u = x + 1, v = 1, uu = n, vv = n;
    else u = 1, v = y + 1, uu = n, vv = n;
    solve(u, v, uu, vv);
    printf("! %d %d %d %d %d %d %d %d\n", x, y, xx, yy, u, v, uu, vv);
	return 0;
}