#include <bits/stdc++.h>
using namespace std;
int main(){
  vector<int> f(1000001);
  for (int i = 1; i < 10; i++){
    f[i] = i;
  }
  for (int i = 10; i <= 1000000; i++){
    string S = to_string(i);
    int tmp = 1;
    int N = S.size();
    for (int j = 0; j < N; j++){
      if (S[j] != '0'){
        tmp *= (S[j] - '0');
      }
    }
    f[i] = f[tmp];
  }
  vector<vector<int>> cnt(1000001, vector<int>(9, 0));
  for (int i = 1; i <= 1000000; i++){
    cnt[i] = cnt[i - 1];
    cnt[i][f[i] - 1]++;
  }
  int Q;
  cin >> Q;
  for (int i = 0; i < Q; i++){
    int l, r, k;
    cin >> l >> r >> k;
    l--;
    cout << cnt[r][k - 1] - cnt[l][k - 1] << endl;
  }
}