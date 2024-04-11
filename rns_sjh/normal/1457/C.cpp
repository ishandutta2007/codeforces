#include<bits/stdc++.h>
using namespace std;

#define N 100010

int t, n, p, k, x, y;
char s[N];
string v;

int main() {
    for(scanf("%d", &t); t --; ) {
        scanf("%d%d%d", &n, &p, &k);
        scanf("%s", s);
        scanf("%d%d", &x, &y);
        int ans = 1 << 30;
        for(int i = p - 1; i < n && i < p + k - 1; i ++) {
            v.clear();
            for(int j = i; j < n; j += k) v.push_back(s[j]);
            int zero = 0;
            for(int j = v.size() - 1; j >= 0; j --) {
                if(v[j] == '0') zero ++;
                int a = zero * x + y * (i + j * k + 1 - p);
                ans = min(a, ans);
            }
        }
        printf("%d\n", ans);
    }
}