#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> l(n), r(n);

    for(int i = 0; i < n; i++)
        cin >> l[i] >> r[i];
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());

    ll res = n;
    for(int i = 0; i < n; i++)
        res += max(l[i], r[i]);
    cout << res << endl;
}