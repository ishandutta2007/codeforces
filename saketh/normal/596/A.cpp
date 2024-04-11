#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N;
vector<int> x, y;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N;

    x.resize(N);
    y.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    sort(x.begin(), x.end());
    x.resize(unique(x.begin(), x.end()) - x.begin());

    sort(y.begin(), y.end());
    y.resize(unique(y.begin(), y.end()) - y.begin());

    if (x.size() == 1 || y.size() == 1) {
        cout << -1 << "\n";
    } else {
        cout << abs(x[1] - x[0]) * abs(y[1] - y[0]) << "\n";
    }

    return 0;
}