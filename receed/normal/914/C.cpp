#include <cstdio>
#include <vector>   
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <iomanip>
#include <deque>
#include <queue>
#include <cstring>

using namespace std;

const int N = 1006;
int a[N], d[N], c[N][N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    int k, t, mod = 1e9 + 7, ss = 0;
    cin >> s >> k;
    int n = s.size();
    c[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= n; j++)
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
    }
    for (int i = 2; i <= n; i++) {
        t = 0;
        for (int j = i; j > 0; j /= 2)
            t += j % 2;
        a[i] = a[t] + 1;
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            for (int j = 0; j <= n; j++)
                if (j >= ss)
                    d[j] = (d[j] + c[n - 1 - i][j - ss]) % mod;
            ss++;
        }
    }
    d[ss]++;
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] + 1 == k)
            ans = (ans + d[i]) % mod;
    if (k == 0)
        ans = 1;
    else if (k == 1)
        ans = (ans + mod - 1) % mod;
    cout << ans;
}