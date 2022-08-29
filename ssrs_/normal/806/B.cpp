#include <bits/stdc++.h>
using namespace std;
bool ok(vector<vector<int>> &a, int n, vector<int> &s, vector<int> &cnt, int mid){
  long long p = n + mid; //number of participants
  int V_score = 0;
  int P_score = 0;
  for (int i = 0; i < 5; i++){
    long long solver = cnt[i];
    if (s[i] == 1){
      //WA
      solver = cnt[i];
    }
    if (s[i] == -1){
      //AC
      solver = cnt[i] + mid;
    }
    int mx;
    if (solver * 2 > p){
      mx = 500;
    } else if (solver * 4 > p){
      mx = 1000;
    } else if (solver * 8 > p){
      mx = 1500;
    } else if (solver * 16 > p){
      mx = 2000;
    } else if (solver * 32 > p){
      mx = 2500;
    } else {
      mx = 3000;
    }
    if (a[0][i] != -1){
      V_score += mx - mx / 250 * a[0][i];
    }
    if (a[1][i] != -1){
      P_score += mx - mx / 250 * a[1][i];
    }
  }
  return V_score > P_score;
}
int main(){
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(5));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < 5; j++){
      cin >> a[i][j];
    }
  }
  vector<int> cnt(5, 0);
  for (int i = 0; i < n; i++){
    for (int j = 0; j < 5; j++){
      if (a[i][j] != -1){
        cnt[j]++;
      }
    }
  }
  vector<int> s(5);
  for (int i = 0; i < 5; i++){
    if (a[0][i] == -1){
      s[i] = 1;
    } else if (a[1][i] == -1){
      s[i] = 1;
    } else if (a[0][i] < a[1][i]){
      s[i] = 1;
    } else {
      s[i] = -1;
    }
  }
  int V_score_tmp = 0;
  int P_score_tmp = 0;
  for (int i = 0; i < 5; i++){
    int mx;
    if (cnt[i] * 2 > n){
      mx = 500;
    } else if (cnt[i] * 4 > n){
      mx = 1000;
    } else if (cnt[i] * 8 > n){
      mx = 1500;
    } else if (cnt[i] * 16 > n){
      mx = 2000;
    } else if (cnt[i] * 32 > n){
      mx = 2500;
    } else {
      mx = 3000;
    }
    if (a[0][i] != -1){
      V_score_tmp += mx - mx / 250 * a[0][i];
    }
    if (a[1][i] != -1){
      P_score_tmp += mx - mx / 250 * a[1][i];
    }
  }
  if (V_score_tmp > P_score_tmp){
    cout << 0 << endl;
  } else {
    //s[i]=1 -> submit WA
    //s[i]=-1 -> submit AC
    //range?
    vector<int> R;
    R.push_back(0);
    for (int i = 0; i < 5; i++){
      if (a[0][i] == -1 && a[1][i] != -1){
        for (int j = 2; j <= 32; j *= 2){
          if (n < cnt[i] * j){
            R.push_back(cnt[i] * j - n - 1);
          }
        }
      }
    }
    R.push_back(1000000008);
    sort(R.begin(), R.end());
    int m = R.size();
    int ans = 1000000008;
    for (int i = 0; i < m - 1; i++){
      long long tv = R[i + 1];
      long long fv = R[i] - 1;
      while (tv - fv > 1){
        long long mid = (tv + fv) / 2;
        if (ok(a, n, s, cnt, mid)){
          tv = mid;
        } else {
          fv = mid;
        }
      }
      if (ok(a, n, s, cnt, tv)){
        ans = tv;
        break;
      }
    }
    if (ans == 1000000008){
      cout << -1 << endl;
    } else {
      cout << ans << endl;
    }
  }
}