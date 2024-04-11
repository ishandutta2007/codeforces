#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; i++){
    cin >> s[i];
  }
  vector<string> ansE(256), ansT(256), ansF(256);
  int X = (1 << 4) + (1 << 5) + (1 << 6) + (1 << 7);
  int Y = (1 << 2) + (1 << 3) + (1 << 6) + (1 << 7);
  int Z = (1 << 1) + (1 << 3) + (1 << 5) + (1 << 7);
  priority_queue<tuple<int, string, char, int>, vector<tuple<int, string, char, int>>, greater<tuple<int, string, char, int>>> pq;
  pq.push(make_tuple(1, "x", 'F', X));
  pq.push(make_tuple(1, "y", 'F', Y));
  pq.push(make_tuple(1, "z", 'F', Z));
  while (!pq.empty()){
    int l = get<0>(pq.top());
    string s = get<1>(pq.top());
    char t = get<2>(pq.top());
    int f = get<3>(pq.top());
    pq.pop();
    if (t == 'E' && ansE[f] == ""){
      ansE[f] = s;
      for (int i = 0; i < 256; i++){
        if (ansT[i] != ""){
          pq.push(make_tuple(l + 1 + ansT[i].size(), s + "|" + ansT[i], 'E', f | i));
        }
      }
      pq.push(make_tuple(1 + l + 1, "(" + s + ")", 'F', f));
    }
    if (t == 'T' && ansT[f] == ""){
      ansT[f] = s;
      for (int i = 0; i < 256; i++){
        if (ansE[i] != ""){
          pq.push(make_tuple(ansE[i].size() + 1 + l, ansE[i] + "|" + s, 'E', i | f));
        }
      }
      pq.push(make_tuple(l, s, 'E', f));
      for (int i = 0; i < 256; i++){
        if (ansF[i] != ""){
          pq.push(make_tuple(l + 1 + ansF[i].size(), s + "&" + ansF[i], 'T', f & i));
        }
      }
    }
    if (t == 'F' && ansF[f] == ""){
      ansF[f] = s;
      for (int i = 0; i < 256; i++){
        if (ansT[i] != ""){
          pq.push(make_tuple(ansT[i].size() + 1 + l, ansT[i] + "&" + s, 'T', i & f));
        }
      }
      pq.push(make_tuple(l, s, 'T', f));
      pq.push(make_tuple(1 + l, "!" + s, 'F', 255 - f));
    }
  }
  for (int i = 0; i < n; i++){
    int id = 0;
    for (int j = 7; j >= 0; j--){
      id *= 2;
      if (s[i][j] == '1'){
        id++;
      }
    }
    cout << ansE[id] << endl;
  }
}