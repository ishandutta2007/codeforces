#include <bits/stdc++.h>

using namespace std;

#define int long long
#define fro for
#define pb push_back
#define ld long double
vector<int> pm1, pm2;
vector<int> h1 = {0}, h2 = {0}, h3 = {0}, h4 = {0};
int m1, m2, n;

pair<int, int> subs(int l, int r) {
    int x1 = (m1 + h1[r] - h1[l - 1] * pm1[r - l + 1] % m1) % m1;
    int x2 = (m2 + h2[r] - h2[l - 1] * pm2[r - l + 1] % m2) % m2;
    return {x1, x2};
}

pair<int, int> subt(int l, int r) {
    int f = h3[l - 1];
    int ff = pm1[r - l + 1];
    int s1 = (f * ff  % m1);
    int s2 = (h4[l - 1] * pm2[r - l + 1] % m2);
    int x1 = (m1 + h3[r] - s1) % m1;
    int x2 = (m2 + h4[r] - s2) % m2;
    return {x1, x2};
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int p1 = 37;
    int p2 = 41;
    m1 = 811713589;
    m2 = 998244853;
    int t;
    cin >> t;
    while (t--) {
        string s,s2;
        cin >> s2;
        s = '0' + s2;
        n = (int) s.size();
        pm1.resize(n+1);
        pm2.resize(n+1);
        fill(pm1.begin(), pm1.end(), 0);
        fill(pm1.begin(), pm1.end(), 0);
        h1 = {0};
        h2 = {0};
        h3 = {0};
        h4 = {0};
        string tt = "0";
        for (int y = n - 1; y >= 1; y--) {
            tt += s[y];
        }
        pm1[0] = 1;
        for (int i = 0; i < n; i++) {
            pm1[i + 1] = pm1[i] * p1 % m1;
        }
        pm2[0] = 1;
        for (int i = 0; i < n; i++) {
            pm2[i + 1] = pm2[i] * p2 % m2;
        }
        for (int i = 1; i <= n; i++) {
            h1.pb((h1.back() * p1 % m1 + s[i] - 'a'+1) % m1);
        }
        for (int i = 1; i <= n; i++) {
            h2.pb((h2.back() * p2 % m2 + s[i] - 'a'+1) % m2);
        }
        for (int i = 1; i <= n; i++) {
            h3.pb((h3.back() * p1 % m1 + tt[i] - 'a'+1) % m1);
        }
        for (int i = 1; i <= n; i++) {
            h4.pb((h4.back() * p2 % m2 + tt[i] - 'a'+1) % m2);
        }
        int i = 1;
        while ((2 * i <= n-1) && subs(1, i) == subt(1, i)) {
            i++;
        }
        if (i == (n + 1)/2) {
            cout << s2 << '\n';
        } else {
            int j = i - 1;
            for (int h = i; h <= n - i; h++) {
                if (subs(i, h) == subt(n - h, n - i)) {
                    j = h;
                }
            }
            int j2 = n - i + 1;
            for (int h = n - i; h >= i; h--) {
                if (subs(h, n - i) == subt(i, n - h)) {
                    j2 = h;
                }
            }
            if (j >= n - j2) {
                string ans;
                for (int p = 0; p < j; p++) {
                    ans += s2[p];
                }
                for (int h = n - i; h < n-1; h++) {
                    ans += s2[h];
                }
                cout << ans << '\n';
            } else {
                string ans;
                for (int p = 0; p < i - 1; p++) {
                    ans += s2[p];
                }
                for (int h = j2-1; h < n-1; h++) {
                    ans += s2[h];
                }
                cout << ans << '\n';
            }
        }
    }


}