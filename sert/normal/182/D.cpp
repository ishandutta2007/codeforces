#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const int N = 1e5 + 7;
const ll p1 = 997;
const ll p2 = 2011;
const ll md = 1e9 + 9;

pair <ll, ll> h[N];
ll s1[N], s2[N], n;

pair <ll, ll> get_hash(int l, int r) {
    return make_pair((h[r].first - h[l].first * s1[r - l] + md * md) % md,
                     (h[r].second - h[l].second * s2[r - l] + md * md) % md);
}

bool ok;
vector <int> periods (string s) {
    vector <int> ans;
    ans.clear();
    n = s.length();
    for (int i = 0; i < n; i++) {
        h[i + 1].first = (h[i].first * p1 + s[i] - 'a' + 1) % md;
        h[i + 1].second = (h[i].second * p2 + s[i] - 'a' + 1) % md;
    }
    for (int i = 1; i <= n; i++)
        if (n % i == 0) {
            ok = true;
            for (int j = 1; ok && (j + 1) * i <= n; j++) {
                if (get_hash(0, i) != get_hash(i * j, i * j + i))
                    ok = false;
            }
            if (ok)
                ans.push_back(i);
        }
    return ans;
}

vector <int> v1, v2;
string s, t;
int ans, mx;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    s1[0] = s2[0] = 1;
    for (int i = 1; i < N; i++) {
        s1[i] = (s1[i - 1] * p1) % md;
        s2[i] = (s2[i - 1] * p2) % md;
    }

    cin >> s;
    v1 = periods(s);
    cin >> t;
    v2 = periods(t);

    while (s[mx] == t[mx])
        mx++;

    while (!v2.empty() && !v1.empty()) {
        while (v1.back() > v2.back()) {
            v1.pop_back();
            if (v1.empty())
                break;
        }
        if (!v1.empty())
            if (v1.back() == v2.back()) {
                if (v1.back() <= mx)
                    ans++;
                //cerr << v1.back() << "\n";
                v1.pop_back();
            }
        v2.pop_back();
    }

    cout << ans;

    return 0;
}