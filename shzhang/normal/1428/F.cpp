#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

#define ll long long

#ifndef ONLINE_JUDGE
#define debug(format, ...) fprintf(stderr, \
    "%s:%d: " format "\n", __func__, __LINE__,##__VA_ARGS__)
#else
#define debug(format, ...)
#define NDEBUG
#endif

int n;
char s[500005];
int rmq1[500005][20];
int rmq2[500005][20];

void rmq_init(int rmq[500005][20], int* seq, int len)
{
    for (int i = 1; i <= len; i++) rmq[i][0] = seq[i];
    for (int pwr = 1; pwr <= 19; pwr++) {
        for (int i = 1; i + (1 << pwr) - 1 <= len; i++) {
            rmq[i][pwr] = max(rmq[i][pwr-1], rmq[i + (1 << (pwr-1))][pwr-1]);
        }
    }
}

int pwr2[500005];

int rmq_query(int rmq[500005][20], int l, int r)
{
    int pwr2val = pwr2[r - l + 1];
    return max(rmq[l][pwr2val], rmq[r - (1 << pwr2val) + 1][pwr2val]);
}

int seq1[500005], seq2[500005];

ll numsum(ll x)
{
    return ((1LL + x) * x) / 2LL;
}

ll sqsum(ll x)
{
    return (x * (x + 1LL) * (2LL * x + 1LL)) / 6LL;
}

int main()
{
    for (int i = 0; i < 20; i++) {
        for (int j = (1 << i); j < (1 << (i + 1)) && j <= 500000; j++) {
            pwr2[j] = i;
        }
    }
    scanf("%d", &n);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++) {
        if (s[i] == '0') {
            seq1[i] = 0;
        } else {
            seq1[i] = seq1[i-1] + 1;
        }
    }
    for (int i = n; i >= 1; i--) {
        if (s[i] == '0') {
            seq2[i] = 0;
        } else {
            seq2[i] = seq2[i+1] + 1;
        }
    }
    rmq_init(rmq1, seq1, n);
    rmq_init(rmq2, seq2, n);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '0') continue;
        if (s[i - 1] == '1') continue;
        for (int j = i; s[j + 1] == '1'; j++) {
            if (i == 1) {
                ans += j; continue;
            }
            int l = 1, r = i - 1;
            while (l < r) {
                int mid = (l + r) / 2;
                if (rmq_query(rmq2, mid, i - 1) >= j - i + 1) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            ans += (ll)(j - i + 1) * (ll)(i - l + 1);
        }
    }
    //printf("%lld\n", ans);
    for (int i = n; i >= 1; i--) {
        if (s[i] == '0') continue;
        if (s[i+1] == '1') continue;
        for (int j = i; s[j-1] == '1'; j--) {
            if (i == n) {
                ans += i - j + 1; continue;
            }
            int l = i + 1, r = n;
            while (l < r) {
                int mid = (l + r) / 2 + 1;
                if (rmq_query(rmq1, i + 1, mid) > i - j + 1) {
                    r = mid - 1;
                } else {
                    l = mid;
                }
            }
            ans += (ll)(i - j + 1) * (ll)(l - i + 1);
        }
    }
    //printf("%lld\n", ans);
    for (int i = 1; i <= n; i++) {
        if (s[i] != '1') continue;
        if (s[i-1] == '1') continue;
        int j;
        for (j = i; s[j] == '1'; j++) {};
        j--;
        int left_end, right_end;
        if (i == 1) {
            left_end = 1;
        } else {
            int l = 1, r = i - 1;
            while (l < r) {
                int mid = (l + r) / 2;
                if (rmq_query(rmq2, mid, i - 1) >= j - i + 1) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            left_end = l;
        }
        if (j == n) {
            right_end = n;
        } else {
            int l = j + 1, r = n;
            while (l < r) {
                int mid = (l + r) / 2 + 1;
                if (rmq_query(rmq1, j + 1, mid) > j - i + 1) {
                    r = mid - 1;
                } else {
                    l = mid;
                }
            }
            right_end = l;
        }
        ans += (ll)(i - left_end + 1) * (ll)(right_end - j + 1) * (ll)(j - i + 1);
        if (j - i + 1 >= 2) {
            ll siz = j - i - 1;
            ans += (siz + 1LL) * numsum(siz) - sqsum(siz);
        }
    }
    printf("%lld", ans);
    return 0;
}