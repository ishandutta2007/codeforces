#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

#define ll long long

char origstr[200005];
int seq[200005];
int psum[200005];
int tmp[200005];
int prevone[200005];

const int kbound = 300;
int n;

int main()
{
    scanf("%s", origstr + 1);
    int pre = 0;
    for (int i = 1; origstr[i]; i++) {
        seq[i] = origstr[i] - '0';
        psum[i] = psum[i-1] + seq[i];
        n = i; prevone[i] = pre;
        if (seq[i]) pre = i;
    }
    ll ans = 0;
    for (int k = 1; k < kbound; k++) {
        for (int i = 0; i <= n; i++) {
            tmp[i] = i - k * psum[i];
        }
        sort(tmp, tmp + n + 1);
        int curfreq = 0;
        for (int i = 0; i <= n; i++) {
            curfreq++;
            if (i == n || tmp[i] != tmp[i+1]) {
                ans += (((ll)(curfreq) * (ll)(curfreq-1)) >> 1LL);
                curfreq = 0;
            }
        }
    }
    int onebound = n / kbound;
    for (int right = 1; right <= n; right++) {
        int left = (seq[right] ? right : prevone[right]);
        for (int onecnt = 1; onecnt <= onebound; onecnt++) {
            if (!left) break;
            int leftmost = prevone[left] + 1;
            int rightmost = min(left, right + 1 - onecnt * kbound);
            if (rightmost >= leftmost) {
                ans += (right - leftmost + 1) / onecnt;
                ans -= (right - rightmost) / onecnt;
            }
            left = prevone[left];
        }
    }
    printf("%lld", ans);
    return 0;
}