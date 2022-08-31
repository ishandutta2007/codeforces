#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      cin >> a[i][j];
      a[i][j]--;
    }
  }
  vector<vector<int>> cnt(n, vector<int>(n, 0));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if (a[i][j] != -1){
        cnt[a[i][j]][i]++;
        cnt[a[i][j]][j]++;
      }
    }
  }
  vector<int> p(n, -1);
  for (int i = 0; i < n; i++){
    int mp = 0;
    for (int j = 1; j < n; j++){
      if (cnt[i][j] > cnt[i][mp]){
        mp = j;
      }
    }
    if (cnt[i][mp] > 0){
      p[mp] = i;
    }
  }
  for (int i = 0; i < n; i++){
    if (p[i] == -1){
      p[i] = n - 1;
    }
  }
  for (int i = 0; i < n; i++){
    cout << p[i] + 1;
    if (i < n - 1){
      cout << ' ';
    }
  }
  cout << endl;
}