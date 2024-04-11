#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> t(n);
  for (int i = 0; i < n; i++){
    cin >> t[i];
  }
  bool ok = false;
  for (int i = 0; i < n; i++){
    for (int j = i + 1; j < n; j++){
      for (int k = j + 1; k < n; k++){
        vector<int> tmp = {t[i], t[j], t[k]};
        sort(tmp.begin(), tmp.end());
        if (tmp[0] == tmp[1] - 1 && tmp[1] == tmp[2] - 1){
          ok = true;
        }
      }
    }
  }
  if (ok){
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}