#include <bits/stdc++.h>
using namespace std;

#define N 111

char s[N];

int x[N], y[N];

bool check() {
    int n = strlen(s + 1);
    for (int i = 1; i <= n; i ++) {
        x[i] = x[i-1], y[i] = y[i-1];
        if (s[i] == 'L') x[i] --;
        else if (s[i] == 'R') x[i] ++;
        else if (s[i] == 'U') y[i] ++;
        else y[i] --;
        for (int j = 0; j < i - 1; j ++) if (abs(x[i] - x[j]) + abs(y[i] - y[j]) <= 1) return 0;
    }
    return 1;

}

int main() {
    scanf("%s", s + 1);
    puts(check() ? "OK" : "BUG");

    return 0;
}