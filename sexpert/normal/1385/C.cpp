#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v)
        cin >> x;
    if(n <= 2) {
        cout << "0\n";
        return;
    }
    reverse(v.begin(), v.end());
    int ptr = 0;
    vector<int> mt;
    while(ptr < n && (mt.empty() || v[ptr] >= mt.back()))
        mt.push_back(v[ptr++]);
    while(ptr < n && v[ptr] <= mt.back())
        mt.push_back(v[ptr++]);
    cout << n - ptr << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}