#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N, D, H;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N >> D >> H;

    if (D > 2 * H) {
        cout << -1 << "\n";
        return 0;
    }

    vector<pair<int, int>> res;

    int last = 1;

    // first create the height
    for (int i = 1; i <= H; i++) {
        res.emplace_back(i, i + 1);
        last = i + 1;
    }

    // now produce the diameter
    if (D > H) {
        res.emplace_back(1, ++last);

        for (int CD = H + 1; CD < D; CD++) {
            res.emplace_back(last, last + 1);
            last++;
        }
    }

    // now add the remaining vertices
    if (H == 1) {
        if (D == 1 && res.size() < N - 1) {
            cout << -1 << "\n";
            return 0;
        }

        while (res.size() < N - 1) {
            res.emplace_back(1, ++last);
        }
    } else {
        while (res.size() < N - 1) {
            res.emplace_back(2, ++last);
        }
    }


    for (auto p : res) {
        cout << p.first << " " << p.second << "\n";
    }
}