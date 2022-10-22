#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll P1 = 1e9 + 7;
const ll P2 = 1e5 + 7;
const ll MAXN = 1e6 + 7;
const double EPS = 1e-8;
const ll Q = 10;

ll get_hash(ll l, ll r, ll P, vector <ll> &hashs, vector <ll> &pows) {
    if (!l) {
        return hashs[r];
    }
    return (hashs[r] - hashs[l - 1] * pows[r - l + 1] % P + P) % P;
}

void init(string &s, vector <ll> &hashs, vector <ll> &pows, ll P) {
    ll n = s.size();
    hashs.resize(n, 0);
    pows.resize(n, 0);
    hashs[0] = s[0] - '0';
    pows[0] = 1;
    for (ll i = 1; i < n; i++) {
        hashs[i] = (hashs[i - 1] * Q + s[i] - '0') % P;
        pows[i] = pows[i - 1] * Q % P;
    }
}

string s;
ll n;

vector <ll> hashs1, pows1, hashs2, pows2;

void tryParse(ll a, ll b, ll c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        return;
    }
    if (a != 1 && s[0] == '0') {
        return;
    }
    if (b != 1 && s[a] == '0') {
        return;
    }
    if (c != 1 && s[a + b] == '0') {
        return;
    }
    ll hash1 = get_hash(0, a - 1, P1, hashs1, pows1);
    ll hash2 = get_hash(a, a + b - 1, P1, hashs1, pows1);
    ll hash3 = get_hash(a + b, n - 1, P1, hashs1, pows1);
    if ((hash1 + hash2) % P1 != hash3) {
        return;
    }
    hash1 = get_hash(0, a - 1, P2, hashs2, pows2);
    hash2 = get_hash(a, a + b - 1, P2, hashs2, pows2);
    hash3 = get_hash(a + b, n - 1, P2, hashs2, pows2);
    if ((hash1 + hash2) % P2 != hash3) {
        return;
    }
    cout << s.substr(0, a) << "+" << s.substr(a, b) << "=" << s.substr(a + b, c);
    exit(0);
}


int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    cin >> s;
    n = s.size();
    init(s, hashs1, pows1, P1);
    init(s, hashs2, pows2, P2);
    for (int sz = 1; sz <= n; sz++) {
        tryParse(sz, n - 2 * sz, sz);
        tryParse(sz - 1, n - 2 * sz + 1, sz);
        tryParse(n - 2 * sz, sz, sz);
        tryParse(n - 2 * sz + 1, sz - 1, sz);
    }
    assert(false);
}