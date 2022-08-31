#include <bits/stdc++.h>

#ifndef LOCAL
#define cerr dolor_sit_amet
#endif

#define mp make_pair
#define sz(x) ((int)((x).size()))
#define X first
#define Y second
#define ALL(x) (x).begin(), (x).end()

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int , int > ipair;
typedef pair < ll , ll > lpair;
const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = numeric_limits<double>::infinity();
const int MOD = 1000000007;
const double EPS = 1e-9;
const int DX[] = { 1,  0, -1,  0,  1, -1,  1, -1};
const int DY[] = { 0,  1,  0, -1,  1, -1, -1,  1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll sqr(ll x) { return x*x; } ll sqr(int x) { return (ll)x*x; }
double sqr(double x) { return x*x; } ld sqr(ld x) { return x*x; }
mt19937 mmtw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(mmtw) % (y - x + 1) + x; }

// ========================================================================= //

const int N = 100899;
const int S = 333;

struct Block1 {
    ipair a[S];
    int th;
    int pos;
    ll sumg;
    bool *good;
    int cntg;
    int arr[S];

    Block1() {
        th = IINF;
        for (int i = 0; i < S; ++i)
            a[i] = {arr[i] = IINF, i};
        sumg = 0;
        cntg = 0;
        pos = S;
    }

    void newTH(int nth) {
        if (nth >= th)
            return;
        if (th == IINF)
            sumg += 1LL*(nth)*cntg;
        else
            sumg += 1LL*(nth-th)*cntg;
        th = nth;
        while (pos > 0 && a[pos-1].X >= th) {
            --pos;
            if (good[a[pos].Y]) {
                ++cntg;
                if (a[pos].X == IINF) {
                    sumg += th;
                } else {
                    sumg += th - a[pos].X;
                }
            }
        }
    }

    void snake(int v, int l, int r) {
        if (l >= S || r < 0 || v >= th)
            return;
        if (l <= 0 && S-1 <= r) {
            newTH(v);
            return;
        }
        static ipair s1[S], s2[S];
        int s1s = 0, s2s = 0;
        for (int i = 0; i < S; ++i)
            if (l <= a[i].Y && a[i].Y <= r)
                s1[s1s++] = {min(a[i].X, v), a[i].Y};
            else
                s2[s2s++] = {min(a[i].X, th), a[i].Y};
        merge(s1, s1+s1s, s2, s2+s2s, a);
        th = IINF;
        pos = S;
        sumg = 0;
        cntg = 0;
        for (int i = 0; i < S; ++i)
            if (a[i].X != IINF) {
                arr[a[i].Y] = a[i].X;
                if (good[a[i].Y])
                    sumg += a[i].X;
            }
    }
};

bool good[N];
bool good1[N], good2[N];

struct Block2 {
    Block1 b1, b2;

    Block2() {
    }

    void snake(int v, int l, int r) {
        if (r < 0 || l >= S)
            return;
        if (v > 0)
            b1.snake(v, l, r);
        else
            b2.snake(-v, l, r);
    }

    ll sum(int l, int r) {
        if (r < 0 || l >= S)
            return 0;
        if (l <= 0 && S-1 <= r)
            return b1.sumg + b2.sumg;
        ll ans = 0;
        l = max(l, 0);
        r = min(r, S-1);
        for (int i = l; i <= r; ++i)
            if (b1.good[i]) {
                ans += min(b1.th, b1.arr[i]);
            }
        for (int i = l; i <= r; ++i)
            if (b1.good[i]) {
                ans += min(b2.th, b2.arr[i]);
            }
        return ans;
    }
} bb[N / S];
int q;

set < int > nogood1;
set < int > nogood2;

int main() {
    ios::sync_with_stdio(false);

    for (int i = 0; i < N; ++i)
        nogood1.insert(i);
    for (int i = 0; i < N; ++i)
        nogood2.insert(i);
    for (int i = 0; i < N / S; ++i) {
        bb[i].b1.good = good + i*S;
        bb[i].b2.good = good + i*S;
    }

    cin >> q;
    for (int i = 0; i < q; ++i) {
        int t, l, r;
        cin >> t >> l >> r;
        --r;
        if (t == 1) {
            ll y;
            cin >> y;

            for (int j = 0; j < N / S; ++j)
                bb[j].snake(y, l - j*S, r - j*S);

            auto &ng = (y > 0 ? nogood1 : nogood2);
            bool *cgood = (y > 0 ? good1 : good2);
            while (true) {
                auto it = ng.lower_bound(l);
                if (it == ng.end() || *it > r)
                    break;
                int ii = *it;
                ng.erase(it);
                cgood[ii] = true;
                if (good1[ii] && good2[ii] && !good[ii]) {
                    good[ii] = true;
                    Block1 &b1 = bb[ii/S].b1;
                    int val = min(b1.arr[ii%S], b1.th);
                    if (val != IINF) {
                        b1.sumg += val;
                    }
                    if (b1.arr[ii%S] >= b1.th)
                        ++b1.cntg;
                    Block1 &b2 = bb[ii/S].b2;
                    val = min(b2.arr[ii%S], b2.th);
                    if (val != IINF) {
                        b2.sumg += val;
                    }
                    if (b2.arr[ii%S] >= b2.th)
                        ++b2.cntg;
                }
            }
        } else {
            ll ans = 0;
            for (int j = 0; j < N/S; ++j)
                ans += bb[j].sum(l-j*S, r-j*S);
            cout << ans << "\n";
        }
    }

    return 0;
}