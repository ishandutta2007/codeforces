#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct binary_indexed_tree{
  int N;
  vector<T> BIT;
  binary_indexed_tree(int N): N(N), BIT(N + 1, 0){
  }
  void add(int i, T x){
    i++;
    while (i <= N){
      BIT[i] += x;
      i += i & -i;
    }
  }
  T sum(int i){
    T ans = 0;
    while (i > 0){
      ans += BIT[i];
      i -= i & -i;
    }
    return ans;
  }
};
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> S(n + 1);
    S[0] = n;
    for (int j = 0; j < n; j++){
      S[j + 1] = S[j];
      if (s[j] == '-'){
        S[j + 1]++;
      } else {
        S[j + 1]--;
      }
    }
    vector<binary_indexed_tree<int>> BIT(3, binary_indexed_tree<int>(n * 2 + 1));
    long long ans = 0;
    for (int j = 0; j <= n; j++){
      ans += BIT[S[j] % 3].sum(S[j] + 1);
      BIT[S[j] % 3].add(S[j], 1);
    }
    cout << ans << endl;
  }
}