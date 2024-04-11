#include <bits/stdc++.h>
using namespace std;
int main(){
  string S;
  cin >> S;
  int N = S.size();
  vector<bool> used(26, false);
  bool ok = true;
  for (int i = 0; i < N; i++){
    int id = S[i] - 'a';
    if (!used[id] && id > 0){
      if (!used[id - 1]){
        ok = false;
      }
    }
    used[id] = true;
  }
  if (ok){
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}