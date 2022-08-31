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
    sort(a.begin(), a.end());
    int S = 0;
    for (int j = 0; j < n; j++){
      S += a[j];
    }
    if (n == 1){
      cout << "T" << endl;
    } else if (S % 2 == 1){
      cout << "T" << endl;
    } else if (S - a[n - 1] >= a[n - 1]){
      cout << "HL" << endl;
    } else {
      cout << "T" << endl;
    }
  }
}