#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

int main() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(auto &x : a)
        cin >> x;
    vector<ii> c;
    for(int i = 0; i < n; i++)
        c.push_back({a[i] + a[(i + 1)%n], i});
    sort(c.begin(), c.end());
    for(int i = 0; i < n; i++)
        b[c[i].second] = i;
    for(int i = 0; i < n; i++)
        cout << b[i] << " ";
    cout << '\n';
}