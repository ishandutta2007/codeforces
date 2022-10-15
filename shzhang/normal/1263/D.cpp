#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <queue>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

#define ll long long

int uf[200500];
int cnt[200500];

int n;

int find(int a)
{
    if (uf[a] == a) return a;
    return uf[a] = find(uf[a]);
}

void un(int a, int b)
{
    a = find(a);
    b = find(b);
    uf[a] = b;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n + 26; i++) {
        uf[i] = i;
    }
    for (int i = 27; i <= 26 + n; i++) {
        char s[55];
        scanf("%s", s + 1);
        for (int j = 1; s[j]; j++) {
            un(i, s[j] - 'a' + 1);
        }
    }
    for (int i = 27; i <= 26 + n; i++) {
        cnt[find(i)]++;
    }
    int ans = 0;
    for (int i = 1; i <= n + 26; i++) {
        if (cnt[i]) ans++;
    }
    printf("%d", ans);
    return 0;
}