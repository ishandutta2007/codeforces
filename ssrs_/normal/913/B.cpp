#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> p(n);
  p[0] = -1;
  for (int i = 1; i < n; i++){
    cin >> p[i];
    p[i]--;
  }
  vector<int> leaf(n, true);
  for (int i = 1; i < n; i++){
    leaf[p[i]] = false;
  }
  vector<int> cnt(n, 0);
  for (int i = 1; i < n; i++){
    if (leaf[i]){
      cnt[p[i]]++;
    }
  }
  bool ok = true;
  for (int i = 0; i < n; i++){
    if (!leaf[i] && cnt[i] < 3){
      ok = false;
    }
  }
  if (ok){
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}