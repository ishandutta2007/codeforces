#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

const int Q = 31;

int dp[Q][Q];

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 1; i < n; i++) {
        dp[s[i - 1] - 'A'][s[i] - 'A']++;
    }
    int a = -1, b = -1, res = 0;
    for (int i = 0; i < Q; i++) {
        for (int j = 0; j < Q; j++) {
            if (dp[i][j] > res) {
                res = dp[i][j];
                a = i, b = j;
            }
        }
    }
    cout << (char) (a + 'A') << (char) (b + 'A');
}