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
  T sum(int L, int R){
    return sum(R) - sum(L);
  }
};
int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++){
    cin >> A[i];
  }
  vector<long long> S(N + 1);
  S[0] = 0;
  for (int i = 0; i < N; i++){
    S[i + 1] = S[i] + A[i];
  }
  vector<long long> T = S;
  sort(T.begin(), T.end());
  T.erase(unique(T.begin(), T.end()), T.end());
  int cnt = T.size();
  for (int i = 0; i <= N; i++){
    S[i] = lower_bound(T.begin(), T.end(), S[i]) - T.begin();
  }
  if (S[0] != 0 || S[N] != cnt - 1){
    cout << -1 << endl;
  } else {
    binary_indexed_tree<int> BIT(cnt);
    long long ans = 0;
    for (int i = 0; i <= N; i++){
      ans += BIT.sum(S[i] + 1, cnt);
      BIT.add(S[i], 1);
    }
    cout << ans << endl;
  }
}