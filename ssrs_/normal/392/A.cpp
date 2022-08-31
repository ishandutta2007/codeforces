#include <bits/stdc++.h>
using namespace std;
int main(){
  long long n;
  cin >> n;
  if (n == 0){
    cout << 1 << endl;
  } else {
    vector<int> a(n);
    for (long long i = 0; i < n; i++){
      a[i] = (int) (sqrt(n * n - (n - i) * (n - i)) + 0.00001);
    }
    int ans = 1;
    for (int i = 0; i < n - 1; i++){
      ans += max(a[i + 1] - a[i], 1);
    }
    cout << ans * 4 << endl;
  }
}