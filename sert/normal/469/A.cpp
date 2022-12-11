#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

int n, t, sz;
set <int> s;

int main() {
    //freopen("a.in", "r", stdin);
    cin >> sz;
    for (int iq = 0; iq < 2; iq++) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> t;
            s.insert(t);
        }
    }
    if (s.size() == sz)
        cout << "I become the guy.\n";
    else
        cout << "Oh, my keyboard!\n";
    return 0;
}