#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> s(n, vector<int>(m));
    for (int j = 0; j < n; j++){
      for (int k = 0; k < m; k++){
        char c;
        cin >> c;
        s[j][k] = c - '0';
      }
    }
    vector<tuple<pair<int, int>, pair<int, int>, pair<int, int>>> op;
    for (int j = 0; j < n - 2; j++){
      for (int k = 0; k < m - 1; k++){
        int a = s[j][k];
        int b = s[j][k + 1];
        if (a == 1 && b == 0){
          op.push_back(make_tuple(make_pair(j, k), make_pair(j + 1, k), make_pair(j + 1, k + 1)));
          s[j][k] = 0;
          s[j + 1][k] = 1 - s[j + 1][k];
          s[j + 1][k + 1] = 1 - s[j + 1][k + 1];
        } else if (a == 0 && b == 1){
          op.push_back(make_tuple(make_pair(j, k + 1), make_pair(j + 1, k), make_pair(j + 1, k + 1)));
          s[j][k + 1] = 0;
          s[j + 1][k] = 1 - s[j + 1][k];
          s[j + 1][k + 1] = 1 - s[j + 1][k + 1];
        } else if (a == 1 && b == 1){
          op.push_back(make_tuple(make_pair(j, k), make_pair(j, k + 1), make_pair(j + 1, k)));
          s[j][k] = 0;
          s[j][k + 1] = 0;
          s[j + 1][k] = 1 - s[j + 1][k];
        }
      }
    }
    for (int j = 0; j < m - 2; j++){
      int a = s[n - 2][j];
      int b = s[n - 1][j];
      if (a == 1 && b == 0){
        op.push_back(make_tuple(make_pair(n - 2, j), make_pair(n - 2, j + 1), make_pair(n - 1, j + 1)));
        s[n - 2][j] = 0;
        s[n - 2][j + 1] = 1 - s[n - 2][j + 1];
        s[n - 1][j + 1] = 1 - s[n - 1][j + 1];
      } else if (a == 0 && b == 1){
        op.push_back(make_tuple(make_pair(n - 1, j), make_pair(n - 2, j + 1), make_pair(n - 1, j + 1)));
        s[n - 1][j] = 0;
        s[n - 2][j + 1] = 1 - s[n - 2][j + 1];
        s[n - 1][j + 1] = 1 - s[n - 1][j + 1];
      } else if (a == 1 && b == 1){
        op.push_back(make_tuple(make_pair(n - 1, j), make_pair(n - 2, j), make_pair(n - 2, j + 1)));
        s[n - 2][j] = 0;
        s[n - 1][j] = 0;
        s[n - 2][j + 1] = 1 - s[n - 2][j + 1];
      }
    }
    int a = s[n - 2][m - 2];
    int b = s[n - 2][m - 1];
    int c = s[n - 1][m - 2];
    int d = s[n - 1][m - 1];
    pair<int, int> A = make_pair(n - 2, m - 2);
    pair<int, int> B = make_pair(n - 2, m - 1);
    pair<int, int> C = make_pair(n - 1, m - 2);
    pair<int, int> D = make_pair(n - 1, m - 1);
    if (a == 1 && b == 0){
      swap(a, b);
      swap(A, B);
    }
    if (c == 1 && d == 0){
      swap(c, d);
      swap(C, D);
    }
    if (a == 0 && b == 0){
      if (c == 0 && d == 1){
        op.push_back(make_tuple(B, C, D));
        op.push_back(make_tuple(A, C, D));
        op.push_back(make_tuple(A, B, D));
      } else if (c == 1 && d == 1){
        op.push_back(make_tuple(A, B, C));
        op.push_back(make_tuple(A, B, D));
      }
    } else if (a == 0 && b == 1){
      if (c == 0 && d == 0){
        op.push_back(make_tuple(A, B, D));
        op.push_back(make_tuple(A, B, C));
        op.push_back(make_tuple(B, C, D));
      } else if (c == 0 && d == 1){
        op.push_back(make_tuple(A, B, C));
        op.push_back(make_tuple(A, C, D));
      } else if (c == 1 && d == 1){
        op.push_back(make_tuple(B, C, D));
      }
    } else if (a == 1 && b == 1){
      if (c == 0 && d == 0){
        op.push_back(make_tuple(A, C, D));
        op.push_back(make_tuple(B, C, D));
      } else if (c == 0 && d == 1){
        op.push_back(make_tuple(A, B, D));
      } else if (c == 1 && d == 1){
        op.push_back(make_tuple(A, B, C));
        op.push_back(make_tuple(A, B, D));
        op.push_back(make_tuple(A, C, D));
        op.push_back(make_tuple(B, C, D));
      }
    }
    int k = op.size();
    cout << k << endl;
    for (int i = 0; i < k; i++){
      int x1 = get<0>(op[i]).first + 1;
      int y1 = get<0>(op[i]).second + 1;
      int x2 = get<1>(op[i]).first + 1;
      int y2 = get<1>(op[i]).second + 1;
      int x3 = get<2>(op[i]).first + 1;
      int y3 = get<2>(op[i]).second + 1;
      cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << ' ' << x3 << ' ' << y3 << endl;
    }
  }
}