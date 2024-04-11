#include <bits/stdc++.h>

using namespace std;

int nums[502][502];
int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> nums[i][j];
    }
  }

  int drow = -1;

  for (int i = 1; i <= n; i++) {
    if (drow != -1) break;
    for (int j = 1; j <= m; j++) {
      if (nums[i][j] != nums[i][1]) {
        drow = i;
        break;
      }
    }
  }

  if (drow == -1) {
    int cv = 0;
    for (int i = 1; i <= n; i++) {
      cv ^= nums[i][1];
    }
    if (cv) {
      cout << "TAK" << endl;
      for (int i = 1; i <= n; i++) {
        cout << 1 << " ";
      }
      cout << endl;
    }
    else {
      cout << "NIE" << endl;
    }
    return 0;
  }


  int cv = 0;
  for (int i = 1; i <= n; i++) {
    if (i != drow) {
      cv ^= nums[i][1];
    }
  }
  int cspot = -1;
  for (int i = 1; i <= m; i++) {
    if (cv ^ nums[drow][i]) {
      cspot = i;
    }
  }
  cout << "TAK" << endl;
  for (int i = 1; i <= n; i++) {
    if (i == drow) {
      cout << cspot << " ";
    }
    else cout << 1 << " ";
  }
  cout << endl;

}