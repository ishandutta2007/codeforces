#include <bits/stdc++.h>
using namespace std;
int main(){
  vector<int> X;
  int N = 1;
  while (X.size() < 1000){
    if (N % 3 != 0 && N % 10 != 3){
      X.push_back(N);
    }
    N++;
  }
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int k;
    cin >> k;
    k--;
    cout << X[k] << endl;
  }
}