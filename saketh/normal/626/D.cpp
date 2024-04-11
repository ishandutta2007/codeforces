#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2050;
const int MAXV = 5050;

int N;
int value[MAXN];

double prob[MAXV]; // chance of getting a certain difference
double prgt[MAXV];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> value[i];
    }

    sort(value, value + N);

    double chance = 1.0 / (N * (N - 1.0) / 2.0);

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            prob[value[j] - value[i]] += chance;
        }
    }

    for (int d = MAXV - 2; d >= 0; d--) {
        prgt[d] = prgt[d + 1] + prob[d + 1];
    }

    double ans = 0;

    for (int d1 = 1; d1 < MAXV; d1++) {
        for (int d2 = 1; d1 + d2 < MAXV; d2++) {
            ans += prob[d1] * prob[d2] * prgt[d1 + d2];
        }
    }

    cout << ans << "\n";
    return 0;
}