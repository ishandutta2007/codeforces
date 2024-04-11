#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m, k;
  cin >> n >> m >> k;
  long long S = (long long) 2 * n * m;
  if (S % k != 0){
    cout << "NO" << endl;
  } else {
    S /= k;
    cout << "YES" << endl;
    cout << 0 << ' ' << 0 << endl;
    cout << n << ' ' << 1 << endl;
    cout << n - (S - 1) % n - 1 << ' ' << (S + n - 1) / n << endl;
  }
}