#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
    a[i]--;
  }
  vector<int> b(n);
  for (int i = 0; i < n; i++){
    cin >> b[i];
    b[i]--;
  }
  vector<int> p(n);
  for (int i = 0; i < n; i++){
    p[a[i]] = i;
  }
  vector<int> q(n);
  for (int i = 0; i < n; i++){
    q[b[i]] = i;
  }
  map<int, int> mp;
  int ans = 0;
  for (int i = 0; i < n; i++){
    int tmp = p[i] - q[i];
    if (tmp < 0){
      tmp += n;
    }
    mp[tmp]++;
    ans = max(ans, mp[tmp]);
  }
  cout << ans << endl;
}