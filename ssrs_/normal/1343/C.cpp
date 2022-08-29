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
    vector<vector<int>> B;
    long long p = -a[0];
    for (int j = 0; j < n; j++){
      if (p * a[j] > 0){
        //same sign
        B.back().push_back(a[j]);
      } else {
        //different sign
        B.push_back(vector<int>());
        B.back().push_back(a[j]);
        p = a[j];
      }
    }
    int b = B.size();
    for (int j = 0; j < b; j++){
      sort(B[j].begin(), B[j].end());
      reverse(B[j].begin(), B[j].end());
    }
    long long S = 0;
    for (int j = 0; j < b; j++){
      S += B[j][0];
    }
    cout << S << endl;
  }
}