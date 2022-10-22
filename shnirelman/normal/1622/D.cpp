#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 5000 + 113;
const int K = 1e5 + 113;
const int M = 998244353;//1e9 + 7;
const int A = 26;

mt19937 rnd(3432);

int sum(int a, int b) {
    a += b;
    return (a >= M ? a - M : a);
}

int dif(int a, int b) {
    return sum(a, M - b);
}


/*

*/

int C[N][N];

int lf[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    C[0][0] = 1;
    for(int i = 1; i < N; i++) {
        C[i][0] = C[i][i] = 1;
        for(int j = 1; j < i; j++) {
            C[i][j] = sum(C[i - 1][j], C[i - 1][j - 1]);
        }
    }

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    if(k == 0) {
        cout << 1 << endl;
        return 0;
    }

    {
        int lst = -1;
        for(int i = 0; i < n; i++) {
            lf[i] = lst;
            if(s[i] == '1')
                lst = i;
        }
    }

    int ans = 0;
    vector<int> pos;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1')
            pos.push_back(i);
    }

    if(pos.size() < k) {
        cout << 1 << endl;
        return 0;
    }

    for(int i = 0; i + k <= pos.size(); i++) {
//        cout << i << ' ' << ans << ' ' << pos.size() << endl;
        int l = pos[i] - lf[pos[i]] - 1;
        int r = (i + k == pos.size() ? n - pos[i + k - 1] : pos[i + k] - pos[i + k - 1]) - 1;

        int len = r + pos[i + k - 1] - pos[i] + l + 1;

        ans = sum(ans, dif(C[len][k], (i + k < pos.size() ? C[len - l - 1][k - 1] : 0)));
    }

    cout << ans << endl;
//    int lst_fir = 0, lst_len = 0;
//
//    int r = 0;
//    int cur = 0;
//    int ans = 0;
//    for(int l = 0; l < n; l++) {
//        while(r < n && (cur < k || cur == k && s[r] == '0')) {
//            cur += (s[r] == '1');
//            r++;
//        }
//
//        if(cur == k) {
//
//        }
//    }

//    int t = 1;
////    cin >> t;
//
//    while(t--)
//        solve();
}