#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n , m, a[N] , b[N];
void work() {
  scanf("%d" , &n);
  vector<pair<int , int>> v;
  for (int i = 0 ; i < n ; ++ i) {
    scanf("%d" , &a[i]);
    v.emplace_back(a[i] , i);
  }
  sort(v.begin() , v.end());
  for (int i = 0 ; i < n ; ++ i) {
    a[v[i].second] = i;
    b[i] = v[i].second;
  }

  set<int> h;
  for (int i = 0 ; i + 1 < n ; ++ i) {
    if (b[i] > b[i + 1]) {
      h.insert(i);
    }
  }

  vector<pair<int , int>> res;

  while (!h.empty()) {
    int x = *h.begin();
    h.erase(x);

    // swap b[x], b[x + 1]
    res.emplace_back(b[x + 1] , b[x]);
    swap(a[b[x]], a[b[x + 1]]);
    swap(b[x] , b[x + 1]);
    if (x > 0) {
      if (b[x - 1] > b[x]) {
        h.insert(x - 1);
      } else {
        h.erase(x - 1);
      }
    }
    if (x + 1 < n - 1) {
      if (b[x + 1] > b[x + 2]) {
        h.insert(x + 1);
      } else {
        h.erase(x + 1);
      }
    }

  }
  printf("%d\n" , res.size());
  for (int i = 0 ; i < res.size() ; ++ i) {
    printf("%d %d\n" , res[i].first + 1 , res[i].second + 1);
  }
}

int main() {
  work();
}