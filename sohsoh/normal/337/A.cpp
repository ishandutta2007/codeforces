#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v;
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;

        v.push_back(t);
    }

    sort(v.begin(), v.end());

    int mi = 10000;
    for (int i = 0; i <= m - n; i++) {
        mi = min(mi, (v[i + n - 1] - v[i]));
    }

    cout << mi << endl;
    return 0;
}