#include <bits/stdc++.h>
using namespace std;

#define N 505
#define K 26

int n;
char s[N];
int a[N];

int main() {
    gets(s), n = strlen(s);
    for (int i = 0; i < K; i ++) a[i] = n;
    for (int i = n - 1; i >= 0; i --) {
        a[s[i]-'a'] = i;
    }
    for (int i = 0; i < K - 1; i ++) {
        if (a[i] > a[i+1]) return puts("NO"), 0;
    }
    return puts("YES"), 0;
}