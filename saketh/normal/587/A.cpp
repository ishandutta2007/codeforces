#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e6 + 100;

int qua[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int V;
        cin >> V;

        qua[V]++;
    }

    int ans = 0;

    int carry = 0;
    for (int p = 0; p < MAXN; p++) {
        carry /= 2;
        carry += qua[p];

        if (carry & 1) {
            ans++;
            carry--;
        }
    }

    cout << ans << endl;
}