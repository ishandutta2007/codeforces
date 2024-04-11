#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int N = 1e6 + 34;

int n, k, p[N], kol;
long long ans;
char s[N];

int main() {
    scanf("%d%s", &k, s);
    n = strlen(s);
    p[0] = 1;
    for (int i = 0; i < n; i++) {
        kol += (s[i] == '1');
        if (kol >= k)
            ans += p[kol - k];
        p[kol]++;
    }
    cout << ans;
    return 0;
}