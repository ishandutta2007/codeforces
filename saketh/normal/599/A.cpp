#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int A, B, AB;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> A >> B >> AB;

    int ans = 1e9;

    ans = min(ans, 2 * A + 2 * B);
    ans = min(ans, A + AB + B);
    ans = min(ans, 2 * A + 2 * AB);
    ans = min(ans, 2 * B + 2 * AB);

    cout << ans << "\n";
}