#include <bits/stdc++.h>
using namespace std;
int INF = 1000000000;
pair<int, int> tree_diameter_2(vector<set<int>> &E, int m){
  //m: starting vertex
  int V = E.size();
  stack<int> S;
  vector<bool> U(V, false);
  U[m] = true;
  int v;
  S.push(m);
  while (!S.empty()){
    v = S.top();
    S.pop();
    for (int i : E[v]){
      if (U[i] == false){
        S.push(i);
        U[i] = true;
      }
    }
  }
  vector<bool> U2(V, false);
  U2[v] = true;
  int w;
  S.push(v);
  while (!S.empty()){
    w = S.top();
    S.pop();
    for (int i : E[w]){
      if (U2[i] == false){
        S.push(i);
        U2[i] = true;
      }
    }
  }
  return make_pair(v, w);
}
int next_vertex(vector<set<int>> &E, int s, int g){
  int V = E.size();
  stack<int> S;
  vector<bool> U(V, false);
  S.push(s);
  U[s] = true;
  while (1){
    int v = S.top();
    if (E[v].count(g)){
      return v;
    }
    S.pop();
    for (int i : E[v]){
      if (U[i] == false){
        S.push(i);
        U[i] = true;
      }
    }
  }
}
int main(){
  int n;
  cin >> n;
  int x, y;
  vector<set<int>> E(n);
  for (int i = 0; i < n - 1; i++){
    cin >> x >> y;
    x--;
    y--;
    E[x].insert(y);
    E[y].insert(x);
    //
  }
  int w = 0;
  while (1){
    pair<int, int> P = tree_diameter_2(E, w);
    cout << "? " << P.first + 1 << ' ' << P.second + 1 << endl;
    cout.flush();
    cin >> w;
    w--;
    if (E[w].size() <= 2){
      cout << "! " << w + 1;
      break;
    }
    int v1 = next_vertex(E, P.first, w);
    int v2 = next_vertex(E, P.second, w);
    E[v1].erase(w);
    E[v2].erase(w);
    E[w].erase(v1);
    E[w].erase(v2);
  }
}