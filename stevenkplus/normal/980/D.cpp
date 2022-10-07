#include <bits/stdc++.h>
using namespace std;

map<int, int> mp;

int get(int x) {
  if (!mp[x]) {
    mp[x] = mp.size() + 1;
  }
  return mp[x];
}

int max(int a, int b) {
  if (a > b) return a;
  else return b;
}

int maxSq(int k) {
  for(int i = 1E4; i >= 1; --i) {
    if (k % (i * i) == 0) {
      return i * i;
    }
  }
}

const int MAXN = 5555;
int ar[MAXN];

int ans[MAXN];
int ss[MAXN];

int main() {
  int N;
  cin >> N;
  for(int i = 0; i < N; ++i) {
    cin >> ar[i];
    if (ar[i] != 0) {
      ar[i] = ar[i] / maxSq(ar[i]);
      ar[i] = get(ar[i]);
    }
  }

  ss[0] = 1;
  for(int i = 0; i < N; ++i) {
    set<int> s;
    int k = 0;
    for(int j = i; j < N; ++j) {
      if (ar[j]) {
        if (!ss[ar[j]]) {
          ++ss[ar[j]];
          ++k;
        }
      }
      ans[max(k, 1)]++;
    }
    for(int j = i; j < N; ++j) {
      if (ar[j]) {
        ss[ar[j]] = 0;
      }
    }
  }

  for(int i = 1; i <= N; ++i) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}