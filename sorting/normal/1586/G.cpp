#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
const int N = 4e5 + 3;
//I will need 2 * N

int n, t, s[N], r_idx[N];
array<int, 3> p[N];

struct Fenwick{
    ll a[N];

    void update(int i, ll v){
        for(; i < N; i += i & -i){
            a[i] += v;
            if(a[i] >= MOD) a[i] -= MOD;
        }
    }
    ll query(int i){
        ll r = 0;
        for(; i >= 1; i -= i & -i)
            r += a[i];
        r %= MOD;
        return r;
    }
    ll query(int l, int r){
        return (query(r) - query(l - 1) + MOD) % MOD;
    }
} f;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> p[i][0] >> p[i][1];
        p[i][2] = i + 1;
    }
    sort(p, p + n, [&](auto l, auto r){
        return l[1] < r[1];
    });
    for(int i = 0; i < n; ++i)
        r_idx[p[i][2]] = i;

    cin >> t;
    for(int i = 0; i < t; ++i){
        cin >> s[i];
        s[i] = r_idx[s[i]];
    }
    sort(s, s + t, greater<int>());
    vector<int> v{s[0]};
    for(int i = 1; i < t; ++i)
        if(p[v.back()][0] < p[s[i]][0] && p[s[i]][1] < p[v.back()][1])
            v.push_back(s[i]);

    reverse(v.begin(), v.end());
    t = v.size();
    for(int i = 0; i < t; ++i)
        s[i] = v[i];

    int j = 0;
    ll ans = 0;
    for(int i = 0; i < n; ++i){
        ll val = (f.query(p[i][0], p[i][1]) + 1) % MOD;
        if(j < t && s[j] == i){
            ++j;
            if(j < t) ans = (ans + f.query(p[s[j]][0], p[s[j]][1]) + 1) % MOD;
            else ans = (ans + f.query(1, p[s[j - 1]][1]) + 1) % MOD;
        }
        f.update(p[i][0], val);
    }

    cout << ans << "\n";
}
/*
4
1 8
2 7
3 6
4 5
4
1 2 3 4
*/