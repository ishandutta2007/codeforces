#include <bits/stdc++.h>
using namespace std;
const int INF = 1000;
int solve(int b, int c){
  //x^2+bx=c
  int tv = INF;
  int fv = -1;
  while (tv - fv > 1){
    int mid = (tv + fv) / 2;
    if (mid * mid + b * mid >= c){
      tv = mid;
    } else {
      fv = mid;
    }
  }
  return tv;
}
int main(){
  int n;
  cin >> n;
  vector<int> a(n * n);
  for (int i = 0; i < n * n; i++){
    cin >> a[i];
  }
  map<int, int> mp;
  for (int i = 0; i < n * n; i++){
    mp[a[i]]++;
  }
  vector<pair<int, int>> P;
  for (auto p : mp){
    P.push_back(p);
  }
  int m = P.size();
  map<int, int> mp2;
  vector<int> ans;
  map<int, int> mp3;
  for (int i = m - 1; i >= 0; i--){
    int num = P[i].first;
    int cnt = P[i].second;
    //cout << "num = " << num << ", cnt = " << cnt << endl;
    cnt -= mp2[num];
    //cout << "cnt = " << cnt << endl;
    if (cnt > 0){
      int b = 0;
      for (auto p : mp3){
        if (gcd(p.first, num) == num){
          b += p.second * 2;
        }
      }
      //cout << "b = " << b << endl;
      int c = solve(b, cnt);
      //cout << "c = " << c << endl;
      mp2[num] += c;
      mp3[num] = c;
      for (int j = 0; j < c; j++){
        ans.push_back(num);
      }
      for (auto p : mp3){
        if (p.first != num){
          mp2[gcd(p.first, num)] += c * p.second * 2;
        }
      }
    }
  }
  for (int i = 0; i < n; i++){
    cout << ans[i];
    if (i < n - 1){
      cout << ' ';
    }
  }
  cout << endl;
}