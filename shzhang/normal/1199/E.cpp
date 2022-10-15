#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <utility>

using namespace std;

typedef long long ll;

void in(int& a)
{
    scanf("%d", &a);
}

void in(ll& a)
{
#ifdef ONLINE_JUDGE
    scanf("%I64d", &a);
#else
    scanf("%lld", &a);
#endif
}

void in(char* a)
{
    scanf("%s", a);
}

void out(int a)
{
    printf("%d ", a);
}

void out(ll a)
{
    printf("%lld ", a);
}

void out(const char* a)
{
    printf("%s ", a);
}

void newline(void)
{
    printf("\n");
}

template<class T> T gcd(T a, T b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

// Insert correct MOD value here!
#define MOD 1000000007
// 998244353, ....
// Insert correct MOD value here!
#define mul(a, b) (((ll)(a) * (ll)(b)) % MOD)
#define inv(a) fpow(a, MOD-2)
int fpow(int base, int exponent)
{
    int ans = 1;
    int cur = base;
    while (exponent) {
        if (exponent & 1) ans = mul(ans, cur);
        cur = mul(cur, cur); exponent >>= 1;
    }
    return ans;
}

bool* filter_primes(int max_value)
{
    bool* composite = new bool[max_value + 10];
    for (int i = 1; i <= max_value; i++) composite[i] = false;
    for (int i = 2; i <= max_value; i++) {
        if (composite[i]) continue;
        for (int j = 2; i * j <= max_value; j++) {
            composite[i * j] = true;
        }
    }
    for (int i = 2; i <= max_value; i++) composite[i] = !composite[i];
    composite[1] = false;
    return composite;
}

int T, n, m;
vector<pair<int, int> > graph[300005];

bool has_match[300005];

int main()
{
    in(T);
    for (int data = 1; data <= T; data++) {
        in(n); in(m);
        vector<int> edges;
        vector<int> indepset;
        for (int i = 1; i <= 3 * n; i++) graph[i].clear();
        for (int i = 1; i <= 3 * n; i++) has_match[i] = false;
        for (int i = 1; i <= m; i++) {
            int u, v;
            in(u); in(v);
            /*if (u > v) {
                int t = u; u = v; v = t;
            }*/
            graph[u].push_back(make_pair(v, i));
            graph[v].push_back(make_pair(u, i));
        }
        for (int i = 1; i <= 3 * n; i++) {
            if (!has_match[i]) {
                bool found_match = false;
                for (int j = 0; j < graph[i].size(); j++) {
                    if (!has_match[graph[i][j].first]) {
                        edges.push_back(graph[i][j].second);
                        found_match = true; has_match[i] = true;
                        has_match[graph[i][j].first] = true;
                        break;
                    }
                }
                if (!found_match) {
                    indepset.push_back(i);
                }
            }
        }
        if (indepset.size() >= n) {
            printf("IndSet\n");
            for (int i = 0; i < n; i++) printf("%d ", indepset[i]);
            printf("\n");
        } else {
            printf("Matching\n");
            for (int i = 0; i < n; i++) printf("%d ", edges[i]);
            printf("\n");
        }
    }
    return 0;
}

/* Before Submitting:
 * 1. Did the program use loop counters correctly?
 * 2. Does the program have variable name conflicts?
 * 3. Are all the arrays big enough?
 * 4. Did you use the correct integer type?
 * 5. Did you type incorrect variable names?
 * 6. Are you sure that your design is correct?
 *
 */