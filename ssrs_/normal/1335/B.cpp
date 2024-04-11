#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, a, b;
    cin >> n >> a >> b;
    vector<char> L(a);
    for (int j = 0; j < a; j++){
      L[j] = 'a' + min(j, b - 1);
    }
    for (int j = 0; j < n; j++){
      cout << L[j % a];
    }
    cout << endl;
  }
}