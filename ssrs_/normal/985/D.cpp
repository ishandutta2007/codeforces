#include <bits/stdc++.h>
using namespace std;
const long long INF = 2000000000;
long long ap(long long a, long long b){
  return (b + a) * (b - a + 1) / 2;
}
int main(){
  long long n, H;
  cin >> n >> H;
  long long tv = min(n, INF), fv = 0;
  while (tv - fv > 1){
    long long mid = (tv + fv) / 2;
    long long sum;
    if (mid <= H){
      sum = ap(1, mid);
    } else {
      if ((mid - H) % 2 == 0){
        long long h = (mid + H) / 2;
        sum = ap(1, h) + ap(H, h - 1);
      } else {
        long long h = (mid + H) / 2;
        sum = ap(1, h) + ap(H, h);
      }
    }
    if (sum >= n){
      tv = mid;
    } else {
      fv = mid;
    }
  }
  cout << tv << endl;
}