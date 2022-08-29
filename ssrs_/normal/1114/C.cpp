#include <bits/stdc++.h>
using namespace std;
const long long INF = 3000000000000000000;
int main(){
  long long n, b;
  cin >> n >> b;
  vector<pair<long long, int>> f;
  for (long long i = 2; i * i <= b; i++){
    if (b % i == 0){
      int cnt = 0;
      while (b % i == 0){
        cnt++;
        b /= i;
      }
      f.push_back(make_pair(i, cnt));
    }
  }
  if (b > 1){
    f.push_back(make_pair(b, 1));
  }
  int cnt = f.size();
  long long ans = INF;
  for (int i = 0; i < cnt; i++){
    long long tmp = n;
    long long cnt2 = 0;
    while (tmp > 0){
      tmp /= f[i].first;
      cnt2 += tmp;
    }
    ans = min(ans, cnt2 / f[i].second);
  }
  cout << ans << endl;
}