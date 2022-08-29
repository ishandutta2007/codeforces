#include <bits/stdc++.h>
using namespace std;
void dfs(string &ans, vector<bool> &prime, string &n, int &k, int &D, int p, int x, int L){
  if (p == k){
    if (L == D && !prime[x]){
      ans = to_string(x);
    }
  } else {
    dfs(ans, prime, n, k, D, p + 1, x, L);
    if (ans.empty() && L < D){
      dfs(ans, prime, n, k, D, p + 1, x * 10 + (n[p] - '0'), L + 1);
    }
  }
}
int main(){
  vector<bool> prime(10000, true);
  prime[1] = false;
  for (int i = 2; i < 10000; i++){
    if (prime[i]){
      for (int j = i * 2; j < 10000; j += i){
        prime[j] = false;
      }
    }
  }
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int k;
    cin >> k;
    string n;
    cin >> n;
    int D = 1;
    while (true){
      string ans;
      dfs(ans, prime, n, k, D, 0, 0, 0);
      if (!ans.empty()){
        cout << D << endl;
        cout << ans << endl;
        break;
      }
      D++;
    }
  }
}