#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  string s;
  cin >> s;

  int sp = -1;
  for (int i = 0; i < s.length()-1; i++) {
    if (s[i] > s[i+1]) {
      sp = i+1;
    }
  }
  if (sp == -1) {
    cout << "NO" << endl;
  }
  else cout << "YES" << endl << sp << " " << sp+1 << endl;
}