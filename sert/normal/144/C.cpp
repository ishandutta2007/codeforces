#include <cstdio>
#include <cstring>

const int N = 1e5 + 34;

char s[N], k[N];
int n, m, ans;
int a[100], b[100];
bool ok;

int main() {
    ///freopen("a.in", "r", stdin);
    scanf("%s%s", s, k);
    n = strlen(s);
    m = strlen(k);
    for (int i = 0; i < m; i++)
        b[k[i] - 'a']++;
    for (int i = 0; i < n - m + 1; i++) {
        if (i == 0) {
            for (int j = i; j < i + m; j++)
                if (s[j] != '?')
                    a[s[j] - 'a']++;
        } else {
            if (s[i - 1] != '?')
                a[s[i - 1] - 'a']--;
            if (s[i + m - 1] != '?')
                a[s[i + m - 1] - 'a']++;
        }
        ok = true;
        for (int j = 0; j < 26; j++)
            if (a[j] > b[j])
                ok = false;
        ans += ok;
    }
    printf("%d\n", ans);
}