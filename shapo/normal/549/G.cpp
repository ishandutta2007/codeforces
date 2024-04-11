#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <utility>

using namespace std;

int n;
vector< pair< int, int > > a;

int
main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].first += i;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    bool ok = true;
    for (int i = 0, pr = 0; i < n && ok; ++i) {
        a[i].first -= i;
        if (a[i].first < pr) {
            ok = false;
        } else {
            pr = a[i].first;
        }
    }
    if (ok) {
        for (int i = 0; i < n; ++i) {
            cout << a[i].first << ' ';
        }
        cout << '\n';
    } else {
        cout << ":(\n";
    }
    return 0;
}