#include <bits/stdc++.h>
using namespace std;

const int INF = (int)1e9 + 41;

void solve() {
  int m, k;
  cin >> m >> k;
  vector<int> num(k);
  for (int i = 0; i < k; i++)
    cin >> num[i];

  vector<int> food(m), sad(m);
  for (int i = 0; i < m - 1; i++) {
    cin >> food[i] >> sad[i];
    food[i]--;    
  }
  food.back() = -34;
  
  int pos1 = -1;
  int numAny = 0;
  for (pos1 = 0; sad[pos1] == 0 && pos1 < m - 1; pos1++) {
    if (food[pos1] == -1) numAny++;      
  }

  vector<bool> fas(k, false);
  for (int i = pos1 + 1; i < m - 1; i++)
    if (food[i] != -1)
      fas[food[i]] = true;

  for (int i = 0; i < min(m - 1, pos1 + 1); i++)
    if (food[i] != -1)
      num[food[i]]--;

  vector<bool> ans(k, false);
  int minEmpty = m + k;
  for (int i = 0; i < k; i++) {
    if (food[pos1] == i) continue;
    if (!fas[i] && num[i] <= numAny)
      ans[i] = true;
    if (!fas[i])
      minEmpty = min(minEmpty, num[i]);
  }  
  
  if (food[pos1] == -1) numAny++;
  for (int i = pos1 + 1; i < m - 1; i++) {
    if (food[i] != -1)
      num[food[i]]--;
    else
      numAny++;
  }

  for (int i = 0; i < k; i++)
    if (num[i] <= numAny - minEmpty)
      ans[i] = true;

  for (int i = 0; i < k; i++) {
    cout << (ans[i] ? "Y" : "N");
  }
  cout << "\n";    
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}