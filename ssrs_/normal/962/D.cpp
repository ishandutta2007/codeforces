#include <bits/stdc++.h>
using namespace std;
long long dtz(long long a){
  //delete trailing zeroes
  return a >> __builtin_ctzll(a);
}
int main(){
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  map<long long, vector<int>> M;
  for (int i = 0; i < n; i++){
    M[dtz(a[i])].push_back(i);
  }
  for (auto P : M){
    map<long long, int> M2;
    for (int i : P.second){
      if (!M2.count(a[i])){
        M2[a[i]] = i;
      } else {
        while (M2.count(a[i])){
          a[M2[a[i]]] = 0;
          M2.erase(a[i]);
          a[i] *= 2;
        }
        M2[a[i]] = i;
      }
    }
  }
  vector<long long> ans;
  for (int i = 0; i < n; i++){
    if (a[i] != 0){
      ans.push_back(a[i]);
    }
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++){
    cout << ans[i];
    if (i < ans.size() - 1){
      cout << ' ';
    }
  }
  cout << endl;
}