#include <bits/stdc++.h>
using namespace std;

#define N 200100

int n;
char s[N];

int main() {
    scanf("%d %s", &n, s);
    if (n & 1) puts("No");
    else {
        int sum = 0;
        for (int i = 0; i < n; i ++) {
            if (s[i] == '(') sum ++;
            else sum --;
            if (sum < -1) return puts("No"), 0;
        }
        if (sum == 0) puts("Yes");
        else puts("No");
    }

    return 0;
}