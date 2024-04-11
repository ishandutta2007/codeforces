#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define ll long long

using namespace std;

const int N = 200500;
const int inf = 1e9 + 50;
const int mod = 998244353;

int main() {

    int tcase;
    scanf("%d", &tcase);
    while (tcase--) {
        int n, k;
        scanf("%d%d", &n, &k);
        int s = 0;
        for (int i = 0; i < n; i++) {
            int a;
            scanf("%d", &a);
            s |= a;
        }
        if (s) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}