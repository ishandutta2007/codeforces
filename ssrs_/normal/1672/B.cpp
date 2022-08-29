#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string s2;
    cin >> s2;
    int N = s2.size();
    if (s2[N - 1] == 'A'){
      cout << "NO" << endl;
    } else {
      vector<int> A(1, 0);
      for (int j = 0; j < N; j++){
        if (s2[j] == 'A'){
          A.back()++;
        } else {
          A.push_back(0);
        }
      }
      A.pop_back();
      int cnt = A.size();
      int sum = 0;
      bool ok = true;
      for (int j = 0; j < cnt; j++){
        sum += A[j];
        if (sum <= j){
          ok = false;
        }
      }
      if (ok){
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
}