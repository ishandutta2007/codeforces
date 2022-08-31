#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  set<int> F;
  set<int> L;
  long long Fsum = 0;
  long long Lsum = 0;
  set<int> S1;
  set<int> S2;
  long long S1sum = 0;
  for (int i = 0; i < n; i++){
    int tp, d;
    cin >> tp >> d;
    if (tp == 0){
      if (d > 0){
        F.insert(d);
        S2.insert(d);
        Fsum += d;
      } else {
        F.erase(- d);
        if (S1.count(- d)){
          S1.erase(- d);
          S1sum += d;
        } else {
          S2.erase(- d);
        }
        Fsum += d;
      }
    }
    if (tp == 1){
      if (d > 0){
        L.insert(d);
        S2.insert(d);
        Lsum += d;
      } else {
        L.erase(- d);
        if (S1.count(- d)){
          S1.erase(- d);
          S1sum += d;
        } else {
          S2.erase(- d);
        }
        Lsum += d;
      }
    }
    if (S1.empty() && S2.empty()){
      cout << 0 << "\n";
    } else {
      if (S1.empty()){
        S1.insert(*prev(S2.end()));
        S1sum += *prev(S2.end());
        S2.erase(prev(S2.end()));
      }
      if (!S2.empty()){
        while (*S1.begin() < *prev(S2.end())){
          S1.insert(*prev(S2.end()));
          S1sum += *prev(S2.end());
          S2.erase(prev(S2.end()));
          if (S2.empty()){
            break;
          }
        }
      }
      while (S1.size() > L.size()){
        S1sum -= *S1.begin();
        S2.insert(*S1.begin());
        S1.erase(S1.begin());
      }
      while (S1.size() < L.size()){
        S1.insert(*prev(S2.end()));
        S1sum += *prev(S2.end());
        S2.erase(prev(S2.end()));
      }
      long long ans = Fsum + Lsum + S1sum;
      if (!L.empty() && !F.empty()){
        if (*L.begin() > *prev(F.end())){
          ans -= *L.begin();
          ans += *prev(F.end());
        }
      }
      if (F.empty()){
        ans -= *L.begin();
      }
      cout << ans << "\n";
    }
  }
}