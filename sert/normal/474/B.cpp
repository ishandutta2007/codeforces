#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k, cur;
vector <pair<int, int> > v;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        for (int j = 0; j < k; j++)
            v.push_back(make_pair(++cur, i + 1));
    }
    cin >> m;
    while (m--) {
        cin >> k;
        cout << lower_bound(v.begin(), v.end(), make_pair(k, -1)) -> second << "\n";
    }
    return 0;
}