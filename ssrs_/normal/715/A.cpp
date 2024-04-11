#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  long long x = 2;
  for (long long i = 1; i <= n; i++){
    cout << i * (i + 1) * (i + 1) - x / i << "\n";
    x = i * (i + 1);
  }
}