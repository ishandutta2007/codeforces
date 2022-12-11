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

const int N = 1e6 + 34;

int a[N], k[N];
vector <int> v;

int main() {
    init();
    int n, m;
    cin >> n >> m;
    int b = n / m, ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < N)
            k[a[i]]++;
        if (a[i] > m || k[a[i]] > b)
            v.push_back(i);
    }

    for (int i = 1; i <= m; i++) {
        for (int j = k[i] + 1; j <= b; j++) {
            a[v.back()] = i;
            v.pop_back();
            ans++;
        }
    }

    cout << b << " " << ans << "\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}