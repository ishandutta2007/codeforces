#include <bits/stdc++.h>

#define MOD 998244353

typedef unsigned long long ll;

using namespace std;

ll n;

struct aint{
    int c[10];
};

aint toit(int a) {
    aint ans;
    for (int i = 0; i < 10; i++) {
        ans.c[i] = a % 10;
        a /= 10;
    }
    return ans;
}

ll get(aint a) {
    ll ans = 0;
    ll dom = 1;
    for (int i = 0; i < 10; i++) {
        //cout << ((ll) a.c[i]) * dom * n * (ll)11 << " ";
        ans += ((ll) a.c[i]) * dom * n * (ll)11;
        dom *= 100;
        if (dom > 1000000000)
            dom %= MOD;
    }
    //cout << ans << endl;
    return ans % MOD;
}

int main()
{
    cin >> n;
    int inc;
    //vector<aint> a(n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> inc;
        //a[i] = toit(inc);
        //for (int j = 0; j < 10; j++)
        //    cout << a[i].c[j] << " ";
        //cout << endl;
        ans += get(toit(inc));
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}