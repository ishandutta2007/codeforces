#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.3
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;

const int N = (int)1e6 + 34;
const ll INF = 1e10;

ll c[N], d[N];
pair <ll, ll> a[N];
ll ans = INF;

int main() {
    init();
    ll n;
    cin >> n;
    vector <int> ans;
    ans.push_back(1);
    n--;
    while (ans.back() + 1 <= n) {
        ans.push_back(ans.back() + 1);
        n -= ans.back();
    }
    ans.back() += n;
    cout << ans.size() << "\n";
    for (int num: ans)
        cout << num << " ";

    return 0;
}