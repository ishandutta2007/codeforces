#include <bits/stdc++.h>
using namespace std;
const int INF = 10000;
int main(){
  int n, m, c;
  cin >> n >> m >> c;
  vector<int> A(n, INF), B(n, -INF);
  vector<int> S(n, -1);
  for (int i = 0; i < m; i++){
    int p;
    cin >> p;
    p--;
    if (p < c / 2){
      int pos = upper_bound(A.begin(), A.end(), p) - A.begin();
      cout << pos + 1 << endl;
      A[pos] = p;
      S[pos] = p;
    } else {
      int pos = lower_bound(B.begin(), B.end(), p) - B.begin() - 1;
      cout << pos + 1 << endl;
      B[pos] = p;
      S[pos] = p;
    }
    bool win = true;
    for (int j = 0; j < n; j++){
      if (S[j] == -1){
        win = false;
      }
    }
    for (int j = 0; j < n - 1; j++){
      if (S[j] > S[j + 1]){
        win = false;
      }
    }
    if (win){
      break;
    }
  }
}