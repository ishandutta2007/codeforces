#include <bits/stdc++.h>
using namespace std;
long long MOD = 998244353;
int INF = 1000000000;
int main(){
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> b(m);
  for (int i = 0; i < m; i++){
    cin >> b[i];
  }
  if (n < m){
    cout << 0 << endl;
  } else {
    set<int> a2;
    for (int i = 0; i < n; i++){
      a2.insert(a[i]);
    }
    bool ok = true;
    for (int i = 0; i < m; i++){
      if (!a2.count(b[i])){
        ok = false;
        break;
      }
    }
    if (!ok){
      cout << 0 << endl;
    } else {
      map<int, int> mp;
      for (int i = 0; i < n; i++){
        mp[a[i]] = max(mp[a[i]], i);
      }
      vector<int> pos(m);
      for (int i = 0; i < m; i++){
        pos[i] = mp[b[i]];
      }
      for (int i = 0; i < m - 1; i++){
        if (pos[i] >= pos[i + 1]){
          ok = false;
          break;
        }
      }
      if (!ok){
        cout << 0 << endl;
      } else {
        for (int i = 0; i < pos[0]; i++){
          if (a[i] < b[0]){
            ok = false;
            break;
          }
        }
        for (int i = pos[m - 1] + 1; i < n; i++){
          if (a[i] < b[m - 1]){
            ok = false;
            break;
          }
        }
        if (!ok){
          cout << 0 << endl;
        } else {
          for (int i = 0; i < m - 1; i++){
            for (int j = pos[i] + 1; j < pos[i + 1]; j++){
              if (a[j] < b[i]){
                ok = false;
                break;
              }
            }
            if (!ok){
              break;
            }
          }
          if (!ok){
            cout << 0 << endl;
          } else {
            long long ans = 1;
            for (int i = 0; i < m - 1; i++){
              for (int j = pos[i + 1]; j >= pos[i]; j--){
                if (a[j] < b[i + 1]){
                  //cout << "pos[i + 1] = " << pos[i + 1] << ", b[i + 1] = " << b[i + 1] << ", a[j] = " << a[j] << endl;
                  ans *= pos[i + 1] - j;
                  ans %= MOD;
                  break;
                }
              }
            }
            cout << ans << endl;
          }
        }
      }
    }
  }
}