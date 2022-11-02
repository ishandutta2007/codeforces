#include <bits/stdc++.h>
using namespace std;

#define N 1010

int n, ans[N];
char s[N];

int main() {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    for (int i = 1; i <= n; i ++) s[i] -= 'a';
    int x = 1;
    for (int i = n; i; i --) {
        if (s[i] == x) ans[i] = 0;
        else {
            ans[i] = 1, x ^= 1;
        }
    }
    for (int i = 1; i <= n; i ++) printf("%d ", ans[i]);
}