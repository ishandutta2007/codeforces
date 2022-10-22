#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;

const int N = 1e6 + 130;
const int M = 1e9 + 7;

int pow2(int n, int k) {
    if(k == 0)
        return 1;

    int pw = pow2(n, k / 2);
    if(k & 1)
        return pw * 1ll * pw % M * 1ll * n % M;
    else
        return pw * 1ll * pw % M;
}

int is[N];
int f[N], r[N];

int C(int n, int k) {
    return f[n] * 1ll * r[k] % M * 1ll * r[n - k] % M;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int cur = 0;
    for(int i = 2; i < N; i++) {
        if(is[i] == 0) {
            is[i] = i;
//            p[i] = cur++;
            if(i * 1ll * i < N)
                for(int j = i * i; j < N; j += i)
                    is[j] = i;
        }
    }

    f[0] = 1;
    r[0] = 1;
    for(int i = 1; i < N; i++) {
        f[i] = f[i - 1] * 1ll * i % M;
        r[i] = pow2(f[i], M - 2);
    }

    int q;
    cin >> q;

    while(q--) {
        int x, y;
        cin >> x >> y;

        map<int, int> mp;
        while(x > 1) {
            mp[is[x]]++;
            x /= is[x];
        }

        int ans = 1;
        for(auto pp : mp) {
//            cout << pp.f << ' ' << pp.s << endl;
            int cnt = pp.s;
            ans = ans * 1ll * C(y + cnt - 1, cnt) % M;
        }

        cout << ans * 1ll * pow2(2, y - 1) % M << '\n';
    }
}