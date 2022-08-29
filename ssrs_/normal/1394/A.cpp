#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, d, m;
  cin >> n >> d >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  vector<int> b, c;
  for (int i = 0; i < n; i++){
    if (a[i] <= m){
      b.push_back(a[i]);
    } else {
      c.push_back(a[i]);
    }
  }
  sort(b.rbegin(), b.rend());
  sort(c.rbegin(), c.rend());
  int B = b.size();
  int C = c.size();
  vector<long long> Sb(B + 1, 0);
  for (int i = 0; i < B; i++){
    Sb[i + 1] = Sb[i] + b[i];
  }
  vector<long long> Sc(C + 1, 0);
  for (int i = 0; i < C; i++){
    Sc[i + 1] = Sc[i] + c[i];
  }
  long long ans = 0;
  for (int i = 0; i <= B; i++){
    ans = max(ans, Sb[i] + Sc[min((n - i + d) / (d + 1), C)]);
  }
  cout << ans << endl;
}