#include <bits/stdc++.h>

#define MOD 998244353

typedef unsigned long long ll;

using namespace std;

ll n;
ll len[11];
ll lenb[11];

struct aint{
    int c[10];
    int len = 99;
};

aint toit(int a) {
    aint ans;
    for (int i = 0; i < 10; i++) {
        if (a == 0) {
            ans.len = min(i, ans.len);
        }
        ans.c[i] = a % 10;
        a /= 10;
    }
    ans.len = min(10, ans.len);
    return ans;
}

ll get(aint a) {
    ll ans = 0;
    ll dom = 1;
    for (int i = 0; i < 10; i++) {
        //cout << ((ll) a.c[i]) * dom * n * (ll)11 << " ";
        ans += ((ll) a.c[i]) * dom * (n - lenb[i+1]) * (ll)11;
        dom *= 100;
        if (dom > 1000000000)
            dom %= MOD;
    }
    //cout << ans << endl;
    ll domb = 10;
    for (int i = 1; i < 10; i++) {
        domb *= 10;
        if (domb > 1000000000)
            domb %= MOD;
        dom = domb;
        for (int j = 1; j <= i; j++) {
            ans += ((ll) a.c[i]) * dom * len[j] * (ll)2;
            dom *= 10;
            if (dom > 1000000000)
                dom %= MOD;
        }
    }
    //cout << ans << endl;
    return ans % MOD;
}

int main()
{
    cin >> n;
    int inc;
    vector<aint> a(n);
    ll ans = 0;
    for (int i = 0; i < 11; i++)
        len[i] = 0;
    for (int i = 0; i < 11; i++)
        lenb[i] = 0;
    for (int i = 0; i < n; i++) {
        cin >> inc;
        a[i] = toit(inc);
        //cout << a[i].len << endl;
        len[a[i].len]++;
    }
    for (int i = 1; i < 11; i++) {
        lenb[i] = lenb[i-1] + len[i-1];
        //cout << lenb[i] << endl;
    }
    for (int i = 0; i < n; i++) {
        ans += get(a[i]);
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}