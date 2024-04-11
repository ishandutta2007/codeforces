#include <bits/stdc++.h>
using namespace std;
struct unionfind{
	vector<int> p;
	unionfind(int N){
		p = vector<int>(N, -1);
	}
	int root(int x){
		if (p[x] < 0){
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
			if (p[x] < p[y]){
				swap(x, y);
			}
			p[y] += p[x];
			p[x] = y;
		}
	}
};
int main(){
  mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
  int n, m1, m2;
  cin >> n >> m1 >> m2;
  unionfind UF1(n);
  for (int i = 0; i < m1; i++){
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    UF1.unite(u, v);
  }
  unionfind UF2(n);
  for (int i = 0; i < m2; i++){
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    UF2.unite(u, v);
  }
  int cnt1 = 0;
  for (int i = 0; i < n; i++){
    if (UF1.root(i) == i){
      cnt1++;
    }
  }
  int cnt2 = 0;
  for (int i = 0; i < n; i++){
    if (UF2.root(i) == i){
      cnt2++;
    }
  }
  int h = min(cnt1 - 1, cnt2 - 1);
  cout << h << endl;
  if (cnt1 > cnt2){
    swap(UF1, UF2);
  }
  vector<vector<int>> id(n);
  vector<int> id2;
  for (int i = 0; i < n; i++){
    id[UF1.root(i)].push_back(i);
    if (UF1.root(i) == i){
      id2.push_back(i);
    }
  }
  vector<bool> used(n, false);
  int cnt = 0;
  int A = id2.size(), B = 0;
  while (cnt < h){
    int r;
    while (true){
      r = id2[mt() % A];
      if (!used[r]){
        break;
      }
    }
    int u = id[r][mt() % id[r].size()];
    int s;
    while (true){
      s = id2[mt() % A];
      if (s != r && !used[s]){
        break;
      }
    }
    int v = id[s][mt() % id[s].size()];
    if (!UF1.same(u, v) && !UF2.same(u, v)){
      cnt++;
      cout << u + 1 << ' ' << v + 1 << endl;
      int u2 = UF1.root(u);
      int v2 = UF1.root(v);
      UF1.unite(u, v);
      UF2.unite(u, v);
      u = u2;
      v = v2;
      if (id[u].size() > id[v].size()){
        swap(id[u], id[v]);
      }
      for (int w : id[u]){
        id[v].push_back(w);
      }
      id[u].clear();
      if (UF1.root(u) == u){
        swap(id[u], id[v]);
      }
      int p = u ^ v ^ UF1.root(u);
      used[p] = true;
      B++;
      if (B * 2 >= A){
        vector<int> id3;
        for (int i = 0; i < id2.size(); i++){
          if (!used[id2[i]]){
            id3.push_back(id2[i]);
          }
        }
        swap(id2, id3);
        A = id2.size();
        B = 0;
      }
    }
  }
}