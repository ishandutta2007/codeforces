#include <bits/stdc++.h>
using namespace std;
const int P = 100;
int main(){
  int query = 0;
  int n;
  cin >> n;
  vector<bool> exist(n + 1, true);
  exist[0] = false;
  int sum = n;
  vector<bool> is_prime(n + 1, true);
  is_prime[0] = false;
  is_prime[1] = false;
  for (int i = 2; i <= n; i++){
    if (is_prime[i]){
      for (int j = i * 2; j <= n; j += i){
        is_prime[j] = false;
      }
    }
  }
  vector<int> prime;
  for (int i = 2; i <= n; i++){
    if (is_prime[i]){
      prime.push_back(i);
    }
  }
  int cnt = prime.size();
  int x = 1;
  vector<int> pf;
  bool ok = false;
  for (int i = 0; i < (cnt + P - 1) / P; i++){
    int L = P * i;
    int R = min(P * (i + 1), cnt);
    if (x * prime[L] > n){
      break;
    }
    for (int j = L; j < R; j++){
      if (x * prime[j] > n){
        break;
      }
      query++;
      assert(query <= 10000);
      cout << "B " << prime[j] << endl;
      int res;
      cin >> res;
      int tmp = 0;
      for (int k = prime[j]; k <= n; k += prime[j]){
        if (exist[k]){
          exist[k] = false;
          sum--;
          tmp++;
        }
      }
      if (res != tmp){
        x *= prime[j];
        pf.push_back(prime[j]);
      }
    }
    if (!ok){
      query++;
      assert(query <= 10000);
      cout << "A 1" << endl;
      int res;
      cin >> res;
      if (res != sum){
        for (int j = L; j < R; j++){
          if (x * prime[j] > n){
            break;
          }
          query++;
          assert(query <= 10000);
          cout << "A " << prime[j] << endl;
          int res;
          cin >> res;
          if (res == 1){
            x *= prime[j];
            pf.push_back(prime[j]);
            break;
          }
        }
      }
      if (x > 1){
        ok = true;
      }
    }
  }
  for (long long a : pf){
    long long check = a * a;
    while (check <= n && a * x <= n){
      query++;
      assert(query <= 10000);
      cout << "A " << check << endl;
      int res;
      cin >> res;
      if (res == 1){
        x *= a;
      } else {
        break;
      }
      check *= a;
    }
  }
  query++;
  assert(query <= 10000);
  cout << "C " << x << endl;
}