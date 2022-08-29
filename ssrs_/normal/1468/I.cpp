#include <bits/stdc++.h>
using namespace std;
int main(){
  random_device rnd;
  mt19937 mt(rnd());
  int n;
  cin >> n;
  long long dx1, dy1;
  cin >> dx1 >> dy1;
  long long dx2, dy2;
  cin >> dx2 >> dy2;
  long long D = abs(dx1 * dy2 - dy1 * dx2);
  if (D != n){
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    set<pair<long long, long long>> st;
    int cnt = 0;
    while (cnt < n){
      long long x = mt() % 1000000000;
      long long y = mt() % 1000000000;
      long long A = x * dy1 - y * dx1;
      long long B = x * dy2 - y * dx2;
      A = (A % D + D) % D;
      B = (B % D + D) % D;
      if (!st.count(make_pair(A, B))){
        cout << x << ' ' << y << endl;
        st.insert(make_pair(A, B));
        cnt++;
      }
    }
  }
}