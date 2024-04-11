#include<bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int MAXN = 200005;
const int INF = 0x3f3f3f3f;

template <typename T> inline void read(T &WOW) {
	T x = 0, flag = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') flag = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	WOW = flag * x;
}

int n, a[MAXN], ans;

struct Node {
    int l, r, g;
    Node() {}
    Node(int _l, int _r, int _g): l(_l), r(_r), g(_g) {}
};
Node s[MAXN];
int top1, top2;

void solve() {
    read(n);
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
        if (a[i] == 1) {
            ++ans;
            top1 = 0;
        } else {
            for (int j = 1; j <= top1; ++j) {
                s[j].g = __gcd(s[j].g, a[i]);
            }
            s[++top1] = Node(i, i, a[i]);
            top2 = 1;
            for (int j = 2; j <= top1; ++j) {
                if (s[j].g == s[top2].g) {
                    s[top2].r = s[j].r;
                } else {
                    s[++top2] = s[j];
                }
            }
            top1 = top2;
            for (int j = 1; j <= top1; ++j) {
                if (i - s[j].r + 1 <= s[j].g && s[j].g <= i - s[j].l + 1) {
                    ++ans;
                    top1 = 0;
                    break;
                }
            }
        }
        printf("%d ", ans);
    }
}

int main() {
    solve();
    return 0;
}