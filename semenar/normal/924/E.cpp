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

struct fraction {
    int p;
    int q;

    friend bool operator<(fraction a, fraction b);
};

bool operator<(fraction a, fraction b) {
    return (long long)a.p * b.q < (long long)a.q * b.p;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, l, r;
    cin >> n >> l >> r;

    int h = 0;

    vector<int> height(n);
    vector<int> imp(n);
    for (int i = 0; i < n; i++) {
        cin >> height[i];
        h += height[i];
    }
    for (int i = 0; i < n; i++) cin >> imp[i];

    vector<pair<int, pair<int, int>>> imps;
    for (int i = 0; i < n; i++) {
        if (imp[i] == 0) {
            imps.emplace_back(1, make_pair(height[i], i));
        }
        else {
            imps.emplace_back(0, make_pair(height[i], i));
        }
    }
    vector<int> bp2(h + 1, -2);
    bp2[0] = -1;
    sort(imps.begin(), imps.end());
    for (int i = (int)imps.size() - 1; i >= 0; i--) {
        for (int j = h; j >= imps[i].second.first; j--) {
            if (bp2[j] == -2 && bp2[j - imps[i].second.first] != -2) bp2[j] = imps[i].second.second;
        }
    }

    vector<int> imp_obr(n);
    for (int i = 0; i < imps.size(); i++) imp_obr[imps[i].second.second] = i;

    int ans = 0;
    for (int i = l; i <= min(r, h); i++) {
        if (bp2[i] == -2) continue;
        vector<bool> picked(imps.size());
        int x = i;
        while (bp2[x] != -1) {
            picked[imp_obr[bp2[x]]] = true;
            x -= height[bp2[x]];
        }

        x = i;

        int start = 0;
        int cnt = 0;
        while (start < imps.size() && x <= r) {
            if (imps[start].first == 1) start++;
            else if (picked[start]) start++;
            else {
                x += imps[start].second.first;
                start++;
                cnt++;
            }
        }

        ans = max(ans, cnt);
    }

    cout << ans << endl;

    return 0;
}