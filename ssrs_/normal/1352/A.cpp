#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string S;
    cin >> S;
    int M = S.size();
    vector<string> A;
    for (int j = 0; j < M; j++){
      if (S[j] != '0'){
        string T = S.substr(j, 1);
        for (int k = j + 1; k < M; k++){
          T += '0';
        }
        A.push_back(T);
      }
    }
    cout << A.size() << endl;
    for (int j = 0; j < A.size(); j++){
      cout << A[j];
      if (j < A.size() - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}