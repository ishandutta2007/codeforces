#include <bits/stdc++.h>
using namespace std;
long long INF = 1000000000000000000;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> b(n - 1);
  for (int i = 0; i < n - 1; i++){
    b[i] = abs(a[i + 1] - a[i]);
    if (i % 2 == 1){
      b[i] = -b[i];
    }
  }
  int b0 = b[0];
  vector<long long> S(n - 1, 0);
  S[0] = 0;
  for (int i = 1; i < n - 1; i++){
    S[i] = S[i - 1] + b[i];
  }
  /*
  for (int i = 0; i < n - 1; i++){
    cout << S[i] << ' ';
  }
  cout << endl;
  */
  long long ans1 = 0;
  long long min_S = INF;
  long long max_S = -INF;
  for (int i = 0; i < n - 2; i++){
    min_S = min(min_S, S[i]);
    max_S = max(max_S, S[i]);
    ans1 = max(ans1, abs(min_S - S[i + 1]));
    ans1 = max(ans1, abs(max_S - S[i + 1]));
  }
  //cout << "ans1 = " << ans1 << endl;
  long long ans2 = b0;
  long long c = b0;
  for (int i = 1; i < n - 1; i++){
    c += b[i];
    ans2 = max(ans2, c);
  }
  //cout << "ans2 = " << ans2 << endl;
  cout << max(ans1, ans2) << endl;
}