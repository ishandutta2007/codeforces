#include <bits/stdc++.h>
using namespace std;
vector<int> g = {-1, 1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> s(n);
  for (int i = 0; i < n; i++){
    cin >> s[i];
  }
  int grundy = 0;
  for (int i = 0; i < n; i++){
    grundy ^= g[s[i]];
  }
  if (grundy == 0){
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}