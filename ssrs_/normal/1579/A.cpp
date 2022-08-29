#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string s;
    cin >> s;
    int N = s.size();
    vector<int> cnt(3, 0);
    for (int j = 0; j < N; j++){
      cnt[s[j] - 'A']++;
    }
    if (cnt[1] == cnt[0] + cnt[2]){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}