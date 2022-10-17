#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template<typename T> struct BIT {
    int S;
    vector<T> v;

    BIT<T>(int _S){
        S = _S;
        v.resize(S+1);
    }
    
    void update(int i, T k){
        for(i++; i<=S; i+=i&-i)
            v[i] = v[i] + k;
    }

    T read(int i){
        T sum = 0;
        for(i++; i; i-=i&-i)
            sum = sum + v[i];
        return sum;
    }

    T read(int l, int r){
        return read(r) - read(l-1);
    }
};

const int MAXN = 1e5 + 100;
const int MAXV = 5e5 + 100;

int N;
int a[MAXN], b[MAXN], c[MAXN], d[MAXN];

vector<int> all;

vector<pair<int, int>> horiz[MAXV], vert[MAXV];

vector<pair<int, int>> events[MAXV + 1];

int idx(int val) {
    return lower_bound(all.begin(), all.end(), val) - all.begin();
}

void sanitize(vector<pair<int, int>> &vec) {
    sort(vec.begin(), vec.end());

    vector<pair<int, int>> res;

    for (auto p : vec) {
        if (res.empty()) {
            res.push_back(p);
            continue;
        }

        if (res.back().second >= p.first) {
            res.back().second = max(res.back().second, p.second);
        } else {
            res.push_back(p);
        }
    }

    swap(vec, res);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];

        all.push_back(a[i]);
        all.push_back(b[i]);
        all.push_back(c[i]);
        all.push_back(d[i]);
    }

    sort(all.begin(), all.end());
    all.resize(unique(all.begin(), all.end()) - all.begin());

    for (int i = 0; i < N; i++) {
        a[i] = idx(a[i]);
        b[i] = idx(b[i]);
        c[i] = idx(c[i]);
        d[i] = idx(d[i]);

        // compressed to [0, 4e5)

        if (a[i] == c[i]) { // vertical
            int x = a[i];
            int y1 = min(b[i], d[i]);
            int y2 = max(b[i], d[i]);

            vert[x].emplace_back(y1, y2);
        } else {            // horizontal
            int y = b[i];
            int x1 = min(a[i], c[i]);
            int x2 = max(a[i], c[i]);

            horiz[y].emplace_back(x1, x2);
        }
    }

    ll ans = 0;

    for (int i = 0; i < MAXV; i++) {
        sanitize(horiz[i]);
        sanitize(vert[i]);

        for (auto p : horiz[i]) {
            ans += all[p.second] - all[p.first] + 1;
        }

        for (auto p : vert[i]) {
            ans += all[p.second] - all[p.first] + 1;
        }
    }

    for (int i = 0; i < MAXV; i++) {
        for (auto p : horiz[i]) {
            events[p.first].emplace_back(i, 1);
            events[p.second + 1].emplace_back(i, -1);
        }
    }

    BIT<int> bit(MAXV);

    for (int i = 0; i < MAXV; i++) {
        for (auto e : events[i]) {
            bit.update(e.first, e.second);
        }

        for (auto p : vert[i]) {
            ans -= bit.read(p.first, p.second);
        }
    }

    cout << ans << "\n";
    return 0;
}