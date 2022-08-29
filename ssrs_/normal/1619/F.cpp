#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m, k;
    cin >> n >> m >> k;
    int q = n / m, r = n % m;
    int s = 0;
    for (int j = 0; j < k; j++){
      int c = s;
      for (int l = 0; l < r; l++){
        cout << q + 1;
        for (int o = 0; o <= q; o++){
          cout << ' ' << c + 1;
          c = (c + 1) % n;
        }
        cout << endl;
      }
      for (int l = r; l < m; l++){
        cout << q;
        for (int o = 0; o < q; o++){
          cout << ' ' << c + 1;
          c = (c + 1) % n;
        }
        cout << endl;
      }
      s = (s + (long long) r * (q + 1)) % n;
    }
  }
}