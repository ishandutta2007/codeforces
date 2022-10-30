#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int u, v;
	int in;
	cin >> n;
	vector<vector<int>> p(2*n, vector<int>{});
	for(i=0; i<2*n; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		p[x].push_back(y);
		p[y].push_back(x);
	}
	vector<vector<int>> loop;
	vector<int> vis(2*n, 0);
	for(i=0; i<2*n; i++) {
		if(!vis[i]) {
			loop.push_back({});
			j = i;
			while(1) {
				loop.back().push_back(j);
				vis[j] = 1;
				if(!vis[p[j][0]]) {
					j = p[j][0];
				} else if(!vis[p[j][1]]) {
					j = p[j][1];
				} else {
					break;
				}
			}
		}
	}
	long long answer = 0;
	for(auto lp:loop) {
		int s = lp.size();
		if(lp[0] >= n) {
			lp.push_back(lp[0]);
			lp.erase(lp.begin());
		}
		vector<vector<long long>> d;
		for(i=0; i<s; i++) {
			d.push_back({});
			vector<int> sm(2, 0);
			vector<int> lr(2, 0);
			sm[i%2] = lp[i], lr[i%2] = lp[i];
			sm[(i+1)%2] = lp[(i+1)%s], lr[(i+1)%2] = lp[(i+1)%s];
			for(j=0; j<s; j++) {
				sm[(i+j)%2] = min(sm[(i+j)%2], lp[(i+j)%s]);
				lr[(i+j)%2] = max(lr[(i+j)%2], lp[(i+j)%s]);
				d[i].push_back((long long)(n-lr[0])*(sm[0]+1)*(2*n-lr[1])*(sm[1]-n+1));
				//cout << sm[0] << " " << lr[0] << " " << sm[1] << " " << lr[1] << " " << endl;
			}
		}
		/*for(i=0; i<s; i++) {
			for(j=0; j<s; j++) {
				cout << d[i][j] << " ";
			}
			cout << endl;
		}*/
		for(i=0; i<s; i++) {
			for(j=0; j<s-2; j++) {
				answer += ((j+1)/2)*(d[i][j]-d[i][j+1]-d[(s+i-1)%s][j+1]+d[(s+i-1)%s][j+2]);
				//cout << answer << endl;
			}
			answer += ((s-1)/2)*(d[i][s-2]-d[i][s-1]);
		}
		answer += (s/2)*(d[0][s-1]);
	}
	cout << answer;
}