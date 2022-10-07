#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int mn = 51;
  int cnt = 0;
  for(int i = 0; i < n; ++i ){
    int x;
    cin >> x;
    if (x < mn) {
      cnt = 0;
      mn = x;
    }
    if (x == mn) ++cnt;
  }
  if (cnt <= n / 2) {
    cout << "Alice\n";
  } else {
    cout << "Bob\n";
  }
}