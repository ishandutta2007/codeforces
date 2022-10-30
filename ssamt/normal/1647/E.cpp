#include <bits/stdc++.h>

using namespace std;

class Direct {
	public:
		int n;
		vector<vector<int>> point;
		
		Direct(vector<int>& p) {
			int i, j;
			int n = p.size();
			for(i=0; i<n; i++) {
				point.push_back({p[i]});
			}
			for(i=1; i<32; i++) {
				for(j=0; j<n; j++) {
					point[j].push_back(point[point[j][i-1]][i-1]);
				}
			}
		}
		
		int follow(int start, int rp) {
			int i, j;
			for(i=0; i<32; i++) {
				if(rp&(1<<i)) {
					start = point[start][i];
				}
			}
			return start;
		}
};

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int u, v;
	int in;
	scanf("%d", &n);
	vector<int> p, a;
	for(i=0; i<n; i++) {
		scanf("%d", &in);
		p.push_back(in);
		p[i]--;
	}
	for(i=0; i<n; i++) {
		scanf("%d", &in);
		a.push_back(in);
		a[i]--;
	}
	int rev[n] = {};
	for(i=0; i<n; i++) {
		rev[p[i]] = 1;
	}
	int em = 0;
	for(i=0; i<n; i++) {
		if(!rev[i]) {
			em++;
		}
	}
	int maxa = *max_element(a.begin(), a.end());
	int time = (maxa-(n-1))/em;
	Direct d(p);
	vector<vector<int>> agg(n, vector<int>{});
	for(i=0; i<n; i++) {
		int fin = d.follow(i, time);
		agg[fin].push_back(i);
	}
	vector<vector<int>> s;
	for(i=0; i<n; i++) {
		if(!agg[i].empty()) {
			s.push_back({a[i], i});
		}
	}
	sort(s.begin(), s.end());
	vector<int> answer(n, 0);
	priority_queue<int, vector<int>, greater<int>> pq;
	int idx = 0;
	for(i=0; i<n; i++) {
		if(idx < s.size() && s[idx][0] == i) {
			int pass = s[idx][1];
			answer[agg[pass][0]] = i;
			for(j=1; j<agg[pass].size(); j++) {
				pq.push(agg[pass][j]);
			}
			idx++;
		} else {
			answer[pq.top()] = i;
			pq.pop();
		}
	}
	for(i=0; i<n; i++) {
		printf("%d ", answer[i]+1);
	}
}