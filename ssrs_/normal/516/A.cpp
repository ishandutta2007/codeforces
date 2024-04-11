#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> f = {{0, 0, 0, 0}, {0, 0, 0, 0}, {1, 0, 0, 0}, {1, 1, 0, 0}, {3, 1, 0, 0}, {3, 1, 1, 0}, {4, 2, 1, 0}, {4, 2, 1, 1}, {7, 2, 1, 1}, {7, 4, 1, 1}};
int main(){
  int n;
  cin >> n;
  string a;
  cin >> a;
  vector<int> cnt(4, 0);
  for (int i = 0; i < n; i++){
    int num = a[i] - '0';
    for (int j = 0; j < 4; j++){
      cnt[j] += f[num][j];
    }
  }
  int cnt7 = cnt[3];
  cnt[0] -= cnt7 * 4;
  cnt[1] -= cnt7 * 2;
  cnt[2] -= cnt7;
  int cnt5 = cnt[2];
  cnt[0] -= cnt5 * 3;
  cnt[1] -= cnt5;
  int cnt3 = cnt[1];
  cnt[0] -= cnt3;
  int cnt2 = cnt[0];
  string ans;
  for (int i = 0; i < cnt7; i++){
    ans += '7';
  }
  for (int i = 0; i < cnt5; i++){
    ans += '5';
  }
  for (int i = 0; i < cnt3; i++){
    ans += '3';
  }
  for (int i = 0; i < cnt2; i++){
    ans += '2';
  }
  cout << ans << endl;
}