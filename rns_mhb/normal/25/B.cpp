#include <bits/stdc++.h>
using namespace std;

#define N 105

int n;
char s[N];

int main() {
    scanf("%d\n", &n);
    gets(s);
    if (n < 4) puts(s);
    else {
        if (n & 1) {
            for (int i = 0; i < n - 3; i += 2) printf("%c%c-", s[i], s[i+1]);
            printf("%c%c%c", s[n-3], s[n-2], s[n-1]);
        }
        else {
            for (int i = 0; i < n - 2; i += 2) printf("%c%c-", s[i], s[i+1]);
            printf("%c%c", s[n-2], s[n-1]);
        }
    }
}