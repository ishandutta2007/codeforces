#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

typedef long long ll;

using namespace std;

int main() {
        ll q;
        cin >> q;
        for (int i = 0; i < q; ++i) {
                ll n, a, b;
                cin >> n >> a >> b;
                ll ans = n * a;
                ans = min(n / 2 * b + n % 2 * a, ans);
                cout << ans << endl;
        }
        return 0;
}