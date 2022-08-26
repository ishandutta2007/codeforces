#include <bits/stdc++.h>

#ifndef LOCAL
#define cerr dolor_sit_amet
#endif

#define mp make_pair
#define sz(x) ((int)((x).size()))
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int , int > ipair;
typedef pair < ll , ll > lpair;
const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = numeric_limits<double>::infinity();
const ll MOD = 1000000007;
const double EPS = 1e-9;
const int DX[] = { 1,  0, -1,  0,  1, -1,  1, -1};
const int DY[] = { 0,  1,  0, -1,  1, -1, -1,  1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll sqr(ll x) { return x*x; } ll sqr(int x) { return (ll)x*x; }
double sqr(double x) { return x*x; } ld sqr(ld x) { return x*x; }

// ========================================================================= //

const int N = 123;

int n;
int cnt[5];
int tV[5], tP[5];
bool use[5];
int ans = IINF;

void check(int k)
{
    if (k < 0)
        return;
    int resV = 0, resP = 0;
    for (int i = 0; i < 5; ++i)
    {
        ll cc = cnt[i] + (use[i] ? k : 0);
        int cost;
        ll nn = k + n;
        if (cc * 2 > nn)
            cost = 500;
        else if (cc * 4 > nn)
            cost = 1000;
        else if (cc * 8 > nn)
            cost = 1500;
        else if (cc * 16 > nn)
            cost = 2000;
        else if (cc * 32 > nn)
            cost = 2500;
        else
            cost = 3000;
        if (tV[i] != -1)
            resV += cost - tV[i] * cost / 250;
        if (tP[i] != -1)
            resP += cost - tP[i] * cost / 250;
    }
    if (resV > resP)
        ans = min(ans, k);
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < 5; ++i)
    {
        cin >> tV[i];
        if (tV[i] != -1)
            ++cnt[i];
    }
    for (int i = 0; i < 5; ++i)
    {
        cin >> tP[i];
        if (tP[i] != -1)
            ++cnt[i];
    }
    for (int j = 2; j < n; ++j)
        for (int i = 0; i < 5; ++i)
        {
            int x;
            cin >> x;
            if (x != -1)
                ++cnt[i];
        }
    for (int i = 0; i < 5; ++i)
        if (tV[i] != -1 && tP[i] != -1 && tV[i] > tP[i])
            use[i] = 1;

    check(0);
    for (int i = 0; i < 5; ++i)
    {
        if (cnt[i] == 0)
            continue;
        for (int t : {2, 4, 8, 16, 32})
        {
            check((n - cnt[i]) / (t - 1));
            check((n - cnt[i]) / (t - 1) + 1);
            check((n - cnt[i]) / (t - 1) + 2);
            check((n - cnt[i]) / (t - 1) - 1);
            check((n - cnt[i]) / (t - 1) - 2);
        }
        for (int t : {2, 4, 8, 16, 32})
        {
            check(cnt[i]*t - n);
            check(cnt[i]*t - n + 1);
            check(cnt[i]*t - n - 1);
        }
    }
    cout << (ans == IINF ? -1 : ans) << "\n";

    return 0;
}