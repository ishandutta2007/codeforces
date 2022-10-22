#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<pii> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a.begin(), a.end());
    vector<int> b(n);
    for (int i = 1; i < n; ++i) {
        b[a[i - 1].second] = a[i].first;
    }
    b[a[n - 1].second] = a[0].first;

    for (int i = 0; i < n; ++i) {
        cout << b[i] << " ";
    }
    cout << '\n';

    return 0;
}