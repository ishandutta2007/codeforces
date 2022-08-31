#define GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> S(n);
    for (int j = 0; j < n; j++){
      cin >> S[j];
    }
    long long ans = 0;
    vector<long long> cnt(n, 0);
    for (int j = 0; j < n; j++){
      int t = S[j] - 1;
      if (S[j] > max(n - 1 - j, 1)){
        int d = S[j] - max(n - 1 - j, 1);
        S[j] -= d;
      }
      for (int k = S[j]; k >= 2; k--){
        cnt[j + k]++;
      }
      ans += max(t - cnt[j], (long long) 0);
      if (j < n - 1 && cnt[j] > t){
        cnt[j + 1] += cnt[j] - t;
      }
    }
    cout << ans << endl;
  }
}