#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define ll long long

using namespace std;

const int N = 100500;

int main() {
    int tcase;
    scanf("%d", &tcase);
    while (tcase--) {
        int n;
        scanf("%d", &n);
        int r1, r2, r3, c1, c2, c3;
        int x, y;
        scanf("%d%d%d%d%d%d", &r1, &c1, &r2, &c2, &r3, &c3);
        scanf("%d%d", &x, &y);
        int r, c;
        if (r1 == r2) r = r1;
        else if (r1 == r3) r = r1;
        else r = r2;

        if (c1 == c2) c = c1;
        else if (c1 == c3) c = c1;
        else c = c2;

        if (r == 1 && c == 1) {
            if (x == 1 || y == 1) printf("YES\n");
            else printf("NO\n");
        }
        else if (r == 1 && c == n) {
            if (x == 1 || y == n) printf("YES\n");
            else printf("NO\n");
        }
        else if (r == n && c == 1) {
            if (x == n || y == 1) printf("YES\n");
            else printf("NO\n");
        }
        else if (r == n && c == n) {
            if (x == n || y == n) printf("YES\n");
            else printf("NO\n");
        }
        else {
            if ((r - x) % 2 == 0 || (c - y) % 2 == 0) printf("YES\n");
            else printf("NO\n");
        }
    }

    return 0;
}