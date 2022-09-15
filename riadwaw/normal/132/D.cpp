#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <cmath>
#include <memory.h>
#include <algorithm>

using namespace std;
void solve();

#define pb push_back

typedef long long li;
typedef vector<int> vi;
typedef pair<int, int> pi;

int main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output","w",stdout);
#else
#endif
    cin.sync_with_stdio(false);
    //cout.sync_with_stdio(false);
    solve();
    return 0;
}
int dp[1010101][2];
int prevv[1010101][2];
int add[1010101][2];

void solve() {
    string s;
    cin >> s;
    dp[0][0] = 0;
    dp[0][1] = 1;
    add[0][1] = s.length() + 1;
    for (int i = 1; i <= s.length(); ++i) {
        if (s[i - 1] == '1') {
            dp[i][1] = dp[i - 1][1];
            prevv[i][1] = 1;
            add[i][1] = 0;
            dp[i][0] = min(dp[i - 1][0] + 1, dp[i - 1][1] + 1);
            if (dp[i - 1][0] < dp[i - 1][1]) {
                add[i][0] = s.length() - i + 1;
                prevv[i][0] = 0;
            } else {
                add[i][0] = -(s.length() - i + 1);
                prevv[i][0] = 1;
            }
        } else {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = min(dp[i - 1][0] + 1, dp[i - 1][1] + 1);
            if (dp[i - 1][0] < dp[i - 1][1]) {
                add[i][1] = s.length() - i + 1;
                prevv[i][1] = 0;
            } else {
                add[i][1] = -(s.length() - i + 1);
                prevv[i][1] = 1;
            }
            prevv[i][0] = 0;
        }
    }
    cout << dp[s.length()][0] << endl;\
    int pr = 0;
    for (int i = s.length(); i >= 0; --i) {
        if (add[i][pr] > 0)
            cout << "+2^" << (add[i][pr] - 1) << endl;
        else if (add[i][pr] < 0)
            cout << "-2^" << (-add[i][pr] - 1) << endl;
        pr = prevv[i][pr];
    }
}