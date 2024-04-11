#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using pii = pair<int, int>;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 1; i < n; i++) {
        cout << "? " << 1 << ' ' << i + 1 << endl;
        cin >> a[i];
    }

    cout << "? " << 2 << ' ' << 3 << endl;

    cin >> a[0];

    vector<int> ans(n);
    for(int i = 2; i < n; i++)
        ans[i] = a[i] - a[i - 1];

    ans[0] = a[2] - a[0];
    ans[1] = a[1] - ans[0];

    cout << "! ";
    for(auto x : ans)
        cout << x << ' ';
    cout << endl;
}