#include <bits/stdc++.h>
using namespace std;
long long INF = 1000000000000000000;
int ll_sqrt(long long x){
  long long fv = 1000000001;
  long long tv = -1;
  while (fv - tv > 1){
    long long mv = (tv + fv) / 2;
    if (mv * mv <= x){
      tv = mv;
    } else {
      fv = mv;
    }
  }
  return tv;
}
int main(){
  vector<long long> power;
  //p>2
  for (long long i = 2; i <= 1000000; i++){
    if (ll_sqrt(i) * ll_sqrt(i) == i){
      continue;
    }
    int exp = 3;
    long long tmp = i * i * i;
    while (1){
      if (exp % 2 == 1){
        power.push_back(tmp);
      }
      if (tmp > INF / i){
        break;
      }
      tmp *= i;
      exp++;
    }
  }
  sort(power.begin(), power.end());
  power.erase(unique(power.begin(), power.end()), power.end());
  /*
  cout << power.size() << endl;
  for (int i = 0; i < 100; i++){
    cout << power[i] << ' ';
  }
  cout << endl;
  */
  int Q;
  cin >> Q;
  for (int i = 0; i < Q; i++){
    long long L, R;
    cin >> L >> R;
    auto itr1 = upper_bound(power.begin(), power.end(), R);
    auto itr2 = lower_bound(power.begin(), power.end(), L);
    int ans1 = itr1 - itr2;
    int ans2 = ll_sqrt(R) - ll_sqrt(L - 1);
    cout << ans1 + ans2 << endl;
  }
}