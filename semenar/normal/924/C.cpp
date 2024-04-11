#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <ctime>
#include <set>
#include <algorithm>
#include <unordered_set>
#include <random>
#include <map>
#include <iomanip>

using namespace std;

int inf = (int)1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> m(n);

    for (int i = 0; i < n; i++) {
        cin >> m[i];
    }
    
    vector<int> min_lev(n);
    min_lev[0] = m[0] + 1;
    for (int i = 1; i < n; i++) min_lev[i] = max(min_lev[i - 1], m[i] + 1);

    for (int i = n - 2; i >= 0; i--) min_lev[i] = max(min_lev[i + 1] - 1, min_lev[i]);

    long long sum = 0;

    for (int i = 0; i < n; i++) sum += min_lev[i] - m[i] - 1;

    cout << sum << endl;

    return 0;
}