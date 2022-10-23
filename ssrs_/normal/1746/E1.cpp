#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  if (n == 1){
    cout << "! 1" << endl;
  } else if (n == 2){
    cout << "! 1" << endl;
    string res;
    cin >> res;
    if (res == ":("){
      cout << "! 2" << endl;
    }
  } else {
    vector<int> R;
    for (int i = 1; i <= n; i++){
      R.push_back(i);
    }
    while (R.size() >= 4){
      int N = R.size();
      vector<int> A, B;
      for (int i = 0; i < N; i++){
        if ((i & 1) == 1){
          A.push_back(R[i]);
        }
        if ((i & 2) == 2){
          B.push_back(R[i]);
        }
      }
      int cntA = A.size();
      int cntB = B.size();
      cout << "? " << cntA;
      for (int i = 0; i < cntA; i++){
        cout << ' ' << A[i];
      }
      cout << endl;
      string resA;
      cin >> resA;
      cout << "? " << cntB;
      for (int i = 0; i < cntB; i++){
        cout << ' ' << B[i];
      }
      cout << endl;
      string resB;
      cin >> resB;
      int r = 0;
      if (resA == "NO"){
        r++;
      }
      if (resB == "NO"){
        r += 2;
      }
      vector<int> R2;
      for (int i = 0; i < N; i++){
        if (i % 4 != r){
          R2.push_back(R[i]);
        }
      }
      R = R2;
    }
    vector<int> Q = {0, 1, 1, 2};
    vector<string> res(4);
    for (int i = 0; i < 4; i++){
      cout << "? " << 1 << ' ' << R[Q[i]] << endl;
      cin >> res[i];
    }
    for (int i = 0; i < 3; i++){
      vector<string> co(4);
      for (int j = 0; j < 4; j++){
        if (Q[j] == i){
          co[j] = "YES";
        } else {
          co[j] = "NO";
        }
      }
      bool ok = true;
      for (int j = 0; j < 3; j++){
        if (co[j] != res[j] && co[j + 1] != res[j + 1]){
          ok = false;
        }
      }
      if (ok){
        cout << "! " << R[i] << endl;
        string res2;
        cin >> res2;
        if (res2 == ":)"){
          break;
        }
      }
    }
  }
}