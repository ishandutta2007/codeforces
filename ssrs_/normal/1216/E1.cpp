#include <bits/stdc++.h>
using namespace std;
long long ten(int n){
  long long ans = 1;
  for (int i = 0; i < n; i++){
    ans *= 10;
  }
  return ans;
}
long long ap(long long a, long long n, int d){
  return (a * 2 + (n - 1) * d) * n / 2;
}
long long count(long long x){
  long long ans = 0;
  long long curr = 0;
  for (int i = 1; i <= 9; i++){
    long long A = ten(i - 1);
    long long B = ten(i) - 1;
    if (x < A){
      break;
    }
    B = min(B, x);
    ans += ap(curr + i, B - A + 1, i);
    curr += ten(i - 1) * 9 * i;
  }
  return ans;
}
int main(){
  int q;
  cin >> q;
  for (int i = 0; i < q; i++){
    long long k;
    cin >> k;
    int tv = 0, fv = 500000000;
    while (fv - tv > 1){
      int mid = (tv + fv) / 2;
      if (count(mid) < k){
        tv = mid;
      } else {
        fv = mid;
      }
    }
    int id = k - count(tv);
    id--;
    for (int j = 1; j <= 10; j++){
      long long sum = j * ten(j - 1) * 9;
      if (id < sum){
        int num = id / j + ten(j - 1);
        int r = id % j;
        cout << to_string(num)[r] << endl;
        break;
      }
      id -= sum;
    }
  }
}