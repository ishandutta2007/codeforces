#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

pair <int, int> a[100];

bool cmp(pair<int,int> x, pair<int, int> y) {
    return y.second > x.second;
}

int main() {
    ///freopen("a.in", "r", stdin);
    for (int i = 0; i < 8; i++)
        cin >> a[i].first >> a[i].second;
    sort(a, a + 8);
    if (a[2].first != a[0].first || a[3].first != a[4].first || a[5].first != a[7].first) {
        cout << "ugly\n";
        return 0;
    }

    if (a[0].second != a[1].second && a[0].second != a[2].second && a[1].second != a[2].second)
    if (a[0].second == a[3].second && a[0].second == a[5].second)
    if (a[1].second == a[6].second)
    if (a[2].second == a[4].second && a[2].second == a[7].second) {
        cout << "respectable\n";
        return 0;
    }

    cout << "ugly\n";
    return 0;
}