#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

int
gcd(int a, int b)
{
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

typedef long long ll;

const int MAXN = 1050;


int n;
int l[MAXN], c[MAXN];
ll val[2048][2];
ll ans = -1ll;

ll
find_cost(vector< int > masks, vector< ll > costs, int max_mask, ll start_cost)
{
    const ll MAXVAL = 1000000000000000LL;
    for (int i = 0; i < max_mask; ++i) {
        val[i][0] = val[i][1] = MAXVAL;
    }
    val[max_mask - 1][0] = start_cost;
    int cur_pos = 0;
    int cnt = int(masks.size());
    for (int i = 0; i < cnt; ++i) {
        int cur_mask = masks[i];
        int next_pos = cur_pos ^ 1;
        for (int vm = max_mask - 1; vm >= 0; --vm) {
            val[vm][next_pos] = min(val[vm][next_pos], val[vm][cur_pos]);
            int go_mask = vm & cur_mask;
            val[go_mask][next_pos] = min(val[go_mask][next_pos], val[vm][cur_pos] + costs[i]);
        }
        cur_pos = next_pos;
    }
    return (val[0][cur_pos] == MAXVAL) ? -1 : val[0][cur_pos];
}

int
main()
{
    scanf("%d", &n);
    int cur_gcd = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &l[i]);
        cur_gcd = gcd(cur_gcd, l[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &c[i]);
    }
    if (cur_gcd != 1) {
        printf("-1\n");
    } else {
        for (int i = 0; i < n; ++i) {
            vector< int > primes;
            int x = l[i];
            for (int j = 2; j * j <= x; ++j) {
                if (x % j == 0) {
                    primes.push_back(j);
                    while (x % j == 0) {
                        x /= j;
                    }
                }
            }
            if (x != 1) {
                primes.push_back(x);
            }
            vector< ll > cs;
            vector< int > ms;
            int p_cnt = int(primes.size());
            for (int j = 0; j < n; ++j) {
                if (i == j) {
                    continue;
                }
                int cur_mask = 0;
                for (int k = 0; k < p_cnt; ++k) {
                    if (l[j] % primes[k] == 0) {
                        cur_mask |= (1 << k);
                    }
                }
                ms.push_back(cur_mask);
                cs.push_back(c[j]);
            }
            ll cur_val = find_cost(ms, cs, (1 << p_cnt), c[i]);
            if (cur_val != -1ll && (ans == -1ll || ans > cur_val)) {
                ans = cur_val;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}