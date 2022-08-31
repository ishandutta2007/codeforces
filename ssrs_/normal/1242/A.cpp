#include <bits/stdc++.h>
using namespace std;
int main(){
  long long n;
  cin >> n;
  vector<long long> pf;
  for (long long i = 2; i * i <= n; i++){
    if (n % i == 0){
      pf.push_back(i);
      while (n % i == 0){
        n /= i;
      }
    }
  }
  if (n > 1){
    pf.push_back(n);
  }
  if (pf.size() >= 2){
    cout << 1 << endl;
  } else if (pf.size() == 1){
    cout << pf[0] << endl;
  } else {
    cout << 1 << endl;
  }
}