#include <cstdio>
#include <algorithm>
#include <iostream>
#include <map>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

typedef int ll;
const ll N = 1e3 + 7;

string s;
ll n, a[N][N];
ll q, num, m, p[N], ans;

int main() {

    //freopen("a.in", "r", stdin);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    for (int i = 0; i < n; i++) {
        p[i] = a[i][i];
        ans = (ans + p[i]) % 2;
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        scanf("%d", &q);
        if (q == 3) {
            printf("%d", ans);
            continue;
        }
        scanf("%d", &num);
        ans = (ans + 1) % 2;

    }



    return 0;
}