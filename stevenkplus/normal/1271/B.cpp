#include <iostream>
#include <vector>
using namespace std;

void solve(int n, string s) {
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'W') {
      ++cnt;
    }
  }
  char ch = 'W';
  if (cnt % 2 != 0) {
    if (n % 2 == 0) {
      cout << "-1\n";
      return;
    }
    ch = 'B';
  }

  bool last = false;
  vector<int> v;
  for(int i = 0; i < n; ++i) {
    last ^= s[i] == ch;
    if (last) {
      v.push_back(i);
    }
  }
  cout << v.size() << "\n";
  for (auto i: v) {
    cout << i + 1 << " ";
  }
  cout << "\n";
}

int main() {
  int n;
  string s;
  cin >> n >> s;
  solve(n, s);
}