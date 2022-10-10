#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    unordered_multiset<int> a, b;
    cin >> n;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        a.insert(x);
    }
    cin >> m;
    for (int i=0; i<m; i++) {
        int x;
        cin >> x;
        b.insert(x);
    }

    bool done = false;
    for (int x : a) {
        if (done)
            break;
        for (int y : b)
            if (!a.count(x + y) && !b.count(x + y)) {
                cout << x << " " << y << "\n";
                done = true;
                break;
            }
    }

    return 0;
}