#include <bits/stdc++.h>

using namespace std;
int n;
const int maxn = 300010;

int nums[maxn]; //0 is min; 1 is max
int par[maxn];
vector<int> ch[maxn];
int k = 0;

int sz[maxn]; //size of me

void dfs(int u) {
  if (ch[u].size() ==0) {
    sz[u] = 1;
    return;
  }

  if (nums[u] == 1) {
    sz[u] = n;
    for (int v : ch[u]) {
      dfs(v);
      sz[u] = min(sz[u], sz[v]);
    }
  }
  else {
    for (int v : ch[u]) {
      dfs(v);
      sz[u] += sz[v];
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> nums[i];
  }
  for (int i = 2; i <= n; i++) {
    cin >> par[i];
    ch[par[i]].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    if (ch[i].size() == 0) ++k;
  }
  //put 1 .. k into leaves (where k leaves)
  //want to maximize the answer in the root

  //if root is a max --> we can just go to each guy
  //anytine we have a max we can throw away all children but one
  //if we are a max we essentially just become one child
  //if we are a min, we union all children
  dfs(1);
  cout << k-sz[1]+1;
}