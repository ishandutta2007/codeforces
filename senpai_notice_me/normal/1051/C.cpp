#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e2 + 5;

int n, a[MAXN], cnt[MAXN];

char belong[MAXN];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        cnt[a[i]] += 1;
    }
    
    int t = 0;
    for (int i = 1; i <= 100; ++i)
        if (cnt[i] == 1) ++t;
    
    int spec = 0;
    for (int i = 1; i <= 100; ++i)
        if (cnt[i] > 2) {
            spec = i; break;
        }
    
    if (!spec && (t & 1)) {
        puts("NO");
    } else {
        puts("YES");
        
        int half = (t + 1) / 2;
        bool fir = 1;
        for (int i = 1, j = 0; i <= n; ++i) {
            if (cnt[a[i]] == 1) {
                if (j < half) {
                    belong[i] = 'A';
                    ++j;
                } else {
                    belong[i] = 'B';
                }
            } else if (a[i] == spec && (t & 1) && fir) {
                belong[i] = 'B';
                fir = 0;
            } else {
                belong[i] = 'A';
            }
        }
        
        for (int i = 1; i <= n; ++i)
            putchar(belong[i]);
        putchar('\n');
    }
    
    return 0;
}