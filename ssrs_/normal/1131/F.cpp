#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> x(n - 1), y(n - 1);
  for (int i = 0; i < n - 1; i++){
    cin >> x[i] >> y[i];
    x[i]--;
    y[i]--;
  }
  vector<vector<int>> id(n);
  for (int i = 0; i < n; i++){
    id[i].push_back(i);
  }
  vector<int> p(n);
  for (int i = 0; i < n; i++){
    p[i] = i;
  }
  for (int i = 0; i < n - 1; i++){
    int X = p[x[i]];
    int Y = p[y[i]];
    if (id[X].size() > id[Y].size()){
      swap(X, Y);
    }
    for (int a : id[X]){
      id[Y].push_back(a);
      p[a] = Y;
    }
  }
  int r = p[0];
  for (int i = 0; i < n; i++){
    cout << id[r][i] + 1;
    if (i < n - 1){
      cout << ' ';
    }
  }
  cout << endl;
}