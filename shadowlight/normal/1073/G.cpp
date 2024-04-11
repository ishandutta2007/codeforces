#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const ll MAXN = 1e6 + 7;
const double EPS = 1e-8;
const ll LOGN = 30;
const ll Q = 50;

struct State {
    ll x, y, id;
};

vector <ll> construct(string &s) {
    s += (char) ('a' - 1);
    ll n = s.size();
    vector <ll> suffs(n, 0), classes(n, 0);
    vector <ll> cnt(Q, 0);
    ll last = Q;
    for (ll i = 0; i < n; i++) {
        classes[i] = s[i] - 'a' + 3;
        cnt[classes[i]]++;
    }
    for (ll i = 1; i < Q; i++) {
        cnt[i] += cnt[i - 1];
    }
    for (ll i = 0; i < n; i++) {
        ll w = s[i] - 'a' + 3;
        suffs[cnt[w - 1]++] = i;
    }
    cnt.clear();
    last = 0;
    for (ll i = 0; i < n; i++) {
        if (!i || s[suffs[i - 1]] != s[suffs[i]]) {
            last++;
        }
        classes[suffs[i]] = last;
    }
    cnt.resize(last + 1, 0);
    ll len = 1;
    while (len < n) {
        for (ll i = 0; i < n; i++) {
            cnt[classes[i]]++;
        }
        for (ll i = 1; i <= last; i++) {
            cnt[i] += cnt[i - 1];
        }
        vector <ll> suffs1(n, 0);
        for (ll i = 0; i < n; i++) {
            ll j = (suffs[i] - len + n) % n;
            suffs1[cnt[classes[j] - 1]++] = j;
        }
        suffs = suffs1;
        ll last1 = 0;
        vector <ll> classes1(n, 0);
        for (ll i = 0; i < n; i++) {
            if (!i) {
                last1++;
            } else {
                ll w1 = classes[suffs[i - 1]], w2 = classes[suffs[i]];
                ll d1 = classes[(suffs[i - 1] + len) % n], d2 = classes[(suffs[i] + len) % n];
                if (w1 != w2 || d1 != d2) {
                    last1++;
                }
            }
            classes1[suffs[i]] = last1;
        }
        cnt.clear();
        cnt.resize(last1 + 1, 0);
        last = last1;
        classes = classes1;
        len *= 2;
//        cout << "###\n";
//        for (ll x : suffs) {
//            cout << x << " ";
//        }
//        cout << "\n";
//        for (ll x : classes) {
//            cout << x << " ";
//        }
//        cout << "\n";
    }
    return suffs;
}

vector <ll> build_lcp(string s, vector <ll> suff) {
    ll n = suff.size();
    vector <ll> rsuff(n, -1);
    for (ll i = 0; i < n; i++) {
        rsuff[suff[i]] = i;
    }
    vector <ll> lcp(n, 0);
    ll pos = rsuff[0];
    assert(pos);
    ll k = suff[pos - 1];
    while (k + lcp[pos] < n && s[lcp[pos]] == s[k + lcp[pos]]) {
        lcp[pos]++;
    }
    for (ll i = 1; i < n - 1; i++) {
        ll q = rsuff[i];
        ll p = rsuff[i - 1];
        lcp[q] = max(lcp[p] - 1, 0LL);
        ll k = suff[q - 1];
        while (max(k, i) + lcp[q] < n && s[k + lcp[q]] == s[i + lcp[q]]) {
            lcp[q]++;
        }
    }
    return lcp;
}

vector <vector <ll> > segmin;

ll get(ll l, ll r) {
    assert(l <= r);
    assert(0 <= l && l < segmin[0].size());
    assert(0 <= r && r < segmin[0].size());
    ll k = log2(r - l + 1);
    return min(segmin[k][l], segmin[k][r - (1 << k) + 1]);
}

vector <ll> sa, lcp, rsa;

void query() {
    ll n = sa.size();
    ll sza, szb;
    cin >> sza >> szb;
    vector <ll> a(sza), b(szb);
    for (ll j = 0; j < sza; j++) {
        ll x;
        cin >> x;
        x--;
        assert(x < rsa.size());
        a[j] = rsa[x];
    }
    for (ll j = 0; j < szb; j++) {
        ll x;
        cin >> x;
        x--;
        assert(x < rsa.size());
        b[j] = rsa[x];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector <ll> prefs(szb, 0), sufs(szb, 0);
    for (ll i = 1; i < szb; i++) {
        ll x = get(b[i - 1] + 1, b[i]);
        ll l = -1, r = i;
        while (r - l > 1) {
            ll mid = (l + r) / 2;
            ll y = get(b[mid] + 1, b[i]);
            if (y == x) {
                r = mid;
            } else {
                l = mid;
            }
        }
        assert(r < szb);
        prefs[i] = prefs[r] + (i - r) * x;
    }
    for (ll i = szb - 2; i >= 0; i--) {
        ll x = get(b[i] + 1, b[i + 1]);
        ll l = i + 1, r = szb;
        while (r - l > 1) {
            ll mid = (l + r) / 2;
            ll y = get(b[i] + 1, b[mid]);
            if (y == x) {
                l = mid;
            } else {
                r = mid;
            }
        }
        assert(l < szb);
        sufs[i] = sufs[l] + (l - i) * x;
    }
    ll res = 0;
    for (ll x : a) {
        ll pos = lower_bound(b.begin(), b.end(), x) - b.begin();
        if (pos < szb && b[pos] == x) {
            //cout << n - sa[x] - 1 << "\n";
            res += prefs[pos] + sufs[pos] + (n - sa[x] - 1);
            continue;
        }
        if (pos > 0) {
            ll t = get(b[pos - 1] + 1, x);
            ll l = -1, r = pos - 1;
            while (r - l > 1) {
                ll mid = (l + r) / 2;
                ll t1 = get(b[mid] + 1, x);
                if (t1 == t) {
                    r = mid;
                } else {
                    l = mid;
                }
            }
            res += prefs[r] + (pos - r) * t;
        }
        if (pos < szb) {
            ll t = get(x + 1, b[pos]);
            ll l = pos, r = szb;
            while (r - l > 1) {
                ll mid = (l + r) / 2;
                ll t1 = get(x + 1, b[mid]);
                if (t1 == t) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            res += sufs[l] + (l - pos + 1) * t;
        }
    }
    cout << res << "\n";
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
    ll n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    sa = construct(s);
    lcp = build_lcp(s, sa);
    rsa.resize(n + 1);
//    for (ll x : sa) {
//        cout << x << " ";
//    }
//    cout << "\n";
    for (ll i = 0; i <= n; i++) {
        rsa[sa[i]] = i;
    }
//    for (ll x : lcp) {
//        cout << x << " ";
//    }
//    cout << "\n";
    segmin.resize(LOGN, vector <ll> (n + 1, 0));
    segmin[0] = lcp;
    for (ll k = 1; k < LOGN; k++) {
        for (ll i = 0; i < n; i++) {
            if (i + (1 << (k - 1)) > n) break;
            segmin[k][i] = min(segmin[k - 1][i], segmin[k - 1][i + (1 << (k - 1))]);
        }
    }
    for (ll i = 0; i < q; i++) {
        query();
    }
}