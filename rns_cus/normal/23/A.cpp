#include <bits/stdc++.h>
using namespace std;

#define N 111

char s[N];

int main() {
    scanf("%s", s);
    int n = strlen(s);
    int ans = 0;
    for (int i = 0; i < n; i ++) for (int j = 0; j < i; j ++) {
        int k;
        for (k = 0; i + k < n; k ++) if (s[i+k] != s[j+k]) break;
        ans = max(ans, k);
    }
    printf("%d\n", ans);

    return 0;
}