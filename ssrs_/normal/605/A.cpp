#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> P(N);
  for (int i = 0; i < N; i++){
    cin >> P[i];
    P[i]--;
  }
  vector<int> Q(N);
  for (int i = 0; i < N; i++){
    Q[P[i]] = i;
  }
  int ans = 1;
  int curr = 1;
  for (int i = 1; i < N; i++){
    if (Q[i] > Q[i - 1]){
      curr++;
      ans = max(ans, curr);
    } else {
      curr = 1;
    }
  }
  cout << N - ans << endl;
}