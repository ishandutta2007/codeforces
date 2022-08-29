#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    long long a, b, c;
    cin >> a >> b >> c;
    long long S = a + b * 2 + c * 3;
    cout << S % 2 << endl;
  }
}