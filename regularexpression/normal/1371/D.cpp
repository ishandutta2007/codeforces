#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define len(a) ((int) (a).size())
#define all(a) (a).begin(), (a).end()

void solve() {
    int n, k;
    cin >> n >> k;
    cout << (k % n == 0 ? 0 : 2) << '\n';
    int z = k / n, pos = 0;
    for (int i = 0; i < n; i++) {
        vector<int> row(n, 0);
        for (int j = 0; j < (i < k % n ? z + 1 : z); j++) {
            row[pos] = 1;
            pos = (pos + 1) % n;
        }
        for (int j = 0; j < n; j++) cout << row[j];
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}