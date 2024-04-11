#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
  int t; cin >> t;
  while(t--){
      vector<int> v(4);
      for(auto &x : v)cin >> x;
      sort(v.begin(), v.end());
      cout << v[0]*v[2] << "\n";
  }
}