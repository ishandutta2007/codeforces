#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, k;
vector<int> sack, cnt;

void knapsack(int bad) {
  sack.assign(k + 1, 0);
  sack[0] = 1;
  for(int i = 0; i < 26; i++) {
    if(i == bad)
      continue;
    for(int j = k; j >= cnt[i]; j--)
      sack[j] |= sack[j - cnt[i]];
  }
}

void solve() {
  cin >> n >> m >> k;
  string s;
  cin >> s;
  cnt.assign(26, 0);
  for(char c : s)
    cnt[c - 'A']++;
  knapsack(-1);
  //for(int i = 0; i <= k; i++)
    //  cout << sack[i] << " ";
  //cout << endl;
  for(int i = 0; i <= k; i++) {
    if(i < n || k - i < m)
      continue;
    if(sack[i]) {
      cout << "0\n";
      return;
    }
  }
  // cout << "holi" << endl;
  int ans = INT_MAX;
  for(int ch = 0; ch < 26; ch++) {
    knapsack(ch);
    int y = min(m, cnt[ch]);
    for(int x = 1; x <= min(n, cnt[ch]); x++) {
      int s;
      for(s = n - x; s <= n; s++) {
	if(sack[s])
	  break;
      }
      if(s > n)
	continue;
      while(y > 0 && y > m - k + cnt[ch] + s)
	y--;
      ans = min(ans, x * y);
    }
  }
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int q;
  cin >> q;
  while(q--)
    solve();
}