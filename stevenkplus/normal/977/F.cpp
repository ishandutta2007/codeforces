#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
const int MAXN = 200200;

map<int, int> mp;
map<int, int> ans;
int trace[MAXN];
int back[MAXN];
vector<int> v;

int main() {
  int n;
  scanf("%d", &n);
  int bst = 0;
  int t;
  for(int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    if (ans[x - 1] + 1 > ans[x]) {
      mp[x] = i + 1;
      trace[i] = mp[x - 1];
      ans[x] = ans[x - 1] + 1;
    }
    if (ans[x] > ans[bst]) {
      bst = x;
      t = i + 1;
    }
  }

  printf("%d\n", ans[bst]);
  while (t) {
    v.push_back(t);
    t = trace[t - 1];
  }
  reverse(v.begin(), v.end());
  for(auto i: v) {
    printf("%d ", i);
  }
  printf("\n");
}