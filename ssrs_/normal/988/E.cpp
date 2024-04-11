#include <bits/stdc++.h>
using namespace std;
const int INF = 10000;
int bfs(string S){
  int N = S.size();
  queue<pair<int, string>> Q;
  Q.push(make_pair(0, S));
  set<string> used;
  used.insert(S);
  while (!Q.empty()){
    int d = Q.front().first;
    string T = Q.front().second;
    Q.pop();
    if (stoll(T) % 25 == 0){
      return d;
    }
    for (int i = 0; i < N - 1; i++){
      string next = T;
      swap(next[i], next[i + 1]);
      if (next[0] != '0' && !used.count(next)){
        used.insert(next);
        Q.push(make_pair(d + 1, next));
      }
    }
  }
  return INF;
}
int main(){
  long long n;
  cin >> n;
  string S = to_string(n);
  int m = S.size();
  vector<string> S2;
  {
    string tmp = S;
    int cnt = 0;
    for (int i = m - 1; i >= 0; i--){
      if (tmp[i] != '0'){
        tmp[i] = '1';
      } else {
        cnt++;
      }
    }
    if (cnt >= 2){
      S2.push_back(tmp);
    }
  }
  {
    string tmp = S;
    bool two = false, five = false;
    for (int i = m - 1; i >= 0; i--){
      if (tmp[i] == '2'){
        if (!two){
          two = true;
        } else {
          tmp[i] = '1';
        }
      } else if (tmp[i] == '5'){
        if (!five){
          five = true;
        } else {
          tmp[i] = '1';
        }
      } else if (tmp[i] != '0'){
        tmp[i] = '1';
      }
    }
    if (two && five){
      S2.push_back(tmp);
    }
  }
  {
    string tmp = S;
    bool zero = false, five = false;
    for (int i = m - 1; i >= 0; i--){
      if (tmp[i] == '5'){
        if (!five){
          five = true;
        } else {
          tmp[i] = '1';
        }
      } else if (tmp[i] == '0'){
        zero = true;
      } else {
        tmp[i] = '1';
      }
    }
    if (zero && five){
      S2.push_back(tmp);
    }
  }
  {
    string tmp = S;
    bool seven = false, five = false;
    for (int i = m - 1; i >= 0; i--){
      if (tmp[i] == '7'){
        if (!seven){
          seven = true;
        } else {
          tmp[i] = '1';
        }
      } else if (tmp[i] == '5'){
        if (!five){
          five = true;
        } else {
          tmp[i] = '1';
        }
      } else if (tmp[i] != '0'){
        tmp[i] = '1';
      }
    }
    if (seven && five){
      S2.push_back(tmp);
    }
  }
  int cnt = S2.size();
  int ans = INF;
  for (int i = 0; i < cnt; i++){
    ans = min(ans, bfs(S2[i]));
  }
  if (ans == INF){
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
}