#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    long long a, b;
    cin >> a >> b;
    if (a == b){
      cout << 0 << ' ' << 0 << endl;
    } else {
      long long t = abs(a - b);
      long long m = min(a % t, t - a % t);
      cout << t << ' ' << m << endl;
    }
  }
}