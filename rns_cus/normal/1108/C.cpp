#include <bits/stdc++.h>
using namespace std;

int n;
char s[200200];

char num[10];

int main() {
    scanf("%d %s", &n, s);
    char per[5] = "BGR", ans[5];
    int rlt = 1e9;
    do {
        int tmp = 0;
        for (int i = 0; i < n; i ++) {
            if (s[i] != per[i%3]) tmp ++;
        }
        if (rlt > tmp) rlt = tmp, strcpy(ans, per);
    } while (next_permutation(per, per + 3));
    for (int i = 0; i < n; i ++) s[i] = ans[i%3];
    printf("%d\n%s", rlt, s);
}