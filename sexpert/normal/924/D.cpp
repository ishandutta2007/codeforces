#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double D;

const int MAXN = 1e5 + 5;
int n;
ll x[MAXN], v[MAXN], p[MAXN], q[MAXN], val[MAXN], BIT[MAXN], w;

void upd(int p, ll v) {
    for(; p < MAXN; p += (p & -p))
        BIT[p] += v;
}

ll sum(int p) {
    ll res = 0;
    for(; p > 0; p -= (p & -p))
        res += BIT[p];
    return res;
}

bool tcmp(int a, int b) {
    return make_pair((D)p[a]/(D)x[a], (D)q[a]/(D)x[a]) < make_pair((D)p[b]/(D)x[b], (D)q[b]/(D)x[b]);
}

bool ycmp(int a, int b) {
    return (D)q[a]/(D)x[a] < (D)q[b]/(D)x[b];
}

bool eq(int a, int b) {
    return q[a]*x[b] == q[b]*x[a];
}

int main() {
    cin >> n >> w;
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> v[i];
        p[i] = w - v[i];
        q[i] = w + v[i];
    }
    vector<int> ord(n), yord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), tcmp);
    iota(yord.begin(), yord.end(), 0);
    sort(yord.begin(), yord.end(), ycmp);
    val[yord[0]] = 1;
    for(int i = 1; i < n; i++) {
        if(eq(yord[i - 1], yord[i]))
            val[yord[i]] = val[yord[i - 1]];
        else
            val[yord[i]] = val[yord[i - 1]] + 1;
    }
    //for(int i = 0; i < n; i++)
    //    cout << ord[i] << " " << val[ord[i]] << '\n';
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ans += sum(val[ord[i]] + 1);
        upd(val[ord[i]] + 1, 1);
    }
    cout << ans << endl;
}