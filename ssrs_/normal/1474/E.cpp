#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> p(n);
    for (int j = 0; j < n; j++){
      p[j] = j;
    }
    long long T = 0;
    vector<pair<int, int>> op;
    op.push_back(make_pair(0, n - 1));
    swap(p[0], p[n - 1]);
    T += (long long) (n - 1) * (n - 1);
    for (int j = 1; j < n / 2; j++){
      op.push_back(make_pair(j, n - 1));
      swap(p[n - 1], p[j]);
      T += (long long) (n - 1 - j) * (n - 1 - j);
    }
    for (int j = n / 2; j < n - 1; j++){
      op.push_back(make_pair(j, 0));
      swap(p[0], p[j]);
      T += (long long) j * j;
    }
    reverse(op.begin(), op.end());
    cout << T << endl;
    for (int j = 0; j < n; j++){
      cout << p[j] + 1;
      if (j < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
    cout << n - 1 << endl;
    for (int j = 0; j < n - 1; j++){
      cout << op[j].first + 1 << ' ' << op[j].second + 1 << endl;
    }
  }
}