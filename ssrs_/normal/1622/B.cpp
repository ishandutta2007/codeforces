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
      cin >> p[j];
      p[j]--;
    }
    string s;
    cin >> s;
    int cnt = 0;
    for (int j = 0; j < n; j++){
      if (s[j] == '0'){
        cnt++;
      }
    }
    vector<int> pi(n);
    for (int j = 0; j < n; j++){
      pi[p[j]] = j;
    }
    vector<int> q(n);
    int c1 = 0, c2 = cnt;
    for (int j = 0; j < n; j++){
      if (s[pi[j]] == '0'){
        q[pi[j]] = c1;
        c1++;
      }
      if (s[pi[j]] == '1'){
        q[pi[j]] = c2;
        c2++;
      }
    }
    for (int j = 0; j < n; j++){
      cout << q[j] + 1;
      if (j < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}