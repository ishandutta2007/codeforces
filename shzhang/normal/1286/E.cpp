#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

#define ll long long
#define huge __int128
#define e18 1000000000000000000LL
#define MAXV ((1 << 30) - 1)

#ifndef ONLINE_JUDGE
#define debug(format, ...) fprintf(stderr, \
    "%s:%d: " format "\n", __func__, __LINE__,##__VA_ARGS__)
#else
#define debug(format, ...)
#define NDEBUG
#endif

int n;
char s[600005];
int w[600005];
int kmp[600005];
int nonparent[600005];

int rmq[600005][20];
int log_2[600005];

int rmq_query(int l, int r)
{
    int L = log_2[r - l + 1];
    return min(rmq[l][L], rmq[r - (1 << L) + 1][L]);
}

map<int, int> freq;

int main()
{
    log_2[1] = 0;
    for (int i = 2; i <= 600000; i++) {
        if ((1 << (log_2[i-1] + 1)) == i) {
            log_2[i] = log_2[i-1] + 1;
        } else {
            log_2[i] = log_2[i-1];
        }
    }
    //root = build();
    nonparent[0] = -1;
    scanf("%d", &n);
    ll low = 0, high = 0;
    //huge ans = 0;
    ll delta = 0;
    for (int i = 1; i <= n; i++) {
        char Tmp[5];
        scanf("%s%d", Tmp, w + i);
        char c = (Tmp[0] - 'a' + (((low % 26LL) + high * (e18 % 26LL)) % 26)) % 26 + 'a';

        w[i] ^= ((low % (ll)(1 << 30)) + (high * (ll)(e18 % (1 << 30)))) % (ll)(1 << 30);
        s[i] = c;
        if (i == 1) {
            kmp[i] = 0;
        } else {
            int cur = kmp[i-1];
            while (1) {
                if (s[cur + 1] == c) {
                    kmp[i] = cur + 1; break;
                }
                if (cur == 0) break;
                cur = kmp[cur];
            }
        }
        nonparent[i] = -1;
        if (kmp[i]) {
            if (s[kmp[kmp[i]] + 1] == s[kmp[i] + 1]) {
                nonparent[i] = nonparent[kmp[i]];
            } else {
                nonparent[i] = kmp[kmp[i]];
            }
        }
        //printf("! %d %d\n", kmp[i], nonparent[i]);
        int cur = i - 1;
        while (cur > 0) {
            if (s[cur + 1] != c) {
                //printf("eliminate %d %d\n", cur, rmq_query(i - cur, i - 1));
                int x = rmq_query(i - cur, i - 1);
                freq[x]--; delta -= (ll)x;
                //modify(root, 0, MAXV, rmq_query(i - cur, i - 1), -1);
            }
            if (s[kmp[cur] + 1] != c) {
                cur = kmp[cur];
            } else {
                cur = nonparent[cur];
            }
        }
        if (c == s[1]) {
            freq[w[i]]++; delta += (ll)w[i];
            //modify(root, 0, MAXV, w[i], 1);
        }
        if (w[i] < (1 << 30) - 1) {
            //pair<ll, ll> qry = query(root, 0, MAXV, w[i] + 1, (1 << 30) - 1);
            auto iter = freq.upper_bound(w[i]);
            auto tmp = iter;
            ll tot = 0;
            while (tmp != freq.end()) {
                tot += (ll)tmp->second;
                delta -= (ll)tmp->first * (ll)tmp->second;
                tmp++;
            }
            freq.erase(iter, freq.end());
            //to_zero(root, 0, MAXV, w[i] + 1, (1 << 30) - 1);
            freq[w[i]] += tot;
            delta += tot * (ll)w[i];
            //modify(root, 0, MAXV, w[i], qry.first);
        }
        low += delta;
        while (low >= e18) {
            low -= e18; high++;
        }
        if (high) {
            printf("%lld%018lld\n", high, low);
        } else {
            printf("%lld\n", low);
        }
        rmq[i][0] = w[i];
        for (int j = 1; (1 << j) <= i; j++) {
            int from = i - (1 << j) + 1;
            rmq[from][j] = min(rmq[from][j-1],
                rmq[from + (1 << (j - 1))][j-1]);
        }
    }
    return 0;
}