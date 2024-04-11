#include <bits/stdc++.h>
using namespace std;
int main(){
  int T;
  cin >> T;
  for (int i = 0; i < T; i++){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(n, 0));
    for (int j = 0; j < n; j++){
      for (int k = 0; k < n; k++){
        cin >> a[j][k];
        a[j][k]--;
      }
    }
    string s;
    cin >> s;
    int add = 0;
    int t = 0;
    int x = 0, y = 0;
    for (int j = 0; j < m; j++){
      if (s[j] == 'R'){
        if (t == 0) x--;
        if (t == 1) add++;
        if (t == 2) add++;
        if (t == 3) y--;
        if (t == 4) y--;
        if (t == 5) x--;
      }
      if (s[j] == 'L'){
        if (t == 0) x++;
        if (t == 1) add--;
        if (t == 2) add--;
        if (t == 3) y++;
        if (t == 4) y++;
        if (t == 5) x++;
      }
      if (s[j] == 'D'){
        if (t == 0) y--;
        if (t == 1) y--;
        if (t == 2) x--;
        if (t == 3) x--;
        if (t == 4) add++;
        if (t == 5) add++;
      }
      if (s[j] == 'U'){
        if (t == 0) y++;
        if (t == 1) y++;
        if (t == 2) x++;
        if (t == 3) x++;
        if (t == 4) add--;
        if (t == 5) add--;
      }
      if (s[j] == 'I'){
        int t2;
        if (t == 0) t2 = 1;
        if (t == 1) t2 = 0;
        if (t == 2) t2 = 3;
        if (t == 3) t2 = 2;
        if (t == 4) t2 = 5;
        if (t == 5) t2 = 4;
        t = t2;
      }
      if (s[j] == 'C'){
        int t2;
        if (t == 0) t2 = 5;
        if (t == 1) t2 = 2;
        if (t == 2) t2 = 1;
        if (t == 3) t2 = 4;
        if (t == 4) t2 = 3;
        if (t == 5) t2 = 0;
        t = t2;
      }
    }
    vector<vector<int>> b(n, vector<int>(n));
    for (int j = 0; j < n; j++){
      for (int k = 0; k < n; k++){
        int j2 = (j + y % n + n) % n;
        int k2 = (k + x % n + n) % n;
        b[j][k] = a[j2][k2];
        b[j][k] = (b[j][k] + add % n + n) % n;
      }
    }
    for (int j = 0; j < t; j++){
      if (j % 2 == 0){
        for (int k = 0; k < n; k++){
          vector<int> p(n);
          for (int l = 0; l < n; l++){
            p[b[k][l]] = l;
          }
          for (int l = 0; l < n; l++){
            b[k][l] = p[l];
          }
        }
      }
      if (j % 2 == 1){
        for (int k = 0; k < n; k++){
          vector<int> p(n);
          for (int l = 0; l < n; l++){
            p[b[l][k]] = l;
          }
          for (int l = 0; l < n; l++){
            b[l][k] = p[l];
          }
        }
      }
    }
    for (int j = 0; j < n; j++){
      for (int k = 0; k < n; k++){
        cout << b[j][k] + 1 << ' ';
      }
      cout << endl;
    }
  }
}