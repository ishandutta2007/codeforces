#include <bits/stdc++.h>
using namespace std;
int INF = 500000;
int dist(vector<int> &B, vector<int> &N, int b, int n){
  int ans = 0;
  int m = B.size();
  for (int i = 0; i < m; i++){
    if (B[i] < b){
      if (N[i] < n){
        ans = max(ans, max(b - B[i], n - N[i]));
      } else {
        ans = max(ans, (b - B[i]) + (N[i] - n));
      }
    } else {
      if (N[i] < n){
        ans = max(ans, (B[i] - b) + (n - N[i]));
      } else {
        ans = max(ans, max(B[i] - b, N[i] - n));
      }
    }
  }
  return ans;
}
pair<int, int> f(vector<int> &B, vector<int> &N, int b){
  int nl = 0;
  int nr = INF;
  while (nr - nl > 2){
    int mid1 = (nl * 2 + nr) / 3;
    int mid2 = (nl + nr * 2) / 3;
    if (dist(B, N, b, mid1) < dist(B, N, b, mid2)){
      nr = mid2;
    } else {
      nl = mid1;
    }
  }
  int min_n = nl;
  int mx = dist(B, N, b, nl);
  for (int n = nl + 1; n <= nr; n++){
    int tmp = dist(B, N, b, n);
    if (tmp <= mx){
      min_n = n;
      mx = tmp;
    }
  }
  return make_pair(mx, min_n);
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; i++){
    cin >> s[i];
  }
  vector<int> B(n, 0), N(n, 0);
  for (int i = 0; i < n; i++){
    int m = s[i].size();
    for (int j = 0; j < m; j++){
      if (s[i][j] == 'B'){
        B[i]++;
      }
      if (s[i][j] == 'N'){
        N[i]++;
      }
    }
  }
  int bl = 0;
  int br = INF;
  while (br - bl > 2){
    int mid1 = (bl * 2 + br) / 3;
    int mid2 = (bl + br * 2) / 3;
    if (f(B, N, mid1).first < f(B, N, mid2).first){
      br = mid2;
    } else {
      bl = mid1;
    }
  }
  int min_b = bl;
  pair<int, int> P = f(B, N, bl);
  int mn = P.first;
  int min_n = P.second;
  int mx = f(B, N, bl).first;
  for (int b = bl + 1; b <= br; b++){
    pair<int, int> tmp = f(B, N, b);
    if (tmp.first <= mx){
      min_b = b;
      mx = tmp.first;
      min_n = tmp.second;
    }
  }
  int ans = mx;
  if (min_b == 0 && min_n == 0){
    int bm = dist(B, N, 1, 0);
    int nm = dist(B, N, 0, 1);
    if (bm < nm){
      ans = bm;
      min_b = 1;
    } else {
      ans = nm;
      min_n = 1;
    }
  }
  cout << ans << "\n";
  for (int i = 0; i < min_b; i++){
    cout << 'B';
  }
  for (int i = 0; i < min_n; i++){
    cout << 'N';
  }
  cout << "\n";
}