#include <bits/stdc++.h>
using namespace std;

#define N 100
#define INF 2000000000000000000

typedef long long ll;
int n, l;
char k[N];
long double dp[N], e[N];
int len[N];

int main() {
    scanf("%d ", &n);
    gets(k);
    l = strlen(k);
    if (l == 1 && k[0] == '0') {
        printf("0\n");
        return 0;
    }
    e[0] = 1;
    for (int i = 1; i <= 80; i ++) {
        e[i] = e[i-1] * n;
    }
    for (int i = l - 1; i >= 0; i --) {
        long double now = 0;
        dp[i] = INF;
        for (int j = i; j <= l - 1; j ++) {
            now = now * 10 + k[j] - '0';
            if (now >= n - 1e-8) break;
            if (k[i] == '0' && j > i) break;
            if (dp[j+1] + now * e[len[j+1]] < dp[i] - 1e-8) {
                dp[i] = dp[j+1] + now * e[len[j+1]];
                len[i] = len[j+1] + 1;
            }
        }
    }
//    cout<<len[1]<<endl;
    printf("%I64d\n", (long long) dp[0]);
}