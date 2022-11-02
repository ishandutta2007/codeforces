#include <bits/stdc++.h>
using namespace std;

#define N 100005
#define K 26

int n, k;
char s[N];
int a[N], tot;

int main() {
    scanf("%d %d ", &n, &k);
    gets(s);
    for (int i = 0; i < n; i ++) {
        int c = s[i] - 'a';
        tot += max(c, K - 1 - c);
    }
    if (tot < k) {
        printf("-1\n");
        return 0;
    }
    for (int i = 0; i < n; i ++) {
        int c = s[i] - 'a';
        int d = max(c, K - 1 - c);
        if (d <= k) {
            k -= d;
            printf("%c", c > K - 1 - c ? 'a' : 'z');
        }
        else {
            printf("%c", c > K - 1 - c ? 'a' + c - k : 'a' + c + k);
            k = 0;
        }
    }
    return 0;
}