#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;

ll n, x1, x2, k, b;
vector <pair<pair<ll, ll>, int > > e1, e2;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n >> x1 >> x2;
    for (int i = 0; i < n; i++) {
        cin >> k >> b;
        e1.push_back(make_pair(make_pair(k * x1 + b, k), i + 1));
        e2.push_back(make_pair(make_pair(k * x2 + b, -k), i + 1));
    }
    sort(e1.begin(), e1.end());
    sort(e2.begin(), e2.end());

    for (int i = 0; i < n; i++)
        if (e1[i].second != e2[i].second) {
            cout << "YES";
            return 0;
        }
    cout << "NO";


    return 0;
}