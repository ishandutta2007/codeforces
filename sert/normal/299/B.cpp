#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef long long ll;
const ll N = 1e6 + 34;

ll n, k, kol;
char s[N];

int main() {
    ///freopen("a.in", "r", stdin);

    scanf("%d %d", &n, &k);
    scanf("%s", s);

    for (int i = 0; i < n; i++)
        if (s[i] == '#') {
            kol++;
            if (kol >= k) {
                printf("NO\n");
                return 0;
            }
        } else
            kol = 0;

    printf("YES\n");
    return 0;
}