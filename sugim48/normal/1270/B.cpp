#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < (N); i++)
#define all(a) (a).begin(), (a).end()
#define pb push_back

using ll = long long;
using i_i = tuple<int, int>;

i_i f(vector<int> a) {
    int N = a.size();
    rep(i, N - 1) if (abs(a[i] - a[i + 1]) >= 2) return i_i(i, i + 1);
    return i_i(-1, -1);
}

int main() {
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<int> a(N);
        rep(i, N) scanf("%d", &a[i]);
        int i, j;
        tie(i, j) = f(a);
        if (i == -1) cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            cout << i + 1 << ' ' << j + 1 << endl;
        }
    }
}