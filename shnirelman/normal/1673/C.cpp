#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 4e4 + 13;
const int K = 513;
const int M = 1e9 + 7;
const int LOGN = 20;
const int A = 26;

int sum(int a, int b) {
    a += b;
    return (a >= M ? a - M : a);
}

vector<int> a;
int dp[N][K];

void solve() {
    int n;
    cin >> n;

    cout << dp[n][a.size() - 1] << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 1; i <= N; i++) {
        vector<int> d;
        int x = i;
        while(x > 0) {
            d.push_back(x % 10);
            x /= 10;
        }

        bool res = true;
        for(int j = 0; j < d.size() && res; j++)
            if(d[j] != d[d.size() - j - 1])
                res = false;

        if(res)
            a.push_back(i);
    }

//    dp[0][0] = 1;
    for(int i = 0; i < K; i++)
        dp[0][i] = 1;

    for(int i = 1; i < N; i++) {
        for(int j = 0; j < a.size(); j++) {
            dp[i][j] = (j > 0 ? dp[i][j - 1] : 0);
            if(a[j] <= i)
                dp[i][j] = sum(dp[i][j], dp[i - a[j]][j]);
        }
    }

//    for(int x : a)
//        cout << x << endl;

//    cout << a.size() << endl;

    int t;
    cin >> t;

    while(t--)
        solve();
}