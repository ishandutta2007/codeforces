#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXK = 20;
const int MAXN = (1 << MAXK);
const int MD = 1000000007;

int cnt[MAXN];
int pow2[MAXN];
int bits[MAXN];

void
compute_submask(int from, int to)
{
    if (from == to - 1) {
        return;
    }
    compute_submask(from, (from + to) / 2);
    compute_submask((from + to) / 2, to);
    int shift = (to - from) / 2;
    for (int i = (from + to) / 2; i < to; ++i) {
        cnt[i] += cnt[i - shift];
    }
}

int
main()
{
    ios_base::sync_with_stdio(false);
    pow2[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        pow2[i] = (pow2[i - 1] + pow2[i - 1]) % MD;
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        a = (~a) & (MAXN - 1);
        ++cnt[a];
    }
    compute_submask(0, MAXN);
    bits[0] = 0;
    for (int i = 1; i < MAXN; ++i) {
        bits[i] = (bits[i / 2] + (i & 1)) & 1;
    }
    int res = 0;
    for (int i = MAXN - 1; i >= 0; --i) {
        int add_val = pow2[cnt[i]];
        if ((bits[i] ^ bits[MAXN - 1]) == 1) {
            add_val = (MD - add_val);
        }
        res = (res + add_val) % MD;
    }
    cout << res << '\n';
    return 0;
}