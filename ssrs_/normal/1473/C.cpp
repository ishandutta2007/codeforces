#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    vector<int> p(k);
    for (int j = 0; j < k; j++){
      p[j] = j;
    }
    reverse(p.begin() + (2 * k - 1 - n), p.end());
    for (int j = 0; j < k; j++){
      cout << p[j] + 1;
      if (j < k - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}