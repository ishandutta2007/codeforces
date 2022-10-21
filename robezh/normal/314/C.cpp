#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef pair<int, int> P;
typedef long long ll;
const int N = (int)1e5 + 50, mod = (int)1e9 + 7, M = (int)1e6 + 50;

//BIT is 0-indexed!!!

int n;
int num[N];
int las[M], to[N];
P p[N];


struct BIT {
    ll bit[N];

    void add(int x, ll val) {
        for (int i = x; i < n; i |= i + 1) bit[i] += val, bit[i] %= mod;
    }

    ll get(int x) {
        ll res = 0;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1) res += bit[i], res %= mod;
        return res;
    }

    ll getpoint(int x) {
        return get(x) - get(x-1);
    }

} bit0, bit1;

int main() {
    cin >> n;
    fill(las, las + M, -1);
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        to[i] = las[x] == -1 ? -1 : las[x];
        p[i].second = i;
        p[i].first = x;
        las[x] = i;
    }
    sort(p, p + n);
    ll res = 0;
    for(int i = 0; i < n; i++) {
        ll sum = (bit0.get(p[i].second) + 1) * p[i].first % mod;
        bit1.add(p[i].second, sum);
        if(to[p[i].second] != -1) sum -= bit1.getpoint(to[p[i].second]), sum %= mod;
        bit0.add(p[i].second, sum);
        res += sum;
        res %= mod;
    }
    cout << (res + mod) % mod << endl;

}