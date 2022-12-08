#include <bits/stdc++.h>

using namespace std;
#define maxm 16400
bool pre[maxm];
bool cur[maxm];
int par[2*maxm];
int ri[2*maxm];
int ppar[maxm];
int cpar[maxm];
bool tk[2*maxm];

int findset(int u) {
	if (par[u] == u) return u;
	return par[u] = findset(par[u]);
}

void unionSet(int u, int v) {
	u = findset(u);
	v = findset(v);
	if (u == v) return;
	if (ri[u] > ri[v]) {
		par[v] = u;
	}
	else {
		par[u] = v;
		if (ri[u] == ri[v]) ri[v]++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	
	fill(pre, pre+m, false);
	int merge = 0;
	int ones = 0;
	string line;
	int vc;
	vector<int> av;
	for (int i = 0; i < m; i++) par[i] = i;
	for (int i = m; i < 2*m; i++) {
		av.push_back(i);
		par[i] = i;
		ri[i] = 1;
	}
	int c;
	for (int i = 0; i < n; i++) {
		cin >> line;
		for (int j = 0; j < m/4; j++) {
			if (line[j]-'0' >= 0 && line[j]-'0' < 10) {
				vc = line[j]-'0';
			}
			else {
				vc = line[j]-'A'+10;
			}
			if (vc & 8) cur[j*4+0] = true;
			else cur[j*4 + 0] = false;
			if (vc & 4) cur[j*4+1] = true;
			else cur[j*4+1] = false;
			if (vc & 2) cur[j*4+2] = true;
			else cur[j*4+2] = false;
			if (vc & 1) cur[j*4+3] = true;
			else cur[j*4+3] = false;
		}
		for (int j = 0; j < m; j++) {
			// cout << "j   " << j << endl;
			if (!cur[j]) {
				cpar[j] = j;
				continue;
			}
			ones++;
			if (j == 0) {
				if (pre[j]) {
					merge++;
					cpar[j] = ppar[j];
				}
				else {
					cpar[j] = av.back(); av.pop_back();
					par[cpar[j]] = cpar[j];
					ri[cpar[j]] = 1;
				}
			}
			else {
				if (cur[j-1] && pre[j]) {
					merge++;
					if (findset(cpar[j-1]) != findset(ppar[j])) {
						merge++;
						unionSet(cpar[j-1], ppar[j]);
					}
					cpar[j] = findset(cpar[j-1]);

				}
				else if (cur[j-1]) {
					merge++;
					cpar[j] = cpar[j-1];
				}
				else if (pre[j]) {
					merge++;
					cpar[j] = ppar[j];
				}
				else {
					cpar[j] = av.back(); av.pop_back();
					par[cpar[j]] = cpar[j];
					ri[cpar[j]] = 1;
				}
			}
		}
		fill(tk, tk+2*m, false);
		for (int j = 0; j < m; j++) {

			c = findset(cpar[j]);
			cpar[j] = c;
			// cout << "spot  " << j << " - " << c << endl;
			ppar[j] = cpar[j];
			pre[j] = cur[j];
			tk[c] = true;
		}
		av.clear();
		for (int j = m; j < 2*m; j++) {
			if (!tk[j]) {
				// cout << "c  " << j << endl;
				av.push_back(j);
			}
		}
		// cout << "size of av " << av.size() << endl;


	}
	cout << ones - merge << endl;
	cin >> m;
}