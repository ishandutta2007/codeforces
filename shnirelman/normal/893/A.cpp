#include <bits/stdc++.h>

using namespace std;
using li = long long;
using ld = long double;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    set<int> s;
    s.insert(1);
    s.insert(2);

    for(int i = 0; i < n; i++) {
        if(s.count(a[i])) {
            int x = *s.begin() ^ *s.rbegin() ^ a[i];
            s.erase(x);
            x = x ^ 1 ^ 2 ^ 3 ^ a[i];
            s.insert(x);
        } else {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES";
}