#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int a, b, k;
    cin >> a >> b >> k;
    vector<int> A(k);
    for (int j = 0; j < k; j++){
      cin >> A[j];
      A[j]--;
    }
    vector<int> B(k);
    for (int j = 0; j < k; j++){
      cin >> B[j];
      B[j]--;
    }
    vector<int> cntA(a, 0);
    vector<int> cntB(b, 0);
    long long sum = 0;
    for (int j = k - 1; j >= 0; j--){
      sum += (k - 1 - j) - cntA[A[j]] - cntB[B[j]];
      cntA[A[j]]++;
      cntB[B[j]]++;
    }
    cout << sum << endl;
  }
}