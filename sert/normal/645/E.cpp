#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md = 1e9 + 7;
typedef long double ld;
const int N = 2e6 + 34;
char s[N];
ll p[N];
int n, k, m;
int lst[100];
int c, cur, mn;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    scanf("%d %d\n", &n, &k);
    gets(s);
    m = strlen(s);
    for (int i = 0; i < k; i++)
        lst[i] = -1;
    p[0] = 0;
    p[1] = 1;
    for (int i = 0; i < m; i++) {
        c = s[i] - 'a';
        cur = p[i + 1] - p[lst[c] + 1];
        p[i + 2] = (p[i + 1] + cur + md) % md;
        lst[c] = i;
    }
    //cout << p[m + 1];
    for (int i = m; i < m + n; i++) {
        mn = 0;
        for (int j = 1; j < k; j++)
            if (lst[j] < lst[mn])
                mn = j;
        c = mn;
        cur = p[i + 1] - p[lst[c] + 1];
        p[i + 2] = (p[i + 1] + cur + md) % md;
        lst[c] = i;
    }

    cout << p[n + m + 1];

    return 0;
}