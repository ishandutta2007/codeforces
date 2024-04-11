#include <bits/stdc++.h>
using namespace std;

template<typename T> struct BIT{
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

typedef long long ll;
const int MAXN = 3e5 + 500;
const ll INF = 1e18;

vector<int> all;
BIT<int> avail(2 * MAXN);
BIT<ll> totcost(2 * MAXN);

void put(int cost, int qua) {
    int idx = lower_bound(all.begin(), all.end(), cost) - all.begin();
    avail.update(idx, qua);
    totcost.update(idx, qua * cost);
}

ll read(int need) { 
    int idx = 2 * MAXN - 1;
    int lo = 0, hi = idx;

    if (avail.read(hi) < need) return INF;

    while (lo <= hi) {
        int mi = (lo + hi) / 2;

        if (avail.read(mi) >= need) {
            idx = mi;
            hi = mi - 1;
        }
        else lo = mi + 1;
    }

    int get = avail.read(idx);
    ll res = totcost.read(idx);
    return res - (get - need) * all[idx];
}

int N, W;
int a[MAXN], b[MAXN];
int ord[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N >> W;

    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i];

        all.push_back(a[i]);
        all.push_back(b[i] - a[i]);

        ord[i] = i;
    }

    sort(all.begin(), all.end());
    all.resize(unique(all.begin(), all.end()) - all.begin());

    sort(ord, ord + N, [](int i, int j) {
        return b[i] < b[j]; 
    });

    for (int i = 0; i < N; i++) {
        put(a[i], 1);
    }

    int bpf = 0;
    ll ans = read(W);

    ll sofar = 0;
    for (int pf = 1; pf <= N; pf++) {
        put(a[ord[pf-1]], -1);
        sofar += a[ord[pf-1]];
        put(b[ord[pf-1]] - a[ord[pf-1]], 1);

        ll total = sofar + read(W - pf);
        if (total < ans) {
            ans = total;
            bpf = pf;
        }
    }

    cout << ans << "\n";
    vector<int> res(N);

    vector<pair<int, int>> avail;
    for (int i = 0; i < N; i++) {
        if (i < bpf) {
            avail.emplace_back(b[ord[i]] - a[ord[i]], ord[i]);
            res[ord[i]]++;
        } else {
            avail.emplace_back(a[ord[i]], ord[i]);
        }
    }

    sort(avail.begin(), avail.end());

    for (int i = 0; i < (W - bpf); i++) {
        res[avail[i].second]++;        
    }

    for (int v : res)
        cout << v;
    cout << "\n";
}