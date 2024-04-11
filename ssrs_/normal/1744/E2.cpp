#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    long long P = (long long) a * b;
    vector<int> fa;
    for (int j = 1; j * j <= a; j++){
      if (a % j == 0){
        fa.push_back(j);
        if (j * j < a){
          fa.push_back(a / j);
        }
      }
    }
    vector<int> fb;
    for (int j = 1; j * j <= b; j++){
      if (b % j == 0){
        fb.push_back(j);
        if (j * j < b){
          fb.push_back(b / j);
        }
      }
    }
    vector<long long> F;
    for (int x : fa){
      for (int y : fb){
        F.push_back((long long) x * y);
      }
    }
    sort(F.begin(), F.end());
    F.erase(unique(F.begin(), F.end()), F.end());
    int x = -1, y = -1;
    for (long long j : F){
      long long X = c / j * j;
      long long Y = d / (P / j) * (P / j);
      if (X > a && Y > b){
        x = X;
        y = Y;
      }
    }
    cout << x << ' ' << y << endl;
  }
}