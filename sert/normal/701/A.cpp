#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.2
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif

    int n, x;
    cin >> n;
    vector <pair<int, int> > v;

    for (int i = 0; i < n; i++) {
        cin >> x;
        v.push_back({x, i + 1});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n / 2; i++)
        cout << v[i].second << " " << v[n - i - 1].second << "\n";

    return 0;
}