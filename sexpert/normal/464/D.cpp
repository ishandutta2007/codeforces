#include <bits/stdc++.h>
using namespace std;

const int MAX = 1005;
double dp[MAX], tmp[MAX], k;
int n;

int main() {
    cin >> n >> k;
    for(int turn = 1; turn <= n; turn++) {
        for(int st = 1; st < MAX - 1; st++) {
            double x = st*(st + 3)/2.0 + (double)st * dp[st] + dp[st + 1];
            x /= k * (st + 1);
            x += (k - 1)/k * dp[st];
            tmp[st] = x;
        }
        for(int i = 1; i < MAX; i++)
            dp[i] = tmp[i];
    }
    cout << fixed << setprecision(400) << k * dp[1] << '\n';
}