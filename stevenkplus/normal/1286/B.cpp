#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
const int MAXN = 2222;
int ans[MAXN];
int ar[MAXN];
int p[MAXN];
int cnt[MAXN];
vector<int> subtrees[MAXN];

int c = 0;
bool visit(int i) {
  --cnt[i];
  if (cnt[i] >= 0) return true;

  ++c;
  vector<int> v;
  for (int ch: subtrees[i]) {
    v.push_back(ans[ch]);
  }
  v.push_back(c);
  sort(v.begin(), v.end());
  if (ar[i] >= v.size()) {
    return false;
  }
  int a = v[ar[i]];
  for(int j = 0; j < MAXN; ++j) {
    if (ans[j] >= a) {
      ++ans[j];
    }
  }
  ans[i] = a;
  for (int ch: subtrees[i]) {
    subtrees[p[i]].push_back(ch);
  }
  subtrees[p[i]].push_back(i);
  return visit(p[i]);
}

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> p[i] >> ar[i];
    ++cnt[p[i]];
  }
  for (int i = 1; i <= n; ++i) {
    if (!visit(i)) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}