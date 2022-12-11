#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 1e5 + 34;
const ll INF = 1e9;

ll s, k, f[N], sum, cur;
vector <ll> ans;

int main() {

    srand(3431);

    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    cin >> s >> k;
    f[0] = 1;
    sum = 1;
    for (int i = 1; true; i++) {
        f[i] = sum;
        sum += f[i];
        if (i - k >= 0) sum -= f[i - k];
        if (f[i] > s) {
            cur = i;
            break;
        }
    }
    for (int i = cur; i >= 0; i--) {
        if (f[i] <= s) {
            s -= f[i];
            ans.push_back(f[i]);
        }
        if (s == 0)
            break;
    }

    cout << ans.size() + 1 << "\n0 ";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    //while(true);
}