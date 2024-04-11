#include <bits/stdc++.h>
using namespace std;

#define N 11

char s[N], t[N];

set <string> S;

int main() {
    int n;
    scanf("%d", &n);
    while (n --) {
        scanf("%s %s", s, t);
        strcat(s, "&");
        strcat(s, t);
        S.insert(s);
    }
    printf("%d\n", (int)S.size());

    return 0;
}