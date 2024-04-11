#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  array days{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  array names{"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
  string a, b;
  cin >> a >> b;
  int x = find(begin(names), end(names), a) - begin(names);
  int y = find(begin(names), end(names), b) - begin(names);
  for (int i = 0; i + 1 < 12; ++i)
    if (days[i] % 7 == (y - x + 7) % 7) {
      cout << "YES\n";
      exit(0);
    }
  cout << "NO\n";
}