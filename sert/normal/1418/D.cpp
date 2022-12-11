#include <bits/stdc++.h>
using namespace std;

void solve() {
  set<pair<int, int>> gaps;
  set<int> coords;
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int &x : a) {
    cin >> x;
    coords.insert(x);
  }
  sort(a.begin(), a.end());


  auto ins = [&](int from, int to) {
    //cout << "+ " << from << " " << to << endl;
    gaps.insert(make_pair(to - from, from));
  };

  auto del = [&](int from, int to) {
    //cout << "- " << from << " " << to << endl;
    gaps.erase(make_pair(to - from, from));
  };

  for (int i = 1; i < n; i++) {
    ins(a[i - 1], a[i]);    
  }

  auto getAns = [&]() {
    if ((int)coords.size() <= 2) return 0;
    int mx = *(coords.rbegin());
    int mn = *(coords.begin());
    int mxGap = gaps.rbegin()->first;
    return mx - mn - mxGap;
  };  



  cout << getAns() << "\n";  

  while (m--) {    
    int t, x;
    cin >> t >> x;
    int mx = coords.empty() ? 0 : *(coords.rbegin());
    int mn = coords.empty() ? 0 : *(coords.begin());

    //cout << "----" << t << " " << x << endl;
    //cout << "a " << coords.size() << " " << flush;

    if (t == 1) {
      if (!coords.empty()) {
        if (x > mx) {
          ins(mx, x);        
        } else if (x < mn) {
          ins(x, mn);        
        } else {
          auto it = coords.upper_bound(x);
          int nx = *it;
          it--;
          int pr = *it;
          del(pr, nx);
          ins(pr, x);
          ins(x, nx);
        }
      }
      coords.insert(x);
    } else {
      int pr = -1;
      int nx = -1;

      if (x < mx) {
        nx = *(coords.upper_bound(x));
        del(x, nx);        
      }
      if (x > mn) {
        auto it = coords.find(x);
        it--;
        pr = *it;
        del(pr, x);
      }      

      if (pr != -1 && nx != -1)
        ins(pr, nx);
      coords.erase(x);
    }

    cout << getAns() << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
#ifdef SERT
  t = 1;
#endif
  while (t--) solve();
}