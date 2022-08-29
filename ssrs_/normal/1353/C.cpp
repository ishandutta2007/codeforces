#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    long long n;
    cin >> n;
    long long r = (n - 1) / 2;
    cout << r * (r + 1) * (r * 2 + 1) / 3 * 4 << endl;
  }
}