#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> p(n / 2);
  for (int i = 0; i < n / 2; i++){
    cin >> p[i];
  }
  sort(p.begin(), p.end());
  int ans1 = 0, ans2 = 0;
  for (int i = 0; i < n / 2; i++){
    ans1 += abs(p[i] - (i * 2 + 1));
    ans2 += abs(p[i] - (i * 2 + 2));
  }
  cout << min(ans1, ans2) << endl;
}