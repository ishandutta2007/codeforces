#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> letter(string s, int &p);
vector<vector<char>> atom(string s, int &p);
vector<vector<char>> term(string s, int &p);
vector<vector<char>> expr(string s, int &p);
vector<vector<char>> letter(string s, int &p){
  char c = s[p];
  p++;
  vector<vector<char>> ans(3, vector<char>(5, ' '));
  for (int i = 0; i < 3; i++){
    ans[i][0] = '+';
    ans[i][4] = '+';
  }
  for (int i = 1; i < 4; i++){
    ans[0][i] = '-';
    ans[2][i] = '-';
  }
  ans[1][2] = c;
  return ans;
}
vector<vector<char>> atom(string s, int &p){
  vector<vector<char>> tmp;
  if (s[p] == '('){
    p++;
    tmp = expr(s, p);
    if (tmp.size() == 3 && tmp[0].size() == 5){
      tmp[0][0] = '@';
    }
    p++;
  } else {
    tmp = letter(s, p);
  }
  while (true){
    if (s[p] != '+' && s[p] != '?' && s[p] != '*'){
      return tmp;
    }
    char c = s[p];
    p++;
    if (c == '+'){
      int H = tmp.size();
      int W = tmp[0].size();
      vector<vector<char>> ans(H + 2, vector<char>(W + 6, ' '));
      for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
          ans[i][j + 3] = tmp[i][j];
        }
      }
      ans[1][0] = '+';
      ans[1][1] = '-';
      ans[1][2] = '>';
      ans[1][W + 3] = '-';
      ans[1][W + 4] = '>';
      ans[1][W + 5] = '+';
      for (int i = 2; i < H + 1; i++){
        ans[i][0] = '|';
        ans[i][W + 5] = '|';
      }
      ans[H + 1][0] = '+';
      ans[H + 1][1] = '<';
      for (int i = 2; i <= W + 4; i++){
        ans[H + 1][i] = '-';
      }
      ans[H + 1][W + 5] = '+';
      tmp = ans;
    }
    if (c == '?'){
      int H = tmp.size();
      int W = tmp[0].size();
      vector<vector<char>> ans(H + 3, vector<char>(W + 6, ' '));
      for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
          ans[i + 3][j + 3] = tmp[i][j];
        }
      }
      ans[1][0] = '+';
      for (int i = 1; i <= W + 3; i++){
        ans[1][i] = '-';
      }
      ans[1][W + 4] = '>';
      ans[1][W + 5] = '+';
      ans[2][0] = '|';
      ans[2][W + 5] = '|';
      ans[3][0] = '|';
      ans[3][W + 5] = '|';
      ans[4][0] = '+';
      ans[4][1] = '-';
      ans[4][2] = '>';
      ans[4][W + 3] = '-';
      ans[4][W + 4] = '>';
      ans[4][W + 5] = '+';
      swap(tmp, ans);
    }
    if (c == '*'){
      int H = tmp.size();
      int W = tmp[0].size();
      vector<vector<char>> ans(H + 5, vector<char>(W + 6, ' '));
      for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
          ans[i + 3][j + 3] = tmp[i][j];
        }
      }
      ans[1][0] = '+';
      for (int i = 1; i < W + 4; i++){
        ans[1][i] = '-';
      }
      ans[1][W + 4] = '>';
      ans[1][W + 5] = '+';
      ans[2][0] = '|';
      ans[2][W + 5] = '|';
      ans[3][0] = '|';
      ans[3][W + 5] = '|';
      ans[4][0] = '+';
      ans[4][1] = '-';
      ans[4][2] = '>';
      ans[4][W + 3] = '-';
      ans[4][W + 4] = '>';
      ans[4][W + 5] = '+';
      for (int i = 5; i < H + 4; i++){
        ans[i][0] = '|';
        ans[i][W + 5] = '|';
      }
      ans[H + 4][0] = '+';
      ans[H + 4][1] = '<';
      for (int i = 2; i < W + 5; i++){
        ans[H + 4][i] = '-';
      }
      ans[H + 4][W + 5] = '+';
      swap(tmp, ans);
    }
  }
}
vector<vector<char>> term(string s, int &p){
  vector<vector<vector<char>>> atoms(1);
  atoms[0] = atom(s, p);
  while (s[p] != '|' && s[p] != '$' && s[p] != ')'){
    atoms.push_back(atom(s, p));
  }
  int N = atoms.size();
  for (int i = 0; i < N; i++){
    int h = atoms[i].size();
    int w = atoms[i][0].size();
  }
  int H = 0;
  for (int i = 0; i < N; i++){
    H = max(H, (int) atoms[i].size());
  }
  vector<vector<char>> ans = atoms[0];
  while (ans.size() < H){
    int w = atoms[0][0].size();
    ans.push_back(vector<char>(w, ' '));
  }
  for (int i = 1; i < N; i++){
    for (int j = 0; j < H; j++){
      ans[j].push_back(' ');
      ans[j].push_back(' ');
    }
    int W = ans[0].size();
    ans[1][W - 2] = '-';
    ans[1][W - 1] = '>';
    int H2 = atoms[i].size();
    int W2 = atoms[i][0].size();
    for (int j = 0; j < H2; j++){
      for (int k = 0; k < W2; k++){
        ans[j].push_back(atoms[i][j][k]);
      }
    }
    for (int j = H2; j < H; j++){
      for (int k = 0; k < W2; k++){
        ans[j].push_back(' ');
      }
    }
    if (atoms[i - 1].size() == 3 && atoms[i].size() == 3){
      if (atoms[i - 1][0].size() == 5 && atoms[i][0].size() == 5){
        if (atoms[i - 1][0][0] != '@' && atoms[i][0][0] != '@'){
          for (int j = 0; j < 6; j++){
            for (int k = 0; k < H; k++){
              ans[k].erase(ans[k].begin() + W - 4);
            }
          }
        }
      }
    }
  }
  return ans;
}
vector<vector<char>> expr(string s, int &p){
  vector<vector<vector<char>>> terms(1);
  terms[0] = term(s, p);
  while (s[p] == '|'){
    p++;
    terms.push_back(term(s, p));
  }
  int N = terms.size();
  if (N == 1){
    return terms[0];
  }
  int W = 0;
  for (int i = 0; i < N; i++){
    W = max(W, (int)terms[i][0].size());
  }
  W += 6;
  vector<vector<char>> ans;
  for (int i = 0; i < N; i++){
    int h = terms[i].size();
    int w = terms[i][0].size();
    for (int j = 0; j < h; j++){
      ans.push_back(vector<char>(W, ' '));
      if (j == 1){
        ans.back()[0] = '+';
        ans.back()[1] = '-';
        ans.back()[2] = '>';
      }
      for (int k = 0; k < w; k++){
        ans.back()[k + 3] = terms[i][j][k];
      }
      if (j == 1){
        for (int k = w + 3; k < W - 2; k++){
          ans.back()[k] = '-';
        }
        ans.back()[W - 2] = '>';
        ans.back()[W - 1] = '+';
      }
      if (j != 1){
        if (!(j == 0 && i == 0) && !(j >= 2 && i == N - 1)){
          ans.back()[0] = '|';
          ans.back()[W - 1] = '|';
        }
      }
    }
    if (i < N - 1){
      ans.push_back(vector<char>(W, ' '));
      ans.back()[0] = '|';
      ans.back()[W - 1] = '|';
    }
  }
  return ans;
}
vector<vector<char>> input(string s){
  s += '$';
  int p = 0;
  vector<vector<char>> res = expr(s, p);
  int H = res.size();
  int W = res[0].size();
  vector<vector<char>> ans(H, vector<char>(W + 6, ' '));
  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
      if (res[i][j] == '@'){
        res[i][j] = '+';
      }
      ans[i][j + 3] = res[i][j];
    }
  }
  ans[1][0] = 'S';
  ans[1][1] = '-';
  ans[1][2] = '>';
  ans[1][W + 3] = '-';
  ans[1][W + 4] = '>';
  ans[1][W + 5] = 'F';
  return ans;
}
int main(){
  string s;
  cin >> s;
  vector<vector<char>> ans = input(s);
  int h = ans.size();
  int w = ans[0].size();
  cout << h << ' ' << w << endl;
  for (int i = 0; i < h; i++){
    for (int j = 0; j < w; j++){
      cout << ans[i][j];
    }
    cout << endl;
  }
}