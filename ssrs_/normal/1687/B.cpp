#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  vector<int> l(m);
  for (int i = 0; i < m; i++){
    string s(m, '0');
    s[i] = '1';
    cout << "? " << s << endl;
    cin >> l[i];
  }
  vector<pair<int, int>> P(m);
  for (int i = 0; i < m; i++){
    P[i] = make_pair(l[i], i);
  }
  sort(P.begin(), P.end());
  string s(m, '0');
  int sum = 0;
  for (int i = 0; i < m; i++){
    string t = s;
    int p = P[i].second;
    t[p] = '1';
    cout << "? " << t << endl;
    int res;
    cin >> res;
    if (res - sum == P[i].first){
      s = t;
      sum += P[i].first;
    }
  }
  cout << "! " << sum << endl;
}