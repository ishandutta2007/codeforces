#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> S;
    for (int i = 0; i < n; i++){
      cin >> a[i];
      S.insert(a[i]);
    }
    cout << S.size() << endl;
  }
}