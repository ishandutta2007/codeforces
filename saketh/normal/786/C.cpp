#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

typedef long long ll;
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
        for(i++; i<=S; i+=i&-i)
            v[i] = v[i] + k;
    }

    T read(int i) {
        T sum = 0;
        for(i++; i; i-=i&-i)
            sum = sum + v[i];
        return sum;
    }

    T read(int l, int r) {
        return read(r) - read(l-1);
    }
};

int find(int allow, BIT<int> &bit) {
    int ans = 0;

    int lo = 1, hi = bit.S - 1;
    while (lo <= hi) {
        int mi = (lo + hi) / 2;
        int res = bit.read(mi);
        if (res <= allow) {
            ans = mi;
            lo = mi + 1;
        } else hi = mi - 1;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;

    vi val(N);
    for (int i = 0; i < N; i++) {
        cin >> val[i];
        val[i]--;
    }

    vi occ(N, N), succ(N, N);

    for (int i = N - 1; i >= 0; i--) {
        succ[i] = occ[val[i]];
        occ[val[i]] = i;
    }

    BIT<int> bit(N + 1);

    for (int i = 0; i < N; i++) 
        if (occ[i] != N) {
            bit.update(occ[i], 1);
        }

    vi ans(N + 1);

    vvi query(N + 1);
    for (int i = 1; i <= N; i++)
        query[0].push_back(i);

    for (int i = 0; i < N; i++) {
        for (int k : query[i]) {
            ans[k]++;
            int go = find(k, bit);
            if (go != N) query[go + 1].push_back(k);
        }
        bit.update(i, -1);
        if (succ[i] != N) bit.update(succ[i], 1);
    }

    for (int i = 1; i <= N; i++)
        cout << ans[i] << " ";
    cout << endl;

    return 0;
}