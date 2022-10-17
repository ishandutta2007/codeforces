#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
    
int N;
vector<int> vals;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N;

    vals.resize(N);

    for (int &x : vals)
        cin >> x;

    ll ans = abs(vals[0]);

    for (int i = 1; i < N; i++) {
        ans += abs(vals[i] - vals[i-1]);
    }

    cout << ans << "\n";
    return 0;
}