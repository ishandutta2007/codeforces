#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 34;
int n, ps, x;
vector <int> a, b;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x)
            a.push_back(x);
    }
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x)
            b.push_back(x);
    }
    ps = 0;
    while (b[ps] != a[0]) ps++;
    for (int i = 0; i < n - 1; i++)
    if (a[i] != b[(ps + i) % (n - 1)]) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";



    return 0;
}