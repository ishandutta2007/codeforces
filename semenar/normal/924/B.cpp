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

    int n, U;
    cin >> n >> U;

    vector<int> elev(n);
    for (int i = 0; i < n; i++) cin >> elev[i];

    bool exist = false;

    for (int i = 0; i < n - 2; i++) if (elev[i + 2] - elev[i] <= U) exist = true;
    if (!exist) {
        cout << -1 << endl;
        return 0;
    }

    double ans = 0;
    int pt1 = 0;
    for (int pt2 = 0; pt2 < n - 1; pt2++) {
        while (pt1 < n - 1 && elev[pt1 + 1] - elev[pt2] <= U) pt1++;
        if (pt2 < pt1 - 1) ans = max(ans, (double)(elev[pt1] - elev[pt2 + 1]) / (elev[pt1] - elev[pt2]));
    }
        
    cout << fixed << setprecision(10) << ans << endl;


    return 0;
}