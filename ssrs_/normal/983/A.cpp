#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++){
    long long p, q, b;
    cin >> p >> q >> b;
    long long g = gcd(p, q);
    p /= g;
    q /= g;
    while (1){
      long long g2 = gcd(q, b);
      if (g2 == 1){
        break;
      }
      while (q % g2 == 0){
        q /= g2;
      }
    }
    if (q == 1){
      cout << "Finite" << "\n";
    } else {
      cout << "Infinite" << "\n";
    }
  }
}