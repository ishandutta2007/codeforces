#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> sum(N - 1);
  for (int i = 0; i < N - 1; i++){
    cout << "? " << i + 1 << ' ' << i + 2 << endl;
    cin >> sum[i];
  }
  int t;
  cout << "? " << 1 << ' ' << 3 << endl;
  cin >> t;
  vector<int> ans(N);
  ans[0] = t - sum[1];
  for (int i = 1; i < N; i++){
    ans[i] = sum[i - 1] - ans[i - 1];
  }
  cout << "!";
  for (int i = 0; i < N; i++){
    cout << ' ' << ans[i];
  }
  cout << endl;
}