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
    int m;
    cin >>  m;
    vector<int> b(m);
    for (int j = 0; j < m; j++){
      cin >> b[j];
    }
    int mxa = 0;
    for (int j = 0; j < n; j++){
      mxa = max(mxa, a[j]);
    }
    int mxb = 0;
    for (int j = 0; j < m; j++){
      mxb = max(mxb, b[j]);
    }
    if (mxa > mxb){
      cout << "Alice" << endl;
      cout << "Alice" << endl;
    } else if (mxa < mxb){
      cout << "Bob" << endl;
      cout << "Bob" << endl;
    } else {
      cout << "Alice" << endl;
      cout << "Bob" << endl;
    }
  }
}