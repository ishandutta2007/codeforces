#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

const int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};

int mask[71] = {}, ways[71][2] = {}, dp[71][1<<19] = {};

void add(int &a, int b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
}

int mul(int a, int b) {
    return (long long) a * b % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    for (int i=1; i<=70; i++)
        ways[i][0] = 1;

    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        int tmp = ways[a][0];
        add(ways[a][0], ways[a][1]);
        add(ways[a][1], tmp);
    }

    for (int i=1; i<=70; i++)
        for (int j=0; j<19; j++) {
            int num = i, cnt = 0;
            while (num % primes[j] == 0) {
                cnt++;
                num /= primes[j];
            }
            if (cnt % 2 == 1)
                mask[i] |= 1 << j;
        }

    dp[0][0] = 1;
    for (int i=1; i<=70; i++)
        for (int j=0; j<1<<19; j++) {
            add(dp[i][j], mul(dp[i-1][j], ways[i][0]));
            add(dp[i][j], mul(dp[i-1][j ^ mask[i]], ways[i][1]));
        }

    cout << (dp[70][0] + MOD - 1) % MOD << "\n";

    return 0;
}