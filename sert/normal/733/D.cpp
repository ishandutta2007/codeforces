#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.3
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;

const int N = 1e6 + 34;

map <pair<int, int>, pair<int, int> > m;
int r = -1, cur;
int n1, n2 = 0;
pair <int, int> z;

int m3(int a1, int a2, int a3) {
    return min(min(a1, a2), a3);
}

int main() {
    init();

    int n, a, b, c;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &a, &b, &c);
        if (a > b) swap(a, b);
        if (a > c) swap(a, c);
        if (b > c) swap(b, c);

        z = m[{a, b}];
        cur = m3(a, b, z.first + c);
        if (cur > r) {
            r = cur;
            n1 = i + 1;
            n2 = z.second;
        }
        if (c > z.first) z = {c, i + 1};
        m[{a, b}] = z;

        z = m[{a, c}];
        cur = m3(a, c, b + z.first);
        if (cur > r) {
            r = cur;
            n1 = i + 1;
            n2 = z.second;
        }
        if (c > z.first) z = {b, i + 1};
        m[{a, c}] = z;

        z = m[{b, c}];
        cur = m3(b, c, a + z.first);
        if (cur > r) {
            r = cur;
            n1 = i + 1;
            n2 = z.second;
        }
        if (a > z.first) z = {a, i + 1};
        m[{b, c}] = z;

    }

    cout << !!n1 + !!n2 << "\n" << n1;
    if (n2) cout << " " << n2;

    return 0;
}