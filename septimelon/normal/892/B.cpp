#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> l(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i];
    }
    reverse(l.begin(), l.end());
    int dead = 0;
    int lastd = -1;
    for (int i = 0; i < n; ++i) {
        int lastk = min(n - 1, i + l[i]);
        if (lastk > lastd) {
            dead += lastk - max(i, lastd);
            lastd = lastk;
        }
    }
    cout << n - dead << '\n';

    return 0;
}