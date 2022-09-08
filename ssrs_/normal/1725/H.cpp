#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++){
    cin >> A[i];
  }
  vector<int> X, Y;
  for (int i = 0; i < N; i++){
    if (A[i] % 3 == 0){
      X.push_back(i);
    } else {
      Y.push_back(i);
    }
  }
  if (X.size() <= N / 2){
    int Z = 0;
    string S(N, '0');
    for (int i = 0; i < X.size(); i++){
      S[X[i]] = '1';
    }
    for (int i = 0; i < N / 2 - X.size(); i++){
      S[Y[i]] = '1';
    }
    cout << Z << endl;
    cout << S << endl;
  } else {
    int Z = 2;
    string S(N, '0');
    for (int i = 0; i < Y.size(); i++){
      S[Y[i]] = '1';
    }
    for (int i = 0; i < N / 2 - Y.size(); i++){
      S[X[i]] = '1';
    }
    cout << Z << endl;
    cout << S << endl;
  }
}