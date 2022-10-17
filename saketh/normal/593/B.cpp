#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 100;

int N, X1, X2;
int K[MAXN], B[MAXN];

ll calc(int i, ll X) {
    return K[i] * X + B[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N;
    cin >> X1 >> X2;

    vector<int> o1(N), o2(N);

    for (int i = 0; i < N; i++) {
        cin >> K[i] >> B[i];
        o1[i] = i;
        o2[i] = i;
    }

    // sort by y-coordinate
    sort(o1.begin(), o1.end(), [](int i, int j) {
        ll Y1 = calc(i, X1);
        ll Y2 = calc(j, X1);
        if (Y1 != Y2) return Y1 < Y2;
        return K[i] < K[j];
    });

    sort(o2.begin(), o2.end(), [](int i, int j) {
        ll Y1 = calc(i, X2);
        ll Y2 = calc(j, X2);
        if (Y1 != Y2) return Y1 < Y2;
        return K[i] > K[j];
    });

    bool same = true;
    for (int i = 0; i < N; i++)
        same &= o1[i] == o2[i];

    if (same) cout << "NO\n";
    else cout << "YES\n";
}