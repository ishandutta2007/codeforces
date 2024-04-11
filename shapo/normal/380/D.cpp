#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>
#include <utility>

using namespace std;

typedef long long ll;

const ll MD = 1000000007;

#ifdef _DEBUG
#define endline endl
#else
#define endline "\n"
#endif

#define maxn 100500
#define maxk 131072

ll fac[maxn];
ll rev_fac[maxn];
ll pow2[maxn];

int min_val[2 * maxk];
int et[maxn];
int n, curk;

ll
getRev(ll base)
{
    ll res = 1LL;
    ll st = MD - 2;
    while (st) {
        if (st & 1LL) {
            res = (res * base) % MD;
        }
        st >>= 1;
        base = (base * base) % MD;
    }
    return res;
}

void
precalc(void)
{
    pow2[0] = 1LL;
    for (int i = 1; i < maxn; ++i) {
        pow2[i] = (pow2[i - 1] * 2) % MD;
    }
    fac[0] = rev_fac[0] = 1LL;
    for (int i = 1; i < maxn; ++i) {
        fac[i] = (fac[i - 1] * ll(i)) % MD;
        rev_fac[i] = getRev(fac[i]);
#ifdef _DEBUG
        assert(fac[i] * rev_fac[i] % MD == 1LL);
#endif
    }
}

int
getVal(int l, int r)
{
    l += curk - 1;
    r += curk - 1;
    int res = 0;
    while (l < r) {
        res = max(res, max(min_val[l], min_val[r]));
        l = (l + 1) / 2;
        r = (r - 1) / 2;
    }
    if (l == r) res = max(res, min_val[l]);
    return res;
}

#ifdef _DEBUG
bool
#else
void
#endif
input_data(void)
{
#ifdef _DEBUG
    if (!(cin >> n)) {
        return false;
    }
#else
    cin >> n;
#endif
    for (int i = 1; i <= n; ++i) {
        cin >> et[i];
    }
    curk = 2;
    while (curk < n) {
        curk *= 2;
    }
    for (int i = 0; i < curk; ++i) {
        min_val[curk + i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        min_val[curk + i - 1] = et[i];
    }
    for (int i = curk - 1; i > 0; --i) {
        min_val[i] = max(min_val[i * 2], min_val[2 * i + 1]);
    }
#ifdef _DEBUG
    return true;
#endif
}

ll
getBinom(int n, int k)
{
    ll a = fac[n], b = rev_fac[k], c = rev_fac[n - k];
    return (a * b % MD * c % MD);
}

void
calc(void)
{
    ll res = 0LL;
    vector < pair < int, int > > cp;
    for (int i = 1; i <= n; ++i) {
        if (et[i]) {
            cp.push_back(make_pair(et[i], i));
        }
    }
    sort(cp.begin(), cp.end());
    int cnt = int(cp.size());
    if (cnt == 0) {
        res = 1LL;
        for (int i = 0; i < n - 1; ++i) {
            res = (res + res) % MD;
        }
    } else {
        vector < pair < pair < int, int >, int > > possible;
        int cur_pos = cp[0].second, tm = cp[0].first;
        if (cur_pos >= tm && getVal(cur_pos - tm + 1, cur_pos - 1) == 0) {
            possible.push_back(make_pair(make_pair(cur_pos - tm + 1, cur_pos), (tm == 1) ? 1LL : pow2[tm - 2]));
        }
        if (tm != 1 && cur_pos + tm - 1 <= n && getVal(cur_pos + 1, cur_pos + tm - 1) == 0) {
            possible.push_back(make_pair(make_pair(cur_pos, cur_pos + tm - 1), pow2[tm - 2]));
        }
        for (int it = 1; it < cnt && possible.size() != 0; ++it) {
            vector < pair < pair < int, int >, int > > tmp;
            for (int i = 0; i < int(possible.size()); ++i) {
                pair < int, int > cur_seg = possible[i].first;
                ll counts = possible[i].second;
                int cur_l = cur_seg.first, cur_r = cur_seg.second;
                int exp_t = cp[it].first - cp[it - 1].first - 1;
                int cur_pos = cp[it].second;
                if (cur_pos > cur_r) {
                    int bet = cur_pos - cur_r - 1;
                    int lft = exp_t - bet;
                    if (bet >= 0 && lft >= 0 && cur_l - lft >= 1 && getVal(cur_l - lft, cur_l - 1) == 0 &&
                            getVal(cur_r + 1, cur_pos - 1) == 0) {
                        tmp.push_back(make_pair(make_pair(cur_l - lft, cur_pos), counts * getBinom(bet + lft, bet) % MD));
                    }
                } else {
                    int bet = cur_l - cur_pos - 1;
                    int rght = exp_t - bet;
                    if (bet >= 0 && rght >= 0 && cur_r + rght <= n && getVal(cur_r + 1, cur_r + rght) == 0 &&
                            getVal(cur_pos + 1, cur_l - 1) == 0) {
                        tmp.push_back(make_pair(make_pair(cur_pos, cur_r + rght), counts * getBinom(bet + rght, bet) % MD));
                    }
                }
            }
            possible = tmp;
        }
        for (int i = 0; i < int(possible.size()); ++i) {
            int cur_l = possible[i].first.first - 1, cur_r = n - possible[i].first.second;
            ll counts = possible[i].second;
            res = (res + counts * getBinom(cur_l + cur_r, cur_l)) % MD;
        }
    }
    cout << res << endline;
}

int
main(int argc, char **argv)
{
    precalc();
#ifndef _DEBUG
    ios_base::sync_with_stdio(false);
    input_data();
#else
    while (input_data()) {
#endif
        calc();
#ifdef _DEBUG
    }
#endif
    return 0;
}