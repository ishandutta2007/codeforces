//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("fast-math")
/*#pragma GCC optimize("section-anchors")
#pragma GCC optimize("profile-values,profile-reorder-functions,tracer")
#pragma GCC optimize("vpt")
#pragma GCC optimize("rename-registers")
#pragma GCC optimize("move-loop-invariants")
#pragma GCC optimize("unswitch-loops")
#pragma GCC optimize("function-sections")
#pragma GCC optimize("data-sections")
#pragma GCC optimize("branch-target-load-optimize")
#pragma GCC optimize("branch-target-load-optimize2")
#pragma GCC optimize("btr-bb-exclusive")*/
//#pragma GCC optimize("inline")
//#pragma comment(linker, "/STACK:167077260")
#define _CRT_SECURE_NO_WARNINGS
#include <chrono>
#include <set>
#include <map>
#include <deque>
#include <string>
#include <cstdint>
#include <cmath>
#include <queue>
#include <cassert>
#include <random>
#include <bitset>
#include <iomanip>
#include <numeric>
#include <time.h>//////////////
#include <ctime>
#include <climits>
#include <string>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
//++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++
//#define endl '\n'
#define mp make_pair
#define pbc push_back
#define pob pop_back()
#define empb emplace_back
#define queuel queue<long long>
#define sqr(a) ((a) * (a))
#define lsqr(a) (ld(a) * a)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pin(p) cin >> p.first >> p.second;
#define uniq(a) sort(all(a));(a).resize(unique(all(a)) - a.begin());
#define rev(v) reverse(v.begin(), v.end());
#define sout(s, c) for (auto i : s) cout << i << c;
#define pout(p) cout << p.first << " " << p.second;
#define er(v, l, r) erase(v.begin() + l, v.begin() + r);
#define vin(v) for (ll i = 0; i < v.size(); ++i) cin >> v[i];
#define vout(v, c) for (int i = 0; i < v.size(); ++i) cout << v[i] << c;
#define pushi(v, a) for (int i = 0; i < a.size(); ++i) v.push_back(a[i]);
#define fastio() ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0); srand(time(NULL))
#define dab(v) for(auto i:v)cout<<i<<' ';
#define sp system("pause")
#define left left228
#define calc calc228
#define next next228
#define type type1337
#define right right228
//++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++
using namespace std;
//++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
//++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++
const ld EPS = 0;
const ld EPS2 = 1e-12;
const ld PI = acos(-1);
int mod = (int)998244353;
const int MOD7 = 1000000007;
const int MOD9 = 1000000009;
const int a228 = 18;
const int inf = 1e9;
mt19937 rnd(time(0));
const ll kekmod = 1791791791;
const ll bestmod = 1148822869;
const int MAXN = 5e5 + 1;
#define int ll
int n;
string s;
struct vt
{
    ll sm, mn;
    vt(ll a, ll b)
    {
        sm = a, mn = b;
    }
    vt()
    {
        sm = mn = 0;
    }
};
vt t[4 * MAXN];
pair<int, int> add[4 * MAXN];
inline vt merge(vt a, vt b)
{
    return { a.sm + b.sm, min(a.mn, b.mn) };
}
ll ans = 0;
vt pull(int v, int l, int r)
{
    if (add[v].first != -228)
    {
        vt ans = { (r - l) * add[v].first, add[v].first };
        //dadd[v] = { -228,0 };
        //t[v] = ans;
        return ans;
    }
    if (add[v].second)
    {
        vt ans = { t[v].sm + (r - l) * add[v].second, t[v].mn + add[v].second };
        //add[v] = { -228,0 };
        //t[v] = ans;
        return ans;
    }
    return t[v];
}
void push(int v, int l, int r)
{
    if (l != r - 1)
    {
        if (add[v].first > -228)
        {
            add[2 * v + 1].first = add[2 * v + 2].first = add[v].first;
            add[v].first = -228;
        }
        add[2 * v + 1].second += add[v].second, add[2 * v + 2].second += add[v].second;
        add[v].second = 0;
        t[v] = merge(pull(2 * v + 1, l, (l + r) / 2), pull(2 * v + 2, (l + r) / 2, r));
        return;
    }
    t[v] = pull(v, l, r);
    add[v] = {-228, 0};
}

void upd1(int v, int l, int r, int ql, int qr, int x)
{
    if (l >= qr || ql >= r) return;
    push(v, l, r);

    if (l >= ql && r <= qr)
    {
        add[v].first = x;
        return;
    }
    upd1(2 * v + 1, l, (l + r) / 2, ql, qr, x);
    upd1(2 * v + 2, (l + r) / 2, r, ql, qr, x);
    t[v] = merge(pull(2 * v + 1, l, (l + r) / 2), pull(2 * v + 2, (l + r) / 2, r));
}

void upd2(int v, int l, int r, int ql, int qr)
{
    if (l >= qr || ql >= r) return;
    push(v, l, r);

    if (l >= ql && r <= qr)
    {
        add[v].second++;
        return;
    }
    upd2(2 * v + 1, l, (l + r) / 2, ql, qr);
    upd2(2 * v + 2, (l + r) / 2, r, ql, qr);
    t[v] = merge(pull(2 * v + 1, l, (l + r) / 2), pull(2 * v + 2, (l + r) / 2, r));
}

int go(int v, int l, int r, int pf, int x)
{
    if (l >= pf)return -228;
    push(v, l, r);

    if (l == r - 1 && t[v].mn < x) return l;

    if (t[v].mn < x)
    {
        int nw = go(2 * v + 1, l, (l + r) / 2, pf, x);
        if (nw == -228)
            nw = go(2 * v + 2, (l + r) / 2, r, pf, x);
        t[v] = merge(pull(2 * v + 1, l, (l + r) / 2), pull(2 * v + 2, (l + r) / 2, r));
        return nw;
    }
    return -228;
}

signed main()
{
    fastio();
    for (int i = 0; i < 4 * MAXN; ++i) add[i] = { -228,0 };
    for (int i = 0; i < 4 * MAXN; ++i) t[i] = { 0,0 };
    cin >> n >> s;
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '0')
        {
            cnt = 0;
        }
        else
        {

            ++cnt;
            upd2(0, 0, n, i - cnt + 1, i + 1);
            //cout << "cnt = " << cnt << endl;
            //cout << "upd2 = " << i - cnt + 1 << " " << i << endl;
            int rofl = go(0, 0, n, i - cnt + 1, cnt);
            //cout << "rofl = " << rofl << endl;
            if (rofl > -228) upd1(0, 0, n, rofl, i - cnt + 1, cnt);
        }
        //cout << pull(0, 0, n).sm << endl;
        ans += pull(0, 0, n).sm;
    }
    cout << ans << endl;
    //sp;
}