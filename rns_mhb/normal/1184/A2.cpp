#include<bits/stdc++.h>
using namespace std;

#define N 200010

int ps, p[N], phi[N];

void ppm() {
    phi[1] = 1;
    for(int i = 2; i < N; i ++) {
        if(!phi[i]) p[++ps] = i, phi[i] = i - 1;
        for(int j = 1; j <= ps && i * p[j] < N; j ++) {
            int k = i * p[j];
            phi[k] = phi[i] * (p[j] - 1);
            if(i % p[j] == 0) {
                phi[k] = phi[i] * p[j];
                break;
            }
        }
    }
}

char s[N];

int main() {
    ppm();
    int n, ans = 0;
    scanf("%d%s", &n, s);
    for(int d = 1; d <= n; d ++) if(n % d == 0) {
        int x = 0;
        for(int i = 0; i < d; i ++) {
            for(int j = i; j < n; j += d) x ^= s[j]-'0';
            if(x == 1) break;
        }
        if(x == 1) continue;
        ans += phi[n/d];
    }
    cout << ans << endl;
}