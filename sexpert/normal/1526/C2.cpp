#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  ll s_pos = 0, s_neg = 0;
  int cnt = 0;
  priority_queue<ll> p_neg;
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if(x >= 0) {
      s_pos += x;
      cnt++;    
    } else {
      if(s_neg - x <= s_pos) {
        s_neg -= x;
        cnt++;
        p_neg.push(-x);
      }
      else {
        if(p_neg.size() && p_neg.top() > -x) {
          s_neg += -x - p_neg.top();
          p_neg.pop();
          p_neg.push(-x);
        }
      }
    }
  }
  cout << cnt << '\n';
}