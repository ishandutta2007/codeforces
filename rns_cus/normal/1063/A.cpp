#include <bits/stdc++.h>
using namespace std;

#define N 100100

char s[N];

int main() {
    int n;
    scanf("%d %s", &n, s);
    sort(s, s + n);
    printf("%s\n", s);

    return 0;
}