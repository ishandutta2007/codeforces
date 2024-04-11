#include <bits/stdc++.h>
using namespace std;

#define N 105

int n;
char s[N];
int ans[5], r[6];

int main() {
    gets(s);
    n = strlen(s);
    for (int i = 0; i < n; i ++) {
        if (s[i] == 'R') r[0] = i % 4;
        if (s[i] == 'B') r[1] = i % 4;
        if (s[i] == 'Y') r[2] = i % 4;
        if (s[i] == 'G') r[3] = i % 4;
    }
    for (int i = 0; i < 4; i ++) {
        for (int j = 0; j < n; j ++) {
            if (j % 4 == r[i] && s[j] == '!') ans[i] ++;
        }
        printf("%d ", ans[i]);
    }
}