#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 1e6 + 10;
ll res, x, y, ans[MAX];
int n, pr[MAX], cnt[MAX];
vector<int> v, divs;

void solve(int p) {
    ll cur = 0;
    for(auto k : v) {
        int d = ((k % p) ? (p - (k % p)) : 0);
        cur += min(x, y * d);
        if(cur >= res)
            return;
    }
    res = cur;
}

vector<int> pf(int x) {
    vector<int> res;
    while(x > 1) {
        int p = pr[x];
        while(x % p == 0)
            x /= p;
        res.push_back(p);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    mt19937 rnd;

    for(int p = 2; p < MAX; p++) {
        if(pr[p])
            continue;
        for(int q = p; q < MAX; q += p)
            pr[q] = p;
    }
    cin >> n >> x >> y;
    v.resize(n);
    for(auto &k : v)
        cin >> k;
    shuffle(v.begin(), v.end(), rnd);
    res = min(x * n, y * n);
    if(x >= 2 * y) {
        for(int i = 0; i < 30; i++) {
            int idx = rnd() % n;
            for(auto p : pf(v[idx]))
                solve(p);
            for(auto p : pf(v[idx] + 1))
                solve(p);
        }
        cout << res << '\n';
        return 0;
    }
    else {
        for(int i = 0; i < n; i++) {
            for(int j = v[i]; j <= v[i] + 1; j++) {
                for(auto p : pf(j)) {
                    cnt[p]++;
                    ans[p] += min(x, y * (j - v[i]));
                }
            }
        }
        for(int p = 2; p < MAX; p++) {
            if(pr[p] != p)
                continue;
            res = min(res, ans[p] + x * (n - cnt[p]));
        } 
    }
    cout << res << '\n';
}