#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> v(n);
  int numW = 0;

  vector<int> colF(m), colN(m), colL(m);
  vector<int> rowF(n), rowN(n), rowL(n);
  
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    for (int j = 0; j < m; j++) {
      if (v[i][j] == 'w') {
        numW++;
        if (colN[j] == 0) colF[j] = i;
        colN[j]++;
        colL[j] = i;
        if (rowN[i] == 0) rowF[i] = j;
        rowN[i]++;
        rowL[i] = j;
      }
    }
  }  

  if (numW == 1) {
    for (auto s : v) cout << s << "\n";
    return;
  }

  vector<int> digLastRow(n + m, -1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (rowN[i] + colN[j] > 0) {
        digLastRow[i - j + m] = i;
      }
    }
  }

  int x = -1, y = -1, sz = n + m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int ii = digLastRow[i - j + m];      

      if (ii <= i) continue;
      int curSz = ii - i + 1;
      if (curSz >= sz) continue;

      int jj = j + ii - i;

      if (colN[j] > 0 && (colF[j] < i || colL[j] > ii)) continue;
      if (colN[jj] > 0 && (colF[jj] < i || colL[jj] > ii)) continue;
      if (rowN[i] > 0 && (rowF[i] < j || rowL[i] > jj)) continue;
      if (rowN[ii] > 0 && (rowF[ii] < j || rowL[ii] > jj)) continue;

      int tot = colN[j] + colN[jj] + rowN[i] + rowN[ii];
      if (v[i][j] == 'w') tot--;
      if (v[ii][j] == 'w') tot--;
      if (v[i][jj] == 'w') tot--;
      if (v[ii][jj] == 'w') tot--;

      if (tot == numW) {
        x = j;
        y = i;
        sz = curSz;
      }      
    }
  }  

  if (x == -1) {
    cout << "-1\n";
    return;
  }

  for (int i = y; i < y + sz; i++) {
    for (int j = x; j < x + sz; j++) {      
      if (v[i][j] == '.' && (i == y || i == y + sz - 1 || j == x || j == x + sz - 1))
        v[i][j] = '+';
    }
  }

  for (int i = 0; i < n; i++)
    cout << v[i] << "\n";


#ifdef SERT
  cout << x << " " << y << " " << sz << endl;
#endif
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
}