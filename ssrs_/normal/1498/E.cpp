#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> k(n);
  for (int i = 0; i < n; i++){
    cin >> k[i];
  }
  vector<tuple<int, int, int>> Q;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if (i != j){
        if (k[i] < k[j] || (k[i] == k[j] && i < j)){
          Q.push_back(make_tuple(k[j] - k[i], j, i));
        }
      }
    }
  }
  sort(Q.begin(), Q.end(), greater<tuple<int, int, int>>());
  int m = Q.size();
  bool ok = false;
  for (int i = 0; i < m; i++){
    int A = get<1>(Q[i]);
    int B = get<2>(Q[i]);
    cout << "? " << A + 1 << ' ' << B + 1 << endl;
    string res;
    cin >> res;
    if (res == "Yes"){
      cout << "! " << A + 1 << ' ' << B + 1 << endl;
      ok = true;
      break;
    }
  }
  if (!ok){
    cout << "! 0 0" << endl;
  }
}