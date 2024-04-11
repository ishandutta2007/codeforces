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
      a[j]--;
    }
    vector<vector<int>> cnt1(2, vector<int>(100000, 0));
    for (int j = 0; j < n; j++){
      cnt1[j % 2][a[j]]++;
    }
    sort(a.begin(), a.end());
    vector<vector<int>> cnt2(2, vector<int>(100000, 0));
    for (int j = 0; j < n; j++){
      cnt2[j % 2][a[j]]++;
    }
    if (cnt1 == cnt2){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}