#include <algorithm>
#include <chrono>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll MOD = 1000000007;
const ld EPS = 1e11;

void mul(ll& a, ll b) {
    a = (a * b) % MOD;
}

void add(ll& a, ll b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
}

ll todeg(ll x, ll d) {
    if (d < 0) {
        d += MOD - 1;
    }
    if (d == 0) {
        return 1;
    }
    ll ans = todeg(x, d / 2);
    mul(ans, ans);
    if (d % 2 == 1) {
        mul(ans, x);
    }
    return ans;
}

vector<ll> fact, rfact;

void prep(int maxv) {
    fact.assign(maxv, 1);
    rfact.assign(maxv, 1);
    for (int i = 1; i < maxv; ++i) {
        fact[i] = i;
        mul(fact[i], fact[i - 1]);
    }
    rfact[maxv - 1] = todeg(fact[maxv - 1], -1);
    for (int i = maxv - 1; i > 0; --i) {
        rfact[i - 1] = i;
        mul(rfact[i - 1], rfact[i]);
    }
}

ll C(ll n, ll k) {
    ll ans = fact[n];
    mul(ans, rfact[k]);
    mul(ans, rfact[n - k]);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    prep(100001);

    string n;
    cin >> n;

    ll ans = 0;
    vector<ll> seq1({ 0 });
    ll cv = 0;
    for (int i = 0; i < n.size(); ++i) {
        mul(cv, 10);
        add(cv, 1);
        seq1.push_back(cv);
    }
    cv = 0;
    for (int i = 0; i < n.size(); ++i) {
        mul(cv, 10);
        add(cv, n[i] - '0');
        ll cp = cv;
        mul(cp, seq1[n.size() - i - 1]);
        add(ans, cp);
        //cout << i << ": " << cp << "\n";
    }
    cv = 1;
    for (int i = n.size() - 1; i > 0; --i) {
        ll cp = cv;
        mul(cp, n[i] - '0');
        mul(cp, C(i + 1, 2));
        add(ans, cp);
        mul(cv, 10);
        //cout << i << ": " << cp << "\n";
    }

    cout << ans << "\n";

    return 0;
}