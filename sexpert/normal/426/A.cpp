#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, s;
    cin >> n >> s;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    int x = accumulate(v.begin(), v.end(), 0) - *max_element(v.begin(), v.end());
    cout << (x <= s ? "YES\n" : "NO\n");
}