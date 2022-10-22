#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int s, n;
    cin >> s >> n;

    vector<pair<int, int>> d;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        d.push_back(make_pair(a, b));
    }

    sort(d.begin(), d.end());

    for (int i = 0; i < d.size(); i++) {
        if (s <= d[i].first) {
            cout << "NO" << endl;
            return 0;
        }

        s += d[i].second;
    }

    cout << "YES" << endl;

    return 0;
}