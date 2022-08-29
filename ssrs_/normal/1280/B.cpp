#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int r, c;
    cin >> r >> c;
    vector<vector<char>> a(r, vector<char>(c));
    for (int j = 0; j < r; j++){
      for (int k = 0; k < c; k++){
        cin >> a[j][k];
      }
    }
    bool ok0 = true;
    for (int j = 0; j < r; j++){
      for (int k = 0; k < c; k++){
        if (a[j][k] == 'P'){
          ok0 = false;
        }
      }
    }
    bool ok1 = false;
    bool oka = true;
    for (int j = 0; j < c; j++){
      if (a[0][j] == 'P'){
        oka = false;
      }
    }
    if (oka){
      ok1 = true;
    }
    bool okb = true;
    for (int j = 0; j < c; j++){
      if (a[r - 1][j] == 'P'){
        okb = false;
      }
    }
    if (okb){
      ok1 = true;
    }
    bool okc = true;
    for (int j = 0; j < r; j++){
      if (a[j][0] == 'P'){
        okc = false;
      }
    }
    if (okc){
      ok1 = true;
    }
    bool okd = true;
    for (int j = 0; j < r; j++){
      if (a[j][c - 1] == 'P'){
        okd = false;
      }
    }
    if (okd){
      ok1 = true;
    }
    bool ok2 = false;
    for (int j = 0; j < r; j++){
      bool ok = true;
      for (int k = 0; k < c; k++){
        if (a[j][k] == 'P'){
          ok = false;
        }
      }
      if (ok){
        ok2 = true;
      }
    }
    for (int j = 0; j < c; j++){
      bool ok = true;
      for (int k = 0; k < r; k++){
        if (a[k][j] == 'P'){
          ok = false;
        }
      }
      if (ok){
        ok2 = true;
      }
    }
    if (a[0][0] == 'A'){
      ok2 = true;
    }
    if (a[0][c - 1] == 'A'){
      ok2 = true;
    }
    if (a[r - 1][0] == 'A'){
      ok2 = true;
    }
    if (a[r - 1][c - 1] == 'A'){
      ok2 = true;
    }
    bool ok3 = false;
    for (int j = 0; j < c; j++){
      if (a[0][j] == 'A' || a[r - 1][j] == 'A'){
        ok3 = true;
      }
    }
    for (int j = 0; j < r; j++){
      if (a[j][0] == 'A' || a[j][c - 1] == 'A'){
        ok3 = true;
      }
    }
    bool ok4 = false;
    for (int j = 0; j < r; j++){
      for (int k = 0; k < c; k++){
        if (a[j][k] == 'A'){
          ok4 = true;
        }
      }
    }
    if (ok0){
      cout << 0 << endl;
    } else if (ok1){
      cout << 1 << endl;
    } else if (ok2){
      cout << 2 << endl;
    } else if (ok3){
      cout << 3 << endl;
    } else if (ok4){
      cout << 4 << endl;
    } else {
      cout << "MORTAL" << endl;
    }
  }
}