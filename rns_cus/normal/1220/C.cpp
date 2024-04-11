#include <bits/stdc++.h>
using namespace std;

#define N 500200

char s[N];

int main() {
    scanf("%s", s);
    int n = strlen(s);
    int mn = 300;
    for (int i = 0; i < n; i ++) {
        int c = s[i];
        if (mn < c) puts("Ann");
        else puts("Mike");
        mn = min(mn, c);
    }

    return 0;
}