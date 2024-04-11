#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, ta, b, tb, h, m;
    scanf("%d %d %d %d", &a, &ta, &b, &tb);
    scanf("%d:%d", &h, &m);
    int dw = 300, up = 23 * 60 + 59;
    int now = h * 60 + m;
    int st = max(dw, now - tb + 1);
    int fs = min(up, now + ta - 1);
    st -= dw, fs -= dw;
    cerr << st << " " << fs << endl;
    int ans = fs / b;
    if (st == 0) ans ++;
    else ans -= (st - 1) / b;
    printf("%d\n", ans);
	return 0;
}