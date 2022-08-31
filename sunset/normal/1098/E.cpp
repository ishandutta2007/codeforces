// please stop creating problems

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll f(ll a, ll b, ll c, ll n) {
  if (n < 0) {
    return 0;
  }
  if (!a) {
    return b / c * (n + 1);
  }
  if (a >= c || b >= c) {
    return f(a % c, b % c, c, n) + n * (n + 1) / 2 * (a / c) + (n + 1) * (b / c);
  }
  ll m = (a * n + b) / c;
  return n * m - f(c, c - b - 1, a, m - 1);
}

ll solve(ll a, ll b, ll c) {
  if (c < 0) {
    return 0;
  }
  ll u = c / b;
  return u + 1 + f(b, c % b, a, u);
}

ll solve(ll a, ll na, ll b, ll nb, ll c) {
  if (a * na + b * nb <= c) {
    return na * nb;
  }
  return solve(a, b, c) - solve(a, b, c - a * na) - solve(a, b, c - b * nb) + solve(a, b, c - a * na - b * nb);
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int m = *max_element(a.begin(), a.end()) + 1;
  vector<int> cnt(m);
  vector<pair<int, int>> st;
  for (int i = 0; i < n; ++i) {
    st.emplace_back(a[i], i);
    for (auto &p : st) {
      p.first = __gcd(p.first, a[i]);
    }
    vector<pair<int, int>> new_st;
    for (int j = 0; j < st.size(); ++j) {
      if (!j || st[j].first != st[j - 1].first) {
        new_st.push_back(st[j]);
      }
    }
    swap(st, new_st);
    for (int j = 0; j < st.size(); ++j) {
      cnt[st[j].first] += (j + 1 == st.size() ? i + 1 : st[j + 1].second) - st[j].second;
    }
  }
  ll d = (ll) n * (n + 1) / 2;
  d = (ll) d * (d + 1) / 2;
  d = (d + 1) / 2;
  n = m;
  vector<int> pref(n);
  vector<ll> pref_mul(n);
  for (int i = 1; i < n; ++i) {
    pref[i] = pref[i - 1] + cnt[i];
    pref_mul[i] = pref_mul[i - 1] + (ll) cnt[i] * i;
  }
  auto check = [&](ll limit) {
    ll ans = 0;
    for (int i = 1; i < n; ++i) {
      if (cnt[i]) {
        ll w = min((ll) cnt[i], limit / i);
        ans += w * cnt[i] - w * (w - 1) / 2;
      }
    }
    for (int i = 1, j = 1; i < n; ++i) {
      if (cnt[i]) {
        if (j > i) {
          ans += (ll) cnt[i] * (pref[j - 1] - pref[i]);
        }
        while (j < n && pref_mul[j] - pref_mul[i] <= limit) {
          if (j > i && cnt[j]) {
            ans += solve(i, cnt[i], j, cnt[j], limit - (pref_mul[j - 1] - pref_mul[i]) - i - j);
          }
          ++j;
        }
        if (j < n) {
          ans += solve(i, cnt[i], j, cnt[j], limit - (pref_mul[j - 1] - pref_mul[i]) - i - j);
        }
      }
    }
    return ans;
  };
  ll l = 0, r = pref_mul[n - 1];
  while (l < r) {
    ll mid = l + r >> 1;
    if (check(mid) >= d) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << r << "\n";
  return 0;
}