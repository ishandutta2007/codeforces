#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>

#define ff first
#define ss second

using namespace std;

typedef int ll;
const int N = 1e6 + 7;

ll a[N];
ll n, m, k, t, p, ans;
bool u[N], ok;
char s[1234][1234];
int kol;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%s", s[i]);

    for (int j = 0; j < m; j++) {
        ok = true;

        //cerr << j << " " << m << " " << kol << "\n";

        for (int i = 0; i < n - 1 && ok; i++) {
            if (!u[i] && s[i][j] > s[i + 1][j]) {
                ans++;
                ok = false;
            }
        }

        if (ok)
            for (int i = 0; i < n - 1; i++)
                if (!u[i] && s[i][j] < s[i + 1][j]) {
                    kol++;
                    u[i] = true;
                }

        //cerr << "kol " << kol << "\n";

    }

    printf("%d", ans);

    return 0;
}