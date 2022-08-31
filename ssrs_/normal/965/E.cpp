#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; i++){
    cin >> s[i];
  }
  vector<tuple<vector<int>, char, bool, int, int>> Trie(1);
  get<1>(Trie[0]) = ' ';
  get<2>(Trie[0]) = false;
  get<3>(Trie[0]) = 0;
  get<4>(Trie[0]) = -1;
  for (int i = 0; i < n; i++){
    int v = 0;
    for (char c : s[i]){
      bool flg = false;
      for (int j : get<0>(Trie[v])){
        if (c == get<1>(Trie[j])){
          v = j;
          flg = true;
          break;
        }
      }
      if (!flg){
        int d = get<3>(Trie[v]);
        int p = v;
        get<0>(Trie[v]).push_back(Trie.size());
        v = Trie.size();
        Trie.push_back(make_tuple(vector<int>(0), c, false, d + 1, p));
      }
    }
    get<2>(Trie[v]) = true;
  }
  int N = Trie.size();
  /*
  for (int i = 0; i < N; i++){
    cout << i << ": ";
    for (int j : get<0>(Trie[i])){
      cout << j << ' ';
    }
    cout << get<1>(Trie[i]) << ' ' << get<2>(Trie[i]) << endl;
  }
  */
  priority_queue<pair<int, int>> Q;
  for (int i = 1; i < N; i++){
    if (get<2>(Trie[i])){
      Q.push(make_pair(get<3>(Trie[i]), i));
    }
  }
  long long ans = 0;
  while (!Q.empty()){
    int d = Q.top().first;
    int v = Q.top().second;
    Q.pop();
    int w = v;
    while (w != 0){
      w = get<4>(Trie[w]);
      if (!get<2>(Trie[w])){
        break;
      }
    }
    if (w != 0){
      get<2>(Trie[v]) = false;
      get<2>(Trie[w]) = true;
      Q.push(make_pair(get<3>(Trie[w]), w));
    } else {
      ans += d;
    }
  }
  cout << ans << endl;
}