#include <bits/stdc++.h>
using namespace std;
const int N = 5000 + 4;
typedef long long ll;
typedef long double ld;

int n, m;
string s[N];
char ss[N];
int a[N], k[N];
int ans, p;

int main() {
    //freopen("a.in", "r", stdin);

    scanf("%d %d\n", &n, &m);
    for (int i = 0; i < n; i++) {
        gets(ss);
        s[i] = ss;
        s[i] += '0';
    }
    m++;

    for (int j = 0; j + 1 < m; j++) {
        for (int i = 0; i < n; i++) {
            if (a[i])
                a[i]--;
            else if (s[i][j] == '1') {
                p = j + 1;
                while (s[i][p] == '1')
                    p++;
                a[i] = p - j;
            }
            k[a[i]]++;
        }
        for (int i = N - 1; i >= 0; i--) {
            ans = max(ans, i * k[i]);
            if (i)
                k[i - 1] += k[i];
            k[i] = 0;
        }
    }

    cout << ans;

    return 0;
}