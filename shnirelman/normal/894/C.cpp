#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;

const int M = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    set<int> s;
    int g = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        g = __gcd(g, a[i]);
        s.insert(a[i]);
    }

    if(s.count(g) == 0) {
        cout << -1;
        return 0;
    }

    cout << n * 2 << endl;
    for(int i = 0; i < n; i++)
        cout << a[i] << ' ' << g << ' ';
}