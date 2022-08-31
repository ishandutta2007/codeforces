#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<bool> used(n, false);
    vector<int> b(n);
    map<int, int> mp;
    int cnt = 0;
    for (int j = 0; j < n; j++){
      if (mp.count(a[j]) == 1 && cnt < n / 2 - 1){
        b[mp[a[j]]] = 1;
        b[j] = -1;
        used[mp[a[j]]] = true;
        used[j] = true;
        mp.erase(a[j]);
        cnt++;
      } else {
        mp[a[j]] = j;
      }
    }
    vector<int> p;
    for (int j = 0; j < n; j++){
      if (!used[j]){
        p.push_back(j);
      }
    }
    int S = 0;
    for (int j : p){
      S += a[j];
    }
    int x = -1;
    for (int j : p){
      if (a[j] != S){
        x = j;
      }
    }
    for (int j : p){
      b[j] = a[x];
    }
    b[x] = a[x] - S;
    for (int j = 0; j < n; j++){
      cout << b[j];
      if (j < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}