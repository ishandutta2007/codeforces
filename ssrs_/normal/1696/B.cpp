#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n + 2, 0);
    for (int j = 1; j <= n; j++){
      cin >> a[j];
    }
    int cnt = 0;
    for (int j = 0; j <= n; j++){
      if (a[j] == 0 && a[j + 1] != 0){
        cnt++;
      }
    }
    cout << min(cnt, 2) << endl;
  }
}