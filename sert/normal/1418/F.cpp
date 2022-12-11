#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = (int)2e5 + 4;
const int MXD = 200;
const int INF = (int)1e6 + 41;

void solve() {
  int n, m;
  ll l, r;

  cin >> n >> m >> l >> r;

  vector<int> numD(N, 0);
  vector<vector<int>> div(N);  
  vector<int> divMaxY(N, 0);  

  for (int i = 1; i < N; i++) {    
    for (int j = i; j < N; j += i) {      
      div[j].push_back(i);
    }
  }


  set<int> rangeDiv;  

  ll yMin = 0;
  ll yMax = 0;

  int divList[MXD + 1];  
  int divNum = 0;

  vector<vector<ll>> ans;

  for (ll x1 = n; x1 >= 1; x1--) {
    //cout << x1 << endl;

    while (x1 * yMax <= r && yMax <= m) {
      for (int d : div[yMax]) {
        if (numD[d] == 0) rangeDiv.insert(d);
        numD[d]++;
        divMaxY[d] = yMax;
      }
      yMax++;
    }

    while (yMin <= m && x1 * yMin < l) {
      for (int d : div[yMin]) {
        numD[d]--;
        if (numD[d] == 0) rangeDiv.erase(d);
      }
      yMin++;
    }

    // cout << x1 << " " << yMin << " " << yMax << endl;

    if ((int)rangeDiv.size() < MXD) {
      divNum = 0;      
      for (const int &div : rangeDiv) {
        //cout << div << endl;
        divList[divNum++] = div;
      }
      divList[divNum] = INF;
    }    
    int curDiv = 0;
    // cout << "divLits: ";
    // for (int i = 0; i < divNum; i++) cout << divList[i] << " ";
    // cout << endl;

    bool fnd = false;
    for (int xDiv : div[x1]) {
      // cout << " " << xDiv << endl;
      int yDiv = -1;
      if ((int)rangeDiv.size() < MXD) {
        while (curDiv < divNum && divList[curDiv] <= xDiv)
          curDiv++;
        yDiv = divList[curDiv];
        if (yDiv == INF) break;
      } else {
        const auto &it = rangeDiv.upper_bound(xDiv);
        if (it == rangeDiv.end()) break;
        yDiv = *it;
      }
      const ll &y1 = divMaxY[yDiv];
      //cout << x1 << " " << y1 << " " << xDiv << " " << yDiv << endl;

      if ((ll)yDiv * x1 <= (ll)xDiv * n) {
        //cout << x1 << " " << y1 << " " << x1 / xDiv * yDiv << " " << y1 / yDiv * xDiv << "\n";
        ans.push_back({x1, y1, x1 / xDiv * yDiv, y1 / yDiv * xDiv});
        fnd = true;
        break;
      }
    }
    if (!fnd) ans.push_back({-1});
  }
  reverse(ans.begin(), ans.end());
  for (int x1 = 1; x1 <= (int)ans.size(); x1++) {
    const auto &v = ans[x1 - 1];
    for (int x : v) cout << x << " ";
#ifdef SERT
    if ((int)v.size() == 4) {
      ll p1 = (ll)v[0] * v[1];
      ll p2 = (ll)v[2] * v[3];
      if (v[0] > n || v[1] > m || v[2] > n || v[3] > m || min(p1, p2) < l || max(p1, p2) > r)
        cout << " ------- fail";
    }
    if ((int)v.size() == 1) {
      bool ok = false;
      ll yy1, xx2;
      for (ll y1 = (l + x1 - 1) / x1; y1 * x1 <= r && y1 <= m; y1++) {
        for (ll x2 = x1 + 1; x2 <= n; x2++) {
          if (x1 * y1 % x2 == 0) {
            yy1 = y1;
            xx2 = x2;
            ok = true;
          }
        }
      }
      if (ok) cout << " -------- fail " << x1 << " " << yy1 << " " << xx2 << " " << x1 * yy1 / xx2;
    }
#endif
    cout << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
#ifdef SERT
  t = 3;
#endif
  while (t--) solve();
}