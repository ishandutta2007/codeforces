#include <bits/stdc++.h>
using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator () (uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

unordered_set<int, custom_hash> visited;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;

    queue<pair<int, int>> q;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        visited.insert(x);
        q.push({x - 1, 1});
        q.push({x + 1, 1});
    }

    long long ret = 0;
    vector<int> y;
    while (m > 0) {
        int x = q.front().first, dist = q.front().second;
        q.pop();
        if (visited.count(x))
            continue;

        ret += dist;
        y.push_back(x);
        m--;
        visited.insert(x);
        q.push({x - 1, dist + 1});
        q.push({x + 1, dist + 1});
    }

    cout << ret << "\n";
    for (int i : y)
        cout << i << " ";
    cout << "\n";

    return 0;
}