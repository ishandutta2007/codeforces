#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    long long a, b, n, m;
    cin >> a >> b >> n >> m;
    if (min(a, b) < m){
      cout << "No" << endl;
    } else if (a + b < n + m){
      cout << "No" << endl;
    } else {
      cout << "Yes" << endl;
    }
  }
}