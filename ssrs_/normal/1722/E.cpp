#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, q;
    cin >> n >> q;
    vector<int> h(n), w(n);
    for (int j = 0; j < n; j++){
      cin >> h[j] >> w[j];
    }
    vector<int> h2 = h, w2 = w;
    sort(h2.begin(), h2.end());
    h2.erase(unique(h2.begin(), h2.end()), h2.end());
    sort(w2.begin(), w2.end());
    w2.erase(unique(w2.begin(), w2.end()), w2.end());
    int cnt1 = h2.size();
    int cnt2 = w2.size();
    for (int j = 0; j < n; j++){
      h[j] = lower_bound(h2.begin(), h2.end(), h[j]) - h2.begin();
      w[j] = lower_bound(w2.begin(), w2.end(), w[j]) - w2.begin();
    }
    vector<vector<long long>> S(cnt1 + 1, vector<long long>(cnt2 + 1, 0));
    for (int j = 0; j < n; j++){
      S[h[j] + 1][w[j] + 1] += (long long) h2[h[j]] * w2[w[j]];
    }
    for (int j = 0; j < cnt1; j++){
      for (int k = 0; k < cnt2; k++){
        S[j + 1][k + 1] += S[j + 1][k] + S[j][k + 1] - S[j][k];
      }
    }
    for (int j = 0; j < q; j++){
      int hs, ws, hb, wb;
      cin >> hs >> ws >> hb >> wb;
      hs++;
      ws++;
      hs = lower_bound(h2.begin(), h2.end(), hs) - h2.begin();
      ws = lower_bound(w2.begin(), w2.end(), ws) - w2.begin();
      hb = lower_bound(h2.begin(), h2.end(), hb) - h2.begin();
      wb = lower_bound(w2.begin(), w2.end(), wb) - w2.begin();
      cout << S[hb][wb] - S[hs][wb] - S[hb][ws] + S[hs][ws] << "\n";
    }
  }
}