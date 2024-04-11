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

int n, bit[100001];

int getSum(int index) {
    int sum = 0;
    index++;
    while (index > 0) {
        sum += bit[index];
        index -= index & (-index);
    }
    return sum;
}

void update(int index, int val) {
    index++;
    while (index <= n) {
        bit[index] += val;
        index += index & (-index);
    }
}

int a[100000], pos[100001];
int bi[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        memset(bit, 0, sizeof(bit));
        memset(pos, -1, sizeof(pos));
        vector<pair<int, int>> v;

        int m;
        cin >> n >> m;
        for (int i=0; i<n; i++) {
            cin >> a[i];
            bi[a[i]] = i;
        }
        for (int i=0; i<m; i++) {
            int b;
            cin >> b;
            pos[b] = i;
            v.emplace_back(i, bi[b]);
        }

        int earliest = INT_MAX;
        long long ret = 0;
        unordered_set<int, custom_hash> st;
        for (int i=n-1; i>=0; i--) {
            if (pos[a[i]] == -1)
                continue;
            if (pos[a[i]] > earliest)
                ret++;
            else
                st.insert(pos[a[i]]);
            earliest = min(earliest, pos[a[i]]);
        }

        sort(v.begin(), v.end());
        for (int i=0; i<m; i++) {
            if (st.count(v[i].first)) {
                int g = getSum(v[i].second);
                g = v[i].second - g;
                ret += 2 * g + 1;
            }
            update(v[i].second, 1);
        }

        cout << ret << "\n";
    }

    return 0;
}