#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string s;
    cin >> s;
    int N = s.size();
    vector<int> cnt(2, 0);
    for (int j = 0; j < N; j++){
      cnt[s[j] - '0']++;
    }
    if (min(cnt[0], cnt[1]) % 2 == 0){
      cout << "NET" << endl;
    } else {
      cout << "DA" << endl;
    }
  }
}