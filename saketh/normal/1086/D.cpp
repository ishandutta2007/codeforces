#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<typename T> struct BIT {
    int S;
    vector<T> v;

    BIT<T>(int _S) {
        S = _S;
        v.resize(S+1);
    }

    void update(int i, T k) {
        for(i++; i <= S; i += i&-i)
            v[i] = v[i] + k;
    }

    T read(int i) {
        T sum = 0;
        for(i++; i; i -= i&-i) {
            sum = sum + v[i];
        }
        return sum;
    }

    T read(int l, int r) {
        return read(r) - read(l-1);
    }

    int lower_bound(T sum) {
        T res = 0;
        int inx = 0;
        for (int i = 31 - __builtin_clz(S); i >= 0; i--) {
            if ((inx + (1 << i) <= S) && res + v[inx + (1 << i)] < sum) {
                inx += 1 << i;
                res += v[inx];
            }
        }
        return inx;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    auto conv = [](char c) {
        return (c == 'R') ? 0 : (c == 'P') ? 1 : 2;
    };

    int N, Q;
    string init;
    cin >> N >> Q >> init;

    vi val(N);
    vector<set<int>> locs(3);
    vector<BIT<int>> counts(3, BIT<int>(N));

    for (int i = 0; i < N; i++) {
        val[i] = conv(init[i]);
        locs[val[i]].insert(i);
        counts[val[i]].update(i, 1);
    }

    auto winners = [&]() {
        int ans = N;
        for (int x = 0; x < 3; x++) {
            int y = (x + 1) % 3, z = (x + 2) % 3;
            if (!locs[y].size()) continue;
            if (!locs[z].size()) {
                ans -= counts[x].read(0, N - 1);
            } else {
                int fy = *locs[y].begin(), ly = *locs[y].rbegin();
                int fz = *locs[z].begin(), lz = *locs[z].rbegin();
                if (fy < fz) ans -= counts[x].read(fy, fz);
                if (lz < ly) ans -= counts[x].read(lz, ly);
            }
        }
        return ans;
    };

    cout << winners() << "\n";
    for (int q = 0, i, m; q < Q; q++) {
        string c;
        cin >> i >> c;
        i--;
        m = conv(c[0]);

        counts[val[i]].update(i, -1);
        locs[val[i]].erase(i);
        val[i] = m;
        counts[val[i]].update(i, 1);
        locs[val[i]].insert(i);

        cout << winners() << "\n";
    }

    return 0;
}