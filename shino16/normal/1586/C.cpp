#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep2(i, m, n) for (auto i = (m); i < (n); i++)
#define rep(i, n) rep2(i, 0, n)
#define all(x) begin(x), end(x)

int h, w, q, l, r;
string S[1000000];
int ng[1000001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> h >> w;
  rep(i, h) S[i].reserve(w);
  rep(i, h) cin >> S[i];
  rep2(i, 1, h) rep2(j, 1, w) if (S[i-1][j] != '.' && S[i][j-1] != '.') ng[j+1] = true;
  partial_sum(all(ng), ng);
  cin >> q;
  while (q--) {
    cin >> l >> r;
    cout << (ng[r] - ng[l] ? "NO" : "YES") << '\n';
  }
}