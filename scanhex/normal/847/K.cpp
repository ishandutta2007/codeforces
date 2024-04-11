#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
#endif
    int n, a, b, k, f;
    cin >> n >> a >> b >> k >> f;
    vector<string> u(n), v(n);
    for (int i = 0; i < n; i++) {
        cin >> u[i] >> v[i];
    }
    map<pair<string, string>, int> cost;

    long long s = 0;
    for (int i = 0; i < n; i++) {
        string s1 = u[i], s2 = v[i];
        if (s1 > s2) {
            swap(s1, s2);
        }

        if (i == 0 || u[i] != v[i - 1]) {
            s += a;
            cost[{s1, s2}] += a;
        } else {
            s += b;
            cost[{s1, s2}] += b;
        }
    }

    vector<int> mems;
    for (auto p : cost) {
        mems.push_back(p.second);
    }

    sort(mems.rbegin(), mems.rend());
    for (int i = 0; i < mems.size() && i < k; i++) {
        if (mems[i] > f) {
            s -= mems[i];
            s += f;
        }
    }

    cout << s << endl;

    return 0;
}