#include <bits/stdc++.h>
using namespace std;

#define N 200005

int n;
char s[N];
bool a[N];

int main() {
    gets(s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i ++) {
        if (s[i] == s[i-1]) a[i] = a[i-1] ^ 1;
        else a[i] = 0;
    }
    for (int i = 1; i <= n; i ++) {
        if (a[i]) { 
            s[i] = 'a';
            while (s[i] == s[i-1] || s[i] == s[i+1]) s[i] += 1;
        }
        putchar(s[i]);
    }
    return 0;
}