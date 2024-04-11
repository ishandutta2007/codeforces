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
  int n, m;
  cin >> n >> m;
  vector<tuple<int, int, int>> E(m);
  vector<set<int>> E2(n);
  int X = 0;
  for (int i = 0; i < m; i++){
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    E[i] = make_tuple(w, u, v);
    E2[u].insert(v);
    E2[v].insert(u);
    X ^= w;
  }
  set<int> st;
  for (int i = 0; i < n; i++){
    st.insert(i);
  }
  vector<int> id(n, -1);
  int cnt = 0;
  unionfind UF1(n), UF2(n);
  for (int i = 0; i < n; i++){
    if (id[i] == -1){
      id[i] = cnt;
      st.erase(i);
      queue<int> Q;
      Q.push(i);
      while (!Q.empty()){
        int v = Q.front();
        Q.pop();
        vector<int> tmp;
        for (int w : st){
          if (E2[v].count(w) == 0){
            id[w] = cnt;
            UF1.unite(i, w);
            Q.push(w);
            tmp.push_back(w);
          }
        }
        for (int w : tmp){
          st.erase(w);
        }
      }
      cnt++;
    }
  }
  sort(E.begin(), E.end());
  int mn = X;
  long long sum = 0;
  for (int i = 0; i < m; i++){
    int w = get<0>(E[i]);
    int u = get<1>(E[i]);
    int v = get<2>(E[i]);
    if (UF1.same(u, v) && !UF2.same(u, v)){
      mn = min(mn, w);
    }
    if (!UF1.same(u, v)){
      UF1.unite(u, v);
      UF2.unite(u, v);
      sum += w;
    }
  }
  long long m2 = (long long) n * (n - 1) / 2 - m;
  if (n - m2 == cnt){
    sum += mn;
  }
  cout << sum << endl;
}