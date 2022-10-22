#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 100 + 13;
const int LOGN = 20;
const int A = 27;

int dp[N][N];
int p[N][N];

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);
    int n;
    cin >> n;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++)
            dp[i][j] = INF;
    }

    for(int i = 1; i <= n; i += 2) {
        dp[n - i][i / 2] = i / 2 + 1;
        p[n - i][i / 2] = -1;
    }

    for(int i = n; i >= 0; i--) {
        for(int j = 1; j <= n; j++) if(dp[i][j] < INF) {
            for(int k = 1; k <= j && k * 2 - 1 <= i; k++) {
                if(dp[i - k * 2 + 1][k - 1] > dp[i][j]) {
                    dp[i - k * 2 + 1][k - 1] = dp[i][j];
                    p[i - k * 2 + 1][k - 1] = j;
                }
            }
        }
    }

//    for(int i = 0; i < n; i++) {
//        for(int j = 0; j <= i; j++)
//            cout << i << ' ' << j << ' ' << dp[i][j] << endl;
//    }

    int mn = -1;
    for(int i = 0; i < N; i++)
        if(mn == -1 && dp[0][i] < INF || dp[0][i] < dp[0][mn])
            mn = i;

    if(mn == -1) {
        cout << -1 << endl;
        return 0;
    }

    int x = dp[0][mn];
//    cout << "mn " << mn << ' ' << x << endl;
    vector<vector<bool>> a(x, vector<bool>(x, false));

    int cur = 0;
    int i = 0, j = mn;
    vector<int> b;
    while(i < n) {
//        cout << "while " << endl;
//            cout << i << ' ' << j << endl;
        b.push_back(j);
        int i1 = i + j * 2 + 1;
        j = p[i][j];
        i = i1;
//        cout << i << ' ' << j << endl;
    }

    reverse(b.begin(), b.end());

//    for(auto x : b)
//        cout << x << endl;

    for(int i = 0; i < b.size(); i++) {
        for(int j = 0; j <= b[i]; j++) {
//            cout << i + j << endl;
            a[i][i + j] = a[i + j][i] = true;
        }
    }

    cout << x << endl;
    reverse(a.begin(), a.end());
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < x; j++) {
            cout << (a[i][j] ? 'o' : '.');
        }
        cout << endl;
    }
}