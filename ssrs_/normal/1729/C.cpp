#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string s;
    cin >> s;
    int N = s.size();
    if (s[0] > s[N - 1]){
      for (int j = 0; j < N; j++){
        s[j] = 'a' + ('z' - s[j]);
      }
    }
    vector<pair<int, int>> P(N);
    for (int j = 0; j < N; j++){
      P[j] = make_pair(s[j] - 'a', j);
    }
    sort(P.begin(), P.end());
    int a = lower_bound(P.begin(), P.end(), make_pair(s[0] - 'a', 0)) - P.begin();
    int b = lower_bound(P.begin(), P.end(), make_pair(s[N - 1] - 'a', N - 1)) - P.begin();
    int cost = s[N - 1] - s[0];
    cout << cost << ' ' << b - a + 1 << endl;
    for (int j = a; j <= b; j++){
      cout << P[j].second + 1;
      if (j < b){
        cout << ' ';
      }
    }
    cout << endl;
  }
}