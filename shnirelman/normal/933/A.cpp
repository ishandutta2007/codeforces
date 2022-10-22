//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 2e5 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;

mt19937 rnd(36547);

/*

*/


int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> suf1(n + 1, 0), suf2(n + 1, 0);
    for(int i = n - 1; i >= 0; i--) {
        suf1[i] = suf1[i + 1];
        suf2[i] = suf2[i + 1];
        if(a[i] == 1) {
            suf1[i] = max(suf1[i + 1] + 1, suf2[i + 1] + 1);
        } else {
            suf2[i] = suf2[i + 1] + 1;
        }
    }

    int c1 = 0;
    int ans = max(suf1[0], suf2[0]);
    for(int i = 0; i < n; i++) {
        int res = c1;

        int dp1 = 0, dp2 = 0;
        for(int j = i; j < n; j++) {
            if(a[j] == 1) {
                dp1 = max(dp1 + 1, dp2 + 1);
            } else {
                dp2++;
            }

            ans = max(ans, c1 + suf2[j + 1] + max(dp1, dp2));
        }

        if(a[i] == 1)
            c1++;
    }

    cout << ans << endl;
}