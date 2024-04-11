#include <bits/stdc++.h>
using namespace std;
struct unionfind{
	vector<int> p;
  vector<int> ch;
  int cnt;
	unionfind(int N){
    p = vector<int>(N, -1);
    cnt = N;
	};
	int root(int x){
		if (p[x] == -1){
			return x;
		} else {
			p[x] = root(p[x]);
			return p[x];
		}
	}
	bool same(int x, int y){
		return root(x) == root(y);
	}
	void unite(int x, int y){
		x = root(x);
		y = root(y);
		if (x != y){
			p[x] = y;
      ch.push_back(x);
		}
    cnt--;
	}
  void reset(){
    for (int x : ch){
      p[x] = -1;
    }
    ch.clear();
    cnt = p.size();
  }
};
int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> E(m);
  for (int i = 0; i < m; i++){
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    c--;
    E[c].push_back(make_pair(a, b));
  }
  int q;
  cin >> q;
  vector<int> u(q), v(q);
  for (int i = 0; i < q; i++){
    cin >> u[i] >> v[i];
    u[i]--;
    v[i]--;
  }
  vector<int> ans(q, 0);
  vector<bitset<10000>> C(n, 0);
  vector<pair<int, int>> cc;
  int id = 0;
  unionfind UF(n);
  for (int i = 0; i < m; i++){
    for (auto P : E[i]){
      int a = P.first;
      int b = P.second;
      if (!UF.same(a, b)){
        UF.unite(a, b);
      }
    }
    map<int, vector<int>> r;
    for (int x : UF.ch){
      r[UF.root(x)].push_back(x);
    }
    for (auto P : r){
      for (auto x : P.second){
        C[x].set(id);
        cc.push_back(make_pair(id, x));
      }
      C[P.first].set(id);
      cc.push_back(make_pair(id, P.first));
      id++;
      if (id == 10000){
        for (int j = 0; j < q; j++){
          ans[j] += (C[u[j]] & C[v[j]]).count();
        }
        id = 0;
        for (auto Q : cc){
          int id2 = Q.first;
          int w = Q.second;
          C[w].reset(id2);
        }
        cc.clear();
      }
    }
    UF.reset();
  }
  for (int i = 0; i < q; i++){
    ans[i] += (C[u[i]] & C[v[i]]).count();
  }
  for (int i = 0; i < q; i++){
    cout << ans[i] << endl;
  }
}