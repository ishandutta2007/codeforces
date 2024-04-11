#include <bits/stdc++.h>
using namespace std;
const int MAXN = 14;
const int MAXK = 7;
typedef long long ll;
int ways[1 << MAXN][1 << MAXK][MAXN]; // [msk][str][mid] : taken msk, trace is str, end at mid
int adj[MAXN][MAXN];
int mp[1 << MAXK][1 << MAXK];
ll ans[1 << MAXN];

int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for(int j = 0; j < n; ++j) {
      adj[i][j] = s[j] == '1';
    }
  }
  for(int i = 0; i < n; ++i) {
    ways[1 << i][0][i] = 1;
  }

  for(int i = 0; i < (1 << n); ++i) {
    for(int j = 0; j < (1 << (MAXK - 1)); ++j) {
      for(int k = 0; k < n; ++k) {
        for(int nxt = 0; nxt < n; ++nxt) {
          int ni = i | (1 << nxt);
          if (i == ni) continue;
          int nj = j * 2 + adj[k][nxt];
          ways[ni][nj][nxt] += ways[i][j][k];
        }
      }
    }
  }

  int leftSize = (n - 1) / 2;
  int rightSize = n - 1 - leftSize;
  for(int lmsk = 0; lmsk < (1 << leftSize); ++lmsk) {
    for (int rmsk = 0; rmsk < (1 << rightSize); ++rmsk) {
      mp[lmsk][rmsk] = (lmsk << rightSize);
      for(int i = 0; i < rightSize; ++i) {
        int bit = (rmsk >> i) & 1;
        mp[lmsk][rmsk] += bit << (rightSize - 1 - i);
      }
    }
  }
  for(int left = 0; left < (1 << n); ++left) {
    if (__builtin_popcount(left) != leftSize) {
      continue;
    }
    for(int lmsk = 0; lmsk < (1 << leftSize); ++lmsk) {
      for (int rmsk = 0; rmsk < (1 << rightSize); ++rmsk) {
        for(int k = 0; k < n; ++k) {
          if ((left >> k) & 1) continue;
          int right = ((1 << n) - 1) ^ left;
          ll w1 = ways[left | (1 << k)][lmsk][k];
          ll w2 = ways[right][rmsk][k];
          ans[mp[lmsk][rmsk]] += w1 * w2;
        }
      }
    }
  }
  for (int i = 0; i < 1 << (n - 1); ++i) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}