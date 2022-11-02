#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define all(a) (a).begin(), (a).end()
#define mp make_pair

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

const int N = 110;
int dp[N][N];

void calcDp() {
    for (int n = 0; n < N; ++n) {
        for (int cnt = 0; cnt < N; ++cnt) {
            dp[n][cnt] = -1;
        }
    }
    dp[0][0] = 0;
    for (int n = 1; n < N; ++n) {
        for (int addCnt = 0; 2 * n - 1 + addCnt < N; ++addCnt) {
            for (int nxt = 0; nxt < n; ++nxt) {
                if (dp[nxt][addCnt] == -1) continue;
                dp[n][2 * n - 1 + addCnt] = nxt;
            } 
        }
    }
}

char ans[N][N];
int topAns = 0;

void makeAns(int cnt) {
    int n = 0;
    while (n < N && dp[n][cnt] == -1) ++n;
    // assert(n < N);
    if (n == N) {
        cout << "-1\n";
        exit(0);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ans[i][j] = '.';
        }
    }
    topAns = n;
    int pos = 0;
    while (cnt) {
        cerr << "n = " << n << " cnt = " << cnt << endl;
        for (int i = 0; i < n; ++i) {
            ans[pos][i + pos] = ans[i + pos][pos] = 'o';
        }
        ++pos;
        int nxt = dp[n][cnt];
        cnt -= 2 * n - 1;
        n = nxt;
    } 
}

void printAns() {
    cout << topAns << '\n';
    for (int i = 0; i < topAns; ++i) {
        for (int j = 0; j < topAns; ++j) {
            cout << ans[topAns - 1 - i][j];
        }
        cout << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    calcDp();
    int cnt;
    cin >> cnt;
    makeAns(cnt);
    printAns();
    return 0;
}