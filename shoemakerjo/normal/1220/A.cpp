#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int maxn = 100010;

int n;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  string line;
  cin >> line;
  int zc = 0, nc = 0;
  for (int i = 0; i < n; i++) {
	if (line[i] == 'n') nc++;
	if (line[i] == 'z') zc++;
  }
  while (nc--) cout << 1 << " " ;
  while (zc--) cout << 0 << " " ;

  cout << endl;

}