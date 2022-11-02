#include<bits/stdc++.h>
using namespace std;
#define N 2222
#define pc putchar

int n;
char s[N];

int main() {
    scanf("%d %s", &n, s);
    if (n & 1) {
        for (int i = n - 2; i > 0; i -= 2) pc(s[i]);
        pc(s[0]);
        for (int i = 2; i < n; i += 2) pc(s[i]);
        puts("");
    }
    else {
        for (int i = n - 2; i >= 0; i -= 2) pc(s[i]);
        for (int i = 1; i < n; i += 2) pc(s[i]);
        puts("");
    }

    return 0;
}