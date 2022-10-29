#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int
main()
{
    int n;
    long long m;
    cin >> n >> m;
    --m;
    vector< int > l, r;
    for (int i = n - 2; i >= 0; --i) {
        if (m & (1ll << i)) {
            r.push_back((n - i - 1));
            m ^= (1ll << i);
        } else {
            l.push_back((n - i - 1));
        }
    }
    l.push_back(n);
    reverse(r.begin(), r.end());
    for (auto x : l) {
        cout << x << ' ';
    }
    for (auto x : r) {
        cout << x << ' ';
    }
    cout << '\n';
    return 0;
}