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
#include <sstream>

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

void solve(istream &cin = std::cin, ostream &cout = std::cout) {
    int n, m, c_l, c_e, v;
    cin >> m >> n >> c_l >> c_e >> v;

    vector<int> ladders(c_l), elevs(c_e);

    for (int i = 0; i < c_l; i++) {
        cin >> ladders[i];
        ladders[i]--;
    }
    for (int i = 0; i < c_e; i++) {
        cin >> elevs[i];
        elevs[i]--;
    }

    int q;
    cin >> q;

    vector<pair<pair<int, int>, pair<int, int>>> queries;

    for (int i = 0; i < q; i++) {
        int x_1, y_1, x_2, y_2;
        cin >> y_1 >> x_1 >> y_2 >> x_2;
        x_1--, x_2--;

        queries.emplace_back(make_pair(x_1, x_2), make_pair(abs(y_1 - y_2), i));
    }

    sort(queries.begin(), queries.end());

    int last_l = 0, last_e = 0;
    vector<int> ans(q, inf);

    for (auto query : queries) {
        while (last_l < c_l && ladders[last_l] < query.first.first) last_l++;
        while (last_e < c_e && elevs[last_e] < query.first.first) last_e++;

        if (last_l > 0) {
            ans[query.second.second] = min(ans[query.second.second],
                abs(query.first.first - ladders[last_l - 1]) + abs(query.first.second - ladders[last_l - 1]) + query.second.first);
        }
        if (last_l < c_l) {
            ans[query.second.second] = min(ans[query.second.second],
                abs(query.first.first - ladders[last_l]) + abs(query.first.second - ladders[last_l]) + query.second.first);
        }
        if (last_e > 0) {
            ans[query.second.second] = min(ans[query.second.second],
                abs(query.first.first - elevs[last_e - 1]) + abs(query.first.second - elevs[last_e - 1]) + (query.second.first + v - 1) / v);
        }
        if (last_e < c_e) {
            ans[query.second.second] = min(ans[query.second.second],
                abs(query.first.first - elevs[last_e]) + abs(query.first.second - elevs[last_e]) + (query.second.first + v - 1) / v);
        }

        if (query.second.first == 0) ans[query.second.second] = abs(query.first.second - query.first.first);
    }

    for (auto elem : ans) {
        cout << elem << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}