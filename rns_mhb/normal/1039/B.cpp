#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll Rand(ll L, ll R) {
    return L + rand() % (R-L+1);
}

int main() {
    srand(time(0));
    ll n;
    int k;
    char s[10];
    scanf("%I64d%d", &n, &k);
    ll L = 1, R = n;
    while(1) {
        if(R - L < 4 * (k+1)) {
            ll pos = Rand(L, R);
            printf("%I64d %I64d\n", pos, pos);
            fflush(stdout);
            scanf("%s", s);
            if(strcmp(s, "Yes") == 0) return 0;
            L = max(1ll, L - k);
            R = min(n, R + k);
        }
        else {
            ll mid = L + R >> 1;
            printf("%I64d %I64d\n", L, mid);
            fflush(stdout);
            scanf("%s", s);
            if(strcmp(s, "Yes") == 0) {
                L = max(1ll, L - k);
                R = min(n, mid + k);
            }
            else {
                L = max(1ll, mid + 1 - k);
                R = min(n, R + k);
            }
        }
    }
}