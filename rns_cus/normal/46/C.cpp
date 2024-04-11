#include <bits/stdc++.h>
using namespace std;

#define N 2010

int n;
char s[N];

int main() {
//    freopen("1.in", "r", stdin);
    scanf("%d %s", &n, s);
    int p = 0;
    for (int i = 0; i < n; i ++) {
        s[i+n] = s[i];
        if (s[i] == 'H') p ++;
    }
    int ans = n;
    for (int k = 0; k < n; k ++) {
        int dif = 0;
        for (int i = 0; i < n; i ++) {
            char c;
            if (i < p) c = 'H';
            else c = 'T';
            if (s[i+k] != c) dif ++;
        }
        ans = min(ans, dif / 2);
        dif = 0;
        for (int i = 0; i < n; i ++) {
            char c;
            if (i < n - p) c = 'T';
            else c = 'H';
            if (s[i+k] != c) dif ++;
        }

    }
    printf("%d\n", ans);
}