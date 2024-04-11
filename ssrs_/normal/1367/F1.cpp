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
    map<int, int> pos;
    for (int j = 0; j < n; j++){
      pos[a[j]] = j;
    }
    vector<int> b = a;
    sort(b.begin(), b.end());
    vector<int> pos2(n);
    for (int j = 0; j < n; j++){
      pos2[j] = pos[b[j]];
    }
    int mx = 1;
    int curr = 1;
    for (int j = 1; j < n; j++){
      if (pos2[j] > pos2[j - 1]){
        curr++;
        mx = max(mx, curr);
      } else {
        curr = 1;
      }
    }
    cout << n - mx << endl;
  }
}