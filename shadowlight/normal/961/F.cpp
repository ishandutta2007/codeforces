#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int P = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;
const int Q = 31;

vector <ll> hashs, pows;
string s;
ll n;

void init() {
    n = s.size();
    hashs.resize(n);
    pows.resize(n);
    hashs[0] = s[0] - 'a';
    pows[0] = 1;
    for (ll i = 1; i < n; i++) {
        hashs[i] = (hashs[i - 1] * Q + (s[i] - 'a')) % P;
        pows[i] = pows[i - 1] * Q % P;
    }
}

ll get_hash(ll l, ll r) {
    if (!l) {
        return hashs[r];
    }
    return (hashs[r] - hashs[l - 1] * pows[r - l + 1] % P + P) % P;
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
    cin >> n;
    cin >> s;
    init();
    vector <ll> res((n + 1) / 2, -1);
    for (ll i = 0; i < (n + 1) / 2; i++) {
        ll l = -1, r = n + 1;
        while (r - l > 1) {
            ll mid = (l + r) / 2;
            if (i - mid < 0 || (n - i - 1 + mid) >= n) {
                r = mid;
                continue;
            }
            ll hash1 = get_hash(i - mid, i + mid);
            ll hash2 = get_hash(n - i - 1 - mid, n - i - 1 + mid);
            if (hash1 == hash2) {
                l = mid;
            } else {
                r = mid;
            }
        }
        //cout << i - l << " " << 2 * l + 1 << "\n";
        if (l > -1 && 2 * l + 1 != n) {
            res[i - l] = 2 * l + 1;
        }
    }
    cout << res[0] << " ";
    for (ll i = 1; i < (n + 1) / 2; i++) {
        res[i] = max(res[i], res[i - 1] - 2);
        cout << res[i] << " ";
    }
}