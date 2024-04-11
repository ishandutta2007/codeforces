#include <bits/stdc++.h>
#define ll long long
#define db double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int n;

int main(){
#ifdef LOCAL
	freopen("J_input.txt", "r", stdin);
	//freopen("J_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n;
  
  if (n == 2) {
      cout << "-1\n";
      return 0;
  }
  
  int x = sqrtl(n);
  while (x * x < n) {
      ++x;
  }
  vector <vector<char>> res(x + 2, vector<char>(x + 2, '.'));
  
  for (int i = 1; i < x; ++i) {
      for (int j = 0; j < x - 1; ++j) {
        res[i][j] = 'o';
      }
  }
  int cnt = (x - 1) * (x - 1);
  int d;
  for (d = 0; d < x && cnt < n; ++d, cnt += 2) {
      res[0][d] = 'o';
      res[x - 1 - d][x - 1] = 'o';
      if (d == x - 1) {
        --cnt;
      }
  }
  bool added = false;
  if (cnt != n) {
    res[1][x - 2] = '.';
    --cnt;
    if (d > x - 2) {
        added = true;
        res[0][x - 2] = '.';
        res[1][x - 1] = '.';
    }
  }
  assert(cnt == n);
  cout << x + added << "\n";
  if (added) {
      cout << "o";
      for (int i = 0; i < x; ++i) {
          cout << ".";
      }
      cout << "\n";
  }
  for (int i = 0; i < x; ++i) {
    for (int j = 0; j < x; ++j) {
        cout << res[i][j];
    }
    if (added) {
        cout << (i == x - 1 ? 'o' : '.');
    }
    cout << "\n";
  }
}