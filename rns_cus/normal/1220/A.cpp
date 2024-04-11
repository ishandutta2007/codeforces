#include <bits/stdc++.h>
using namespace std;

#define N 200200

int n;
char s[N];

int main() {
    scanf("%d %s", &n, s);
    int zero = 0, one = 0;
    for (int i = 0; i < n; i ++) if (s[i] == 'n') one ++;
    for (int i = 0; i < n; i ++) if (s[i] == 'z') zero ++;
    while (one --) printf("1 ");
    while (zero --) printf("0 ");

    return 0;
}