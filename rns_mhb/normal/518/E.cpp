#include <bits/stdc++.h>
using namespace std;
#define f0(i, a, b) for (int i = a; i < b; i ++)
#define f1(i, a, b) for (int i = a; i <= b; i ++)

#define N 100005

const int inf = 0x3f3f3f3f;

int n, k, c[N], d[N], ds;
bool vis[N];
char s[20];

bool func(int a, int b, int id, int g) {
    if (b - a <= g) return 1;
    if (b <= 0) {
        f0(i, 0, g) {
            c[id] = b - g + i;
            id += k;
        }
    }
    else if (a >= 0) {
        f0(i, 0, g) {
			c[id] = a + i + 1;
            id += k;
        }
    }
    else if (g) {
        ds = 0; d[ds ++] = 0; g --;
        int x = 1;
        while (g) {
            if (x > 0) {
                if (x < b) d[ds ++] = x, g --;
                x = -x;
            }
            else {
				if (x > a) d[ds ++] = x, g --;
                x = -x + 1;
            }
        }
        sort(d, d + ds);
        f0(i, 0, ds) c[id] = d[i], id += k;
    }
    return 0;
}

int main() {
	scanf("%d %d", &n, &k);
    f1(i, 1, n) {
        scanf("%s", s);
		if (s[0] == '?') vis[i] = 1;
        else c[i] = atoi(s);
    }
    bool flag = 0;
    f1(i, 1, k) {
        int prv = -inf, id = -1, g = 0;
        for (int j = i; j <= n && !flag; j += k) {
            if (!vis[j]) {
                flag = func(prv, c[j], id, g);
                g = 0; id = -1; prv = c[j];
            }
            else {
                g ++;
                if (id < 0) id = j;
            }
        }
        if (!flag && g) flag = func(prv, inf, id, g);
        if (flag) break;
    }
    if (flag) puts("Incorrect sequence");
    else f1(i, 1, n) printf("%d ", c[i]);

	return 0;
}