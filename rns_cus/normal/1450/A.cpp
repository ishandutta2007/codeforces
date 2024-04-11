#include <bits/stdc++.h>
using namespace std;

#define N 222

int n;
char s[N];

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d %s", &n, s);
        sort(s, s + n);
        puts(s);
    }



    return 0;
}