#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5;

int N;
int val[MAXN];
int rmx[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> val[i];

    for (int i = N - 2; i >= 0; i--) {
        rmx[i] = max(rmx[i+1], val[i+1]);
    }

    for (int i = 0; i < N; i++) {
        cout << max(0, rmx[i] - val[i] + 1) << " ";
    }
    cout << endl;
}