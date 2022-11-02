#include <bits/stdc++.h>
using namespace std;

#define N 100005

const int INF = 1e9;

template <class T> void chkmax(T &a, T b) { if (a < b) a = b; }
template <class T> void chkmin(T &a, T b) { if (a > b) a = b; }

int n;
int a[N], mx[N], mn[N];
char b[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for (int i = 5; i <= n; i ++) {
        mx[i] = mn[i] = a[i];
        for (int j = 1; j <= 4; j ++) {
            chkmax(mx[i], a[i-j]);
            chkmin(mn[i], a[i-j]);
        }
    }
    scanf("%s", b + 1);
    int mxl = INF, mnl = -INF, mxr = INF, mnr = -INF;
    for (int i = 5; i <= n; i ++) {
        if (b[i-1] == b[i-2] && b[i-1] == b[i-3] && b[i-1] == b[i-4]) {
            if (b[i-1] == '0') {
                if (b[i] == '0') chkmin(mxl, mx[i]);
                else chkmax(mnl, mx[i] + 1);
            }
            else {
                if (b[i] == '0') chkmin(mxr, mn[i] - 1);
                else chkmax(mnr, mn[i]);
            }
        }
        else {
//            if (b[i] == b[i-1]) {
//
//            }
        }
    }
    printf("%d %d\n", mnl, mxr);
	return 0;
}