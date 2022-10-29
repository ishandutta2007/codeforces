#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int
main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector< vector< int > > allV(3);
    for (int i = 0; i < n; ++i) {
        int cur;
        cin >> cur;
        allV[cur - 1].push_back(i + 1);
    }
    int val = min(allV[0].size(), min(allV[1].size(), allV[2].size()));
    cout << val << '\n';
    for (int i = 0; i < val; ++i) {
        cout << allV[0][i] << ' ' << allV[1][i] << ' ' << allV[2][i] << '\n';
    }
    return 0;
}