#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int main(){
  int n, k;
  cin >> n >> k;
  vector<int> p(n);
  for (int i = 0; i < n; i++){
    cin >> p[i];
  }
  vector<int> p2 = p;
  sort(p2.begin(), p2.end());
  reverse(p2.begin(), p2.end());
  long long sum = 0;
  set<int> p3;
  for (int i = 0; i < k; i++){
    sum += p2[i];
    p3.insert(p2[i]);
  }
  vector<int> pos;
  for (int i = 0; i < n; i++){
    if (p3.count(p[i])){
      pos.push_back(i);
    }
  }
  long long num = 1;
  for (int i = 0; i < pos.size() - 1; i++){
    num *= (pos[i + 1] - pos[i]);
    num %= MOD;
  }
  cout << sum << ' ' << num << endl;
}