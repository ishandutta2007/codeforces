#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(a) (a).begin(), (a).end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<pair<int, int>> b;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b.pb({a[i] + i, i});
    }
    sort(all(b));
    vector<int> c;
    for (int i = 0; i < n; i++) c.pb(a[b[i].y] - i + b[i].y);
    if (is_sorted(all(c))) {
        for (auto i : c) cout << i << " ";
    } else {
        cout << ":(";
    }
    return 0;
}