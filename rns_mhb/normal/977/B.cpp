#include <bits/stdc++.h>
using namespace std;

#define N 105

int n, a[700];
char s[N];

int main() {
    scanf("%d\n", &n);
    gets(s);
    for (int i = 0; i < n - 1; i ++) a[26 * (s[i] - 'A') + s[i+1] - 'A'] ++;
    int p = max_element(a, a + 700) - a;
    printf("%c%c", p / 26 + 'A', p % 26 + 'A');
}