#include <bits/stdc++.h>
using namespace std;
#define TASKNAME "dynasties"
void init() {
#ifdef MOI_KOD_IDEALEN
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen(TASKNAME".in", "r", stdin);
    //freopen(TASKNAME".out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;

const int N = (int)1e6 + 34;

int n, m;
string s[100];
int b1[100], b2[100], b3[100];

int main() {
    init();

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        b1[i] = b2[i] = b3[i] = 100500;
    }
    int ans = 100500;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ('a' <= s[i][j] && s[i][j] <= 'z') b1[i] = min(b1[i], min(j, m - j));
            if ('0' <= s[i][j] && s[i][j] <= '9') b2[i] = min(b2[i], min(j, m - j));
            if (s[i][j] == '*' || s[i][j] == '#' || s[i][j] == '&') b3[i] = min(b3[i], min(j, m - j));
        }
    }

    for (int a1 = 0; a1 < n; a1++)
    for (int a2 = 0; a2 < n; a2++)
    for (int a3 = 0; a3 < n; a3++) {
        if (a1 == a2 || a1 == a3 || a2 == a3) continue;
        ans = min(ans, b1[a1] + b2[a2] + b3[a3]);
    }
    cout << ans;
    return 0;
}