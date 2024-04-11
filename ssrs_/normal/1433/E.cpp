#include <bits/stdc++.h>
using namespace std;
long long fact(int n){
  long long ans = 1;
  for (int i = 1; i <= n; i++){
    ans *= i;
  }
  return ans;
}
int main(){
  int n;
  cin >> n;
  cout << fact(n) * 2 / (n * n) << endl;
}