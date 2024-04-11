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

template<typename T> struct BIT{
    int S;
    vector<T> v;

    BIT<T>(int _S){
        S = _S;
        v.resize(S+1);
    }
    
    void update(int i, T k){
        for(i++; i<=S; i+=i&-i)
            v[i] = v[i] ^ k;
    }

    T read(int i){
        T sum = 0;
        for(i++; i; i-=i&-i)
            sum = sum ^ v[i];
        return sum;
    }

    T read(int l, int r){
        return read(r) ^ read(l-1);
    }
};

int main() {
    int N;
    scanf("%d", &N);
    unordered_map<int, vi> app;
    vi vals(N + 1), pref(N + 1);

    for (int i = 1; i <= N; i++) {
        scanf("%d", &vals[i]);
        pref[i] = pref[i-1] ^ vals[i];
        app[vals[i]].push_back(i);
    }

    BIT<int> bit(N + 1);
    for (auto v : app) {
        bit.update(v.second.back(), v.first);
    }

    int Q, L, R;
    scanf("%d", &Q);
    vi ans(Q);
    vector<array<int, 3>> queries(Q);

    for (int i = 0; i < Q; i++) {
        scanf("%d %d", &L, &R);
        queries[i] = { L, R, i };
        ans[i] = pref[L - 1] ^ pref[R];
    }

    sort(all(queries), [](array<int, 3> a, array<int, 3> b) {
        return a[1] > b[1];
    });

    R = N;
    for (auto q : queries) {
        while (R > q[1]) {
            bit.update(R, vals[R]);
            auto &wh = app[vals[R]];
            wh.pop_back();
            if (wh.size()) {
                bit.update(wh.back(), vals[R]);
            }
            R--;
        }

        ans[q[2]] ^= bit.read(q[0], q[1]);
    }

    for (int i = 0; i < Q; i++)
        printf("%d\n", ans[i]);

    return 0;
}