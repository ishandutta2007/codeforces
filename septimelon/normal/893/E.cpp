#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int N = (int)2e6;
int mod = (int)1e9+7;

vector<int> fact;
vector<int> invfact;
vector<int> primes;

int mul(int x, int y) {
    return 1LL * x * y % mod;
}

int sum(int x, int y) {
    return (1LL * x + y) % mod;
}

int pw(int x, int deg) {
    if (deg < 0) {
        deg += mod - 1;
    }
    if (deg == 0) {
        return 1;
    }
    int ans = pw(x, deg >> 1);
    ans = mul(ans, ans);
    if (deg & 1) {
        ans = mul(ans, x);
    }
    return ans;
}

int C(int n, int k) {
    return mul(fact[n], mul(invfact[k], invfact[n - k]));
}

void prep() {
    fact.resize(N);
    invfact.resize(N);
    fact[0] = 1;
    for (int i = 1; i < N; ++i) {
        fact[i] = mul(fact[i - 1], i);
    }
    invfact[N - 1] = pw(fact[N - 1], -1);
    for (int i = N - 1; i > 0; --i) {
        invfact[i - 1] = mul(invfact[i], i);
    }

    vector<bool> used(1000001, false);
    for (int i = 2; i < 1000001; ++i) {
        if (used[i]) {
            continue;
        }
        primes.push_back(i);
        if (i < 10000) {
            for (int j = i * i; j < 1000001; j += i) {
                used[j] = true;
            }
        }
    }
}

int next() {
    int x, y;
    cin >> x >> y;
    vector<int> degs;
    int curp = 0;
    int curd = 0;
    while (x > 1) {
        if (x % primes[curp] != 0) {
            ++curp;
            if (curd > 0) {
                degs.push_back(curd);
            }
            curd = 0;
            if (x < primes[curp] * 1LL * primes[curp]) {
                degs.push_back(1);
                break;
            }
        } else {
            ++curd;
            x /= primes[curp];
        }
    }
    if (curd > 0) {
        degs.push_back(curd);
    }
    int ans = 1;
    for (int i = 0; i < degs.size(); ++i) {
        ans = mul(ans, C(degs[i] + y - 1, degs[i]));
    }
    ans = mul(ans, pw(2, y - 1));
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    prep();

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        next();
    }

    return 0;
}