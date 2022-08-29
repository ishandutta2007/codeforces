#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000;
int ford_fulkerson(vector<unordered_map<int, int>> &E, int s, int t){
	int V = E.size();
	int F = 0;
	while (1){
		vector<int> d(V, INF);
		vector<int> m(V, INF);
		vector<int> prev(V, -1);
		d[s] = 0;
		queue<int> Q;
		Q.push(s);
		while (!Q.empty()){
			int v = Q.front();
			Q.pop();
			for (auto P : E[v]){
				int w = P.first;
				if (d[w] == INF){
					prev[w] = v;
					d[w] = d[v] + 1;
					m[w] = min(m[v], P.second);
					Q.push(w);
				}
			}
		}
		if (d[t] == INF){
			break;
		}
		int f = m[t];
		int c = t;
		while (c != s){
			if (E[prev[c]][c] == f){
				E[prev[c]].erase(c);
			} else {
				E[prev[c]][c] -= f;
			}
			E[c][prev[c]] += f;
			c = prev[c];
		}
		F += f;
	}
	return F;
}
int main(){
  int n;
  cin >> n;
  int a1, a2, a3;
  cin >> a1 >> a2 >> a3;
  int b1, b2, b3;
  cin >> b1 >> b2 >> b3;
  vector<unordered_map<int, int>> E1(8);
  E1[0][1] = a1;
  E1[0][2] = a2;
  E1[0][3] = a3;
  E1[1][6] = INF;
  E1[1][4] = INF;
  E1[2][4] = INF;
  E1[2][5] = INF;
  E1[3][5] = INF;
  E1[3][6] = INF;
  E1[4][7] = b1;
  E1[5][7] = b2;
  E1[6][7] = b3;
  int ans1 = n - ford_fulkerson(E1, 0, 7);
  vector<unordered_map<int, int>> E2(8);
  E2[0][1] = a1;
  E2[0][2] = a2;
  E2[0][3] = a3;
  E2[1][5] = INF;
  E2[2][6] = INF;
  E2[3][4] = INF;
  E2[4][7] = b1;
  E2[5][7] = b2;
  E2[6][7] = b3;
  int ans2 = ford_fulkerson(E2, 0, 7);
  cout << ans1 << ' ' << ans2 << endl;
}