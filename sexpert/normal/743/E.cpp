#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;
int a[MAXN], n, dp[MAXN][256][9], moven[MAXN], movex[MAXN];

bool check(int k) {
    if(k == 0) return true;
    vector<int> p(8);
    iota(p.begin(), p.end(), 1);
    do {
        int req = 0, pt = 0;
        for(int i = 1; i <= n; i++) {
            if(a[i] == p[pt])
                req++;
            if(req == k) {
                req = 0;
                pt++;
            }
            if(pt == 8)
                return true;
        }
    } while(next_permutation(p.begin(), p.end()));
    return false;
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    int lo = 0, hi = 125;
    while(lo < hi) {
        int mi = (lo + hi + 1)/2;
        if(check(mi))
            lo = mi;
        else
            hi = mi - 1;
    }
    int k = lo;
    if(k == 0) {
        vector<int> pres(8);
        for(int i = 1; i <= n; i++)
            pres[a[i] - 1] = 1;
        int ans = accumulate(pres.begin(), pres.end(), 0);
        cout << ans << endl;
        return 0;
    }
    for(int i = n; i > 0; i--) {
        int ct = 0;
        for(int j = i; j > 0; j--) {
            if(a[j] == a[i])
                ct++;
            if(ct == k && moven[i] == 0)
                moven[i] = j;
            if(ct == k + 1 && movex[i] == 0)
                movex[i] = j;
        }
    }
    dp[0][0][0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int bm = 0; bm < 256; bm++) {
            for(int sc = 0; sc <= 8; sc++) {
                dp[i][bm][sc] = dp[i - 1][bm][sc];
                if(moven[i] > 0 && (bm & (1 << (a[i] - 1))))
                    dp[i][bm][sc] = max(dp[i][bm][sc], dp[moven[i] - 1][bm ^ (1 << (a[i] - 1))][sc]);
                if(movex[i] > 0 && sc > 0 && (bm & (1 << (a[i] - 1))))
                    dp[i][bm][sc] = max(dp[i][bm][sc], dp[movex[i] - 1][bm ^ (1 << (a[i] - 1))][sc - 1]);
            }
        }
    }
    int ans = 8*k;
    for(int sc = 0; sc <= 8; sc++)
        if(dp[n][255][sc])
            ans = 8*k + sc;
    cout << ans << endl;
}