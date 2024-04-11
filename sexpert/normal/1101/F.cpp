#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> a, perm;
ll query[250005][4];

bool check(int ind, ll V) {
    ll rem = V;
    int s = query[ind][0], f = query[ind][1];
    ll r = query[ind][3], c = query[ind][2];
    while(s < f) {
        if(c*(a[s + 1] - a[s]) > V)
            return false;
        if(c*(a[s + 1] - a[s]) > rem) {
            rem = V;
            r--;
        }
        if(r < 0)
            return false;
        rem -= (c*(a[s + 1] - a[s]));
        s++;
    }
    return true;
}

ll bs(int ind) {
    ll lo = 0, hi = 4e18;
    while(lo < hi) {
        ll mi = (lo + hi)/2ll;
        if(check(ind, mi))
            hi = mi;
        else
            lo = mi + 1ll;
    }
    return lo;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int n, m;
    cin >> n >> m;
    a.resize(n);
    perm.resize(m);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < m; i++)
        perm[i] = i;
    shuffle(perm.begin(), perm.end(), rng);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < 4; j++) {
            cin >> query[i][j];
        }
        query[i][0]--;
        query[i][1]--;
    }
    ll ans = 0;
    for(int i = 0; i < m; i++) {
        int ind = perm[i];
        if(check(ind, ans))
            continue;
        ans = bs(ind);
    }
    cout << ans << endl;
}