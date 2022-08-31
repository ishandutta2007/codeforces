#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    long long n;
    cin >> n;
    long long S = 3;
    while (1){
      if (n % S == 0){
        cout << n / S << endl;
        break;
      }
      S = S * 2 + 1;
    }
  }
}