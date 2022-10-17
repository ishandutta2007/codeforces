#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

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
        for(i++; i; i -= i&-i)
            sum = sum + v[i];
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
    cout << fixed << setprecision(15);

    int N;
    ll T;
    cin >> N >> T;

    vi cost(N);
    BIT<ll> booths(N);
    for (int i = 0; i < N; i++) {
        cin >> cost[i];
        booths.update(i, cost[i]);
    }

    int total_booths = N;
    ll total_cost = booths.read(N-1);

    ll ans = 0;
    while (true) {
        while (total_cost > T) {
            int skip = booths.lower_bound(T + 1);
            total_booths--;
            total_cost -= cost[skip];
            booths.update(skip, -cost[skip]);
        }
        if (total_booths == 0) break;

        ans += T / total_cost * total_booths;
        T %= total_cost;
    }

    cout << ans << endl;
    return 0;
}