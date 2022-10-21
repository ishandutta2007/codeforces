#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e5 + 50, BK = 300, BKSIZE = 400;
const int mod = 998244353;

int n, k;
int num[N];
int la[N], pv[N];
int dp[N];
int curi = 0;

struct Arr{
    ll a[N];
    int mp[BK][2 * N];
    int off[BK];
    ll sum = 0;

    void init(int i) {
        mp[i / BKSIZE][a[i] + N] = (mp[i / BKSIZE][a[i] + N] + g(i)) % mod;
        sum += g(i);
        sum %= mod;
    }


    int g(int x) {
        return x == 0 ? 1 : dp[x-1];
    }

    void add_single(int i, int val) {
        int bk = i / BKSIZE;
        mp[bk][a[i] + N]  = (mp[bk][a[i] + N] - g(i)) % mod;
        sum -= ((a[i] + off[bk]) <= k) * g(i);

        a[i] += val;

        mp[bk][a[i] + N] = (mp[bk][a[i] + N] + g(i)) % mod;
        sum += ((a[i] + off[bk]) <= k) * g(i);
        sum %= mod;

    }

    void add(int l, int r, int val) {
        while(l % BKSIZE != 0 && l <= r) {
            add_single(l, val);
            l++;
        }
        while((r + 1) % BKSIZE != 0 && l <= r) {
            add_single(r, val);
            r--;
        }
        if(l <= r) {
            assert(l % BKSIZE == 0);
            for(int bk = l / BKSIZE; bk <= r / BKSIZE; bk++) {
                if(val > 0 && k - off[bk] + N < 2 * N) {
                    sum -= mp[bk][k - off[bk] + N];
                    sum %= mod;
                }
                off[bk] += val;
                if(val < 0 && k - off[bk] + N < 2 * N) {
                    sum += mp[bk][k - off[bk] + N];
                    sum %= mod;
                }
            }
        }


    }

} A;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> num[i];
    fill(la, la + n + 1, -1);
    for(int i = 0; i < n; i++) {
        pv[i] = la[num[i]];
        la[num[i]] = i;
    }
    ll res = 0;
    for(int i = curi = 0; i < n; i++, curi++) {
        A.init(i);
        int p = pv[i];
        A.add(p + 1, i, 1);
        if(p != -1) {
            A.add(pv[p] + 1, p, -1);
        }
        dp[i] = (int)A.sum;
    }
    cout << (dp[n - 1] % mod + mod) % mod << '\n';
}