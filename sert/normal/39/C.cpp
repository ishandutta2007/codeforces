#include <bits/stdc++.h>
using namespace std;

const int INF = (int)1e9 + 41;

void getAns(vector<int> &ans, int len, int pos, vector<vector<pair<int, bool>>> &dp, vector<pair<int, int>> &b, vector<int> &match) {
  //cout << "ans: " << len << " " << pos << " " << dp[len][pos].second << endl;
  if (len == 0) return;
  if (dp[len][pos].second) {
    ans.push_back(b[pos].second);
    getAns(ans, match[pos] - pos - 1, pos + 1, dp, b, match);
    getAns(ans, pos + len - match[pos] - 1, match[pos] + 1, dp, b, match);
  } else {
    getAns(ans, len - 1, pos + 1, dp, b, match);
  }
}

int solve(vector<int> cc = {}, vector<int> rr = {}) {
  int n;
  if (cc.empty()) cin >> n;
  else n = cc.size();

  vector<int> c(n), r(n);
  vector<pair<int, int>> b;

  if (cc.empty()) {
    for (int i = 0; i < n; i++) {
      cin >> c[i] >> r[i];      
    }
  } else {
    c = cc;
    r = rr;
  }

  for (int i = 0; i < n; i++) {
    b.emplace_back(c[i] - r[i], i);
    b.emplace_back(c[i] + r[i], i);
  }

  sort(b.begin(), b.end(), [&](const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first != b.first) return a.first < b.first;
    int ca = c[a.second];
    int cb = c[b.second];
    if (ca > a.first && cb > b.first) return ca > cb;
    if (ca < a.first && cb < b.first) return ca > cb;
    return ca < cb;
  });

  vector<int> leftPos(n), rightPos(n);  
  int m = b.size();

  for (int i = 0; i < m; i++) {
    if (b[i].first < c[b[i].second]) leftPos[b[i].second] = i;
    else rightPos[b[i].second] = i;
  }

  vector<int> match(m);
  for (int i = 0; i < n; i++) {
    match[leftPos[i]] = rightPos[i];
    match[rightPos[i]] = leftPos[i];
    //cout << leftPos[i] << " " << rightPos[i] << endl;
  }

  vector<vector<pair<int, bool>>> dp(m + 1, vector<pair<int, bool>>(m + 1, make_pair(0, false)));

  for (int len = 2; len <= m; len++) {
    for (int pos = 0; pos + len <= m; pos++) {
      if (dp[len - 1][pos + 1] > dp[len][pos]) {
        dp[len][pos] = dp[len - 1][pos + 1];
        dp[len][pos].second = false;
      }

      int p2 = match[pos];
      if (p2 < pos || p2 >= pos + len) continue;
      int cur = 1 + dp[p2 - pos - 1][pos + 1].first + dp[pos + len - p2 - 1][p2 + 1].first;
      if (cur > dp[len][pos].first) {
        dp[len][pos].first = cur;
        dp[len][pos].second = true;
      }

      //cout << len << " " << pos << " " << dp[len][pos].first << " " << dp[len][pos].second << endl;
    }
  }

  // for (int i = 0; i < m; i++)
  //   cout << b[i].second << " ";
  // cout <<  "\n";

  vector<int> ans;
  getAns(ans, m, 0, dp, b, match);

  if (!cc.empty()) return ans.size();

  cout << ans.size() << "\n";
  for (int x : ans)
    cout << x + 1 << " ";
  cout << "\n";
  return ans.size();

#ifdef SERT
  
#endif
}

int kek(vector<int> c, vector<int> r) {
  // cout << "in kek" << endl;
  int n = r.size();
  int ans = 0;
  int bmsk;

  vector<int> x(n), y(n);
  for (int i = 0; i < n; i++) {
    x[i] = c[i] - r[i];
    y[i] = c[i] + r[i];
  }

  for (int msk = 0; msk < (1 << n); msk++) {
    int bc = __builtin_popcount(msk);
    if (bc <= ans) continue;
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if ((msk & (1 << i)) == 0) continue;
      for (int j = i + 1; j < n; j++) {
        if ((msk & (1 << j)) == 0) continue;
        bool a1 = false, a2 = false, a3 = false, a4 = false;
        if (x[i] < x[j] && x[j] < y[i]) a1 = true;
        if (x[i] < y[j] && y[j] < y[i]) a2 = true;
        if (x[j] < x[i] && x[i] < y[j]) a3 = true;
        if (x[j] < y[i] && y[i] < y[j]) a4 = true;
        if ((a1 || a2) && (a3 || a4)) ok = false;
      }
    }
    if (ok) {
      ans = bc;
      bmsk = msk;
    }
  }
  // for (int i = 0; i < n; i++)
  //   if (bmsk & (1 << i))
  //     cout << i + 1 << " ";
  // cout << endl;
  // cout << "out kek" << endl;
  return ans;
}

void test(int n) {
  vector<int> r(n), c(n);
  set<pair<int, int>> s;
  for (int i = 0; i < n; i++) {
    while (true) {
      c[i] = rand() % n;
      r[i] = 1 + rand() % (n / 2);
      if (s.find(make_pair(c[i], r[i])) == s.end()) {
        s.insert(make_pair(c[i], r[i]));
        break;
      }
    }
  }

  int a1 = solve(c, r);
  int a2 = kek(c, r);

  if (a1 != a2) {
    for (int i = 0; i < n; i++)
      cout << c[i] << " " << r[i] << endl;

    cout << "Stress: " << a2 << " Main: " << a1 << endl;
    exit(0);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
  for (int i = 0; i < 10000; i++) {
    test(7);
  }
}