#include <bits/stdc++.h>
using namespace std;
vector<int> q = {13, 22, 26, 35, 41};
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    int query = 0;
    vector<int> r(n / 3);
    for (int j = 0; j < n / 3; j++){
      cout << "? " << j * 3 + 1 << ' ' << j * 3 + 2 << ' ' << j * 3 + 3 << endl;
      query++;
      cin >> r[j];
    }
    int P, Q;
    for (int j = 0; j < n / 3; j++){
      if (r[j] == 0){
        P = j;
      }
      if (r[j] == 1){
        Q = j;
      }
    }
    vector<int> b;
    b.push_back(P * 3);
    b.push_back(P * 3 + 1);
    b.push_back(P * 3 + 2);
    b.push_back(Q * 3);
    b.push_back(Q * 3 + 1);
    b.push_back(Q * 3 + 2);
    vector<int> r2(5);
    for (int j = 0; j < 5; j++){
      vector<int> c;
      for (int k = 0; k < 6; k++){
        if ((q[j] >> k & 1) == 1){
          c.push_back(b[k]);
        }
      }
      cout << "? " << c[0] + 1 << ' ' << c[1] + 1 << ' ' << c[2] + 1 << endl;
      query++;
      cin >> r2[j];
    }
    int c = 0;
    vector<int> A(6);
    for (int j = 0; j < 64; j++){
      if (__builtin_popcount(j % 8) >= 2 && __builtin_popcount(j / 8) <= 1){
        c++;
        bool ok = true;
        for (int k = 0; k < 5; k++){
          int p = __builtin_popcount(j & q[k]);
          if (r2[k] == 0 && p <= 1 || r2[k] == 1 && p >= 2){
            ok = false;
          }
        }
        if (ok){
          for (int k = 0; k < 6; k++){
            A[k] = j >> k & 1;
          }
        }
      }
    }
    vector<int> zero, one;
    for (int j = 0; j < 6; j++){
      if (A[j] == 0){
        zero.push_back(b[j]);
      }
      if (A[j] == 1){
        one.push_back(b[j]);
      }
    }
    vector<int> ans;
    for (int x : one){
      ans.push_back(x);
    }
    for (int j = 0; j < n / 3; j++){
      if (j != P && j != Q){
        if (r[j] == 1){
          cout << "? " << j * 3 + 1 << ' ' << j * 3 + 2 << ' ' << one[0] + 1 << endl;
          query++;
          int x;
          cin >> x;
          cout << "? " << j * 3 + 2 << ' ' << j * 3 + 3 << ' ' << one[0] + 1 << endl;
          query++;
          int y;
          cin >> y;
          if (x == 1 && y == 0){
            ans.push_back(j * 3 + 2);
          }
          if (x == 0 && y == 1){
            ans.push_back(j * 3);
          }
          if (x == 0 && y == 0){
            ans.push_back(j * 3 + 1);
          }
        }
        if (r[j] == 0){
          cout << "? " << j * 3 + 1 << ' ' << j * 3 + 2 << ' ' << zero[0] + 1 << endl;
          query++;
          int x;
          cin >> x;
          cout << "? " << j * 3 + 2 << ' ' << j * 3 + 3 << ' ' << zero[0] + 1 << endl;
          query++;
          int y;
          cin >> y;
          if (x == 0 && y == 1){
            ans.push_back(j * 3);
            ans.push_back(j * 3 + 1);
          }
          if (x == 1 && y == 0){
            ans.push_back(j * 3 + 1);
            ans.push_back(j * 3 + 2);
          }
          if (x == 1 && y == 1){
            ans.push_back(j * 3);
            ans.push_back(j * 3 + 2);
          }
          if (x == 0 && y == 0){
            ans.push_back(j * 3);
            ans.push_back(j * 3 + 1);
            ans.push_back(j * 3 + 2);
          }
        }
      }
    }
    assert(query <= n + 1);
    int k = ans.size();
    cout << "! " << k;
    for (int j = 0; j < k; j++){
      cout << ' ' << ans[j] + 1;
    }
    cout << endl;
  }
}