#include <bits/stdc++.h>
using namespace std;
const double EPS = 0.000000001;
struct point{
  double x, y;
  point(){
  }
  point(double x, double y): x(x), y(y){
  }
  point operator -(point P){
    return point(x - P.x, y - P.y);
  }
  point operator *(double k){
    return point(x * k, y * k);
  }
  point operator /(double k){
    return point(x / k, y / k);
  }
  pair<int, int> C(){
    int x2 = (x + EPS) * 10000000;
    int y2 = (y + EPS) * 10000000;
    return make_pair(x2, y2);
  }
};
void dfs(vector<vector<tuple<string, point, double>>> &P, int m, string S, double sx, double sy, double s, int h){
  if (S.size() == m){
    P[h].push_back(make_tuple(S, point(sx / s, sy / s), s));
  } else {
    int l = S.size();
    double sx2 = sx + (double) 1 / 3 + (double) (l + h) / 2 + l * h;
    double sy2 = sy + (double) h * h / 2 + h + (double) (1 - h) / 2 - (double) 1 / 3;
    double s2 = s + (double) (h * 2 + 1) / 2;
    dfs(P, m, S + '(', sx2, sy2, s2, h + 1);
    if (h > 0){
      double sx3 = sx + (double) 1 / 3 + (double) (l + h - 1) / 2 + l * (h - 1);
      double sy3 = sy + (double) (h - 1) * (h - 1) / 2 + (h - 1) + (double) (2 - h) / 2 - (double) 1 / 3;
      double s3 = s + (double) (h * 2 - 1) / 2;
      dfs(P, m, S + ')', sx3, sy3, s3, h - 1);
    }
  }
}
int main(){
  int n;
  point G;
  cin >> n >> G.x >> G.y;
  int m = n / 2;
  vector<vector<tuple<string, point, double>>> P(m + 1);
  dfs(P, m, "", 0, 0, 0, 0);
  string ans;
  for (int i = 0; i <= m; i++){
    if ((m - i) % 2 == 0){
      int cnt = P[i].size();
      map<int, map<pair<int, int>, string>> mp;
      for (int j = 0; j < cnt; j++){
        double s = get<2>(P[i][j]);
        int s2 = (s + EPS) * 2;
        point Q = get<1>(P[i][j]);
        Q.x = n - Q.x;
        pair<int, int> C = Q.C();
        string S = get<0>(P[i][j]);
        string S2;
        for (int k = 0; k < m; k++){
          if (S[m - 1 - k] == '('){
            S2 += ')';
          } else {
            S2 += '(';
          }
        }
        mp[s2][C] = S2;
      }
      for (int j = 0; j < cnt; j++){
        string S1 = get<0>(P[i][j]);
        point G1 = get<1>(P[i][j]);
        double s1 = get<2>(P[i][j]);
        for (auto &&e : mp){
          double s2 = ((double) e.first) / 2;
          point G2 = (G * (s1 + s2) - G1 * s1) / s2;
          pair<int, int> C = G2.C();
          if (e.second.count(C)){
            string S2 = e.second[C];
            ans = S1 + S2;
            break;
          }
        }
        if (ans != ""){
          break;
        }
      }
    }
    if (ans != ""){
      break;
    }
  }
  cout << ans << endl;
}