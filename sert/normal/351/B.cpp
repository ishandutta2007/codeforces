#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, inv = 0;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) cin >> x;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      if (a[i] > a[j])
        inv++;
  cout << inv * 2 - inv % 2 << endl;
}