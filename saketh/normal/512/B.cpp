#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 333;
const int MAXP = 15;
const int INF = 1e9 + 1e5;

int N;
int cards[MAXN];
int cost[MAXN];

int mask[MAXN];
int dp[1 << MAXP];

vector<int> factor(int value) {
    vector<int> result;

    for (int p = 2; p * p <= value; p++) {
        if (value % p) continue;
        result.push_back(p);
        while (value % p == 0) value /= p;
    }

    if(value != 1) result.push_back(value);
    return result;
}

int solve(int value) {
    vector<int> primes = factor(value);

    for (int i = 0; i < N; i++) {
        mask[i] = 0;
        for (int j = 0; j < primes.size(); j++)
            if (cards[i] % primes[j] != 0)
                mask[i] |= (1 << j);
    }

    int FIN = (1 << primes.size()) - 1;

    memset(dp, 0x7f, sizeof(dp));
    dp[0] = 0;

    for (int m = 0; m < FIN; m++) {
        for (int i = 0; i < N; i++) {
            int g = m | mask[i];
            dp[g] = min(dp[g], dp[m] + cost[i]);
        }
    }

    return dp[FIN];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N;

    for (int i = 0; i < N; i++) 
        cin >> cards[i];

    for (int i = 0; i < N; i++) 
        cin >> cost[i];

    int ans = INF;
    for (int i = 0; i < N; i++) {
        ans = min(ans, cost[i] + solve(cards[i]));
    }

    cout << (ans < INF ? ans : -1) << endl;
}