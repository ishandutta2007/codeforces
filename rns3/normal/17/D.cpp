#include <bits/stdc++.h>
using namespace std;
#define M 1001001
typedef long long ll;

char s[M], t[M];
int mod;

int main() {
    //freopen("17D1.in", "r", stdin);
    scanf("%s %s %d", s, t, &mod);
    int x = 0;
    for (int i = 0; s[i]; i++) {
        x = (1ll * x * 10 + s[i] - '0') % mod;
    }

    int nt = strlen(t);
    for (int i = nt - 1; i >= 0; i--) {
        if (t[i] > '0') {
            t[i]--;
            break;
        } else {
            t[i] = '9';
        }
    }

    int P[11];
    int answer = (x + mod - 1) % mod;
    for (int i = nt - 1; i >= 0; i--) {
        P[0] = 1;
        for (int j = 1; j <= 10; j++) {
            P[j] = 1ll * P[j-1] * x % mod;
        }
        answer = 1ll * answer * P[t[i]-'0'] % mod;
        x = P[10];
    }
    if (!answer) {
        answer = mod;
    }
    printf("%d\n", answer);
    return 0;
}