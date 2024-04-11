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
  for (int i = 0; i < m; i++){
    int v, u, w;
    cin >> v >> u >> w;
    v--;
    u--;
    E[i] = make_tuple(w, v, u);
  }
  sort(E.begin(), E.end());
  vector<int> T;
  T.push_back(-1);
  for (int i = 0; i < m; i++){
    T.push_back(get<0>(E[i]));
  }
  for (int i = 0; i < m; i++){
    for (int j = i + 1; j < m; j++){
      T.push_back((get<0>(E[i]) + get<0>(E[j]) + 1) / 2);
    }
  }
  sort(T.begin(), T.end());
  T.erase(unique(T.begin(), T.end()), T.end());
  int cnt = T.size();
  vector<long long> A(cnt, 0), B(cnt, 0);
  for (int i = 0; i < cnt; i++){
    vector<tuple<int, int, int, int, int>> E2(m);
    for (int j = 0; j < m; j++){
      int c = get<0>(E[j]);
      int u = get<1>(E[j]);
      int v = get<2>(E[j]);
      if (c <= T[i]){
        E2[j] = make_tuple(abs(T[i] - c), 1, -c, u, v);
      } else {
        E2[j] = make_tuple(abs(T[i] - c), -1, c, u, v);
      }
    }
    sort(E2.begin(), E2.end());
    unionfind UF(n);
    for (int j = 0; j < m; j++){
      int u = get<3>(E2[j]);
      int v = get<4>(E2[j]);
      if (!UF.same(u, v)){
        UF.unite(u, v);
        A[i] += get<1>(E2[j]);
        B[i] += get<2>(E2[j]);
      }
    }
  }
  int p, k, a, b, c;
  cin >> p >> k >> a >> b >> c;
  vector<int> q(k);
  for (int i = 0; i < p; i++){
    cin >> q[i];
  }
  for (int i = p; i < k; i++){
    q[i] = ((long long) q[i - 1] * a + b) % c;
  }
  long long ans = 0;
  for (int i = 0; i < k; i++){
    int po = upper_bound(T.begin(), T.end(), q[i]) - T.begin() - 1;
    ans ^= A[po] * q[i] + B[po];
  }
  cout << ans << endl;
}