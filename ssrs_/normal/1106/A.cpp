#include <bits/stdc++.h>
using namespace std;
vector<int> dx = {0, 1, 1, -1, -1};
vector<int> dy = {0, 1, -1, 1, -1};
int main(){
  int n;
  cin >> n;
  vector<string> M(n);
  for (int i = 0; i < n; i++){
    cin >> M[i];
  }
  int ans = 0;
  for (int i = 1; i < n - 1; i++){
    for (int j = 1; j < n - 1; j++){
      bool cross = true;
      for (int k = 0; k < 5; k++){
        if (M[i + dx[k]][j + dy[k]] != 'X'){
          cross = false;
        }
      }
      if (cross){
        ans++;
      }
    }
  }
  cout << ans << endl;
}