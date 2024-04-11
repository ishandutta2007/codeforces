#include <bits/stdc++.h>

using namespace std;

int mod = 998244353;

int pow_mod(int a, int k) {
	if(k == 0) {
		return 1;
	}
	int sub = pow_mod(a, k/2);
	if(k%2 == 0) {
		return ((long long)sub*sub)%mod;
	} else {
		return (((long long)sub*sub)%mod*a)%mod;
	}
}

int inv_mod(int a) {
	return pow_mod(a, mod-2);
}

int comb_mod(int n, int r) {
	int i;
	int answer = 1;
	if(2*r > n) {
		return comb_mod(n, n-r);
	}
	for(i=n-r+1; i<=n; i++) {
		answer = ((long long)answer*i)%mod;
	}
	for(i=1; i<=r; i++) {
		answer = ((long long)answer*inv_mod(i))%mod;
	}
	return answer;
}

class Mod {
	public:
		long long val;
		
		Mod() {
			this->val = 0;
		}
		
		Mod(int val) {
			this->val = val;
		}
		
		Mod(int num, int den) {
			this->val = ((long long)num*inv_mod(den))%mod;
		}
		
		Mod operator+(Mod a) {
			return Mod((val+a.val)%mod);
		}
		
		Mod operator+=(Mod a) {
			val = (val+a.val)%mod;
		}
		
		Mod operator-(Mod a) {
			return Mod((mod+val-a.val)%mod);
		}
		
		Mod operator-=(Mod a) {
			val = (mod+val-a.val)%mod;
		}
		
		Mod operator*(Mod a) {
			return Mod((val*a.val)%mod);
		}
		
		Mod operator*=(Mod a) {
			val = (val*a.val)%mod;
		}
		
		Mod operator/(Mod a) {
			return Mod((val*inv_mod(a.val))%mod);
		}
		
		Mod operator/=(Mod a) {
			val = (val*inv_mod(a.val))%mod;
		}
};

class Graph {
	public:
		int n;
		std::vector<set<int> > a;

		Graph(int nodes) {
		    int i;
            n = nodes;
            for(i=0; i<n; i++) {
                set<int> e;
                a.push_back(e);
            }
		}
		
		void add(int i, int j) {
			a[i].insert(j);
		}

		void del(int i, int j) {
			a[i].erase(j);
		}

		void add_both(int i, int j) {
			add(i, j);
			add(j, i);
		}

		void del_both(int i, int j) {
			del(i, j);
			del(j, i);
		}
		
		vector<int> path(int u, int v) {
			int i;
			int pred[n] = {};
			int visited[n] = {};
			queue<int> to;
			to.push(u);
			visited[u] = 1;
			while(!to.empty()) {
				int node = to.front();
				to.pop();
				for(int con:a[node]) {
					if(!visited[con]) {
						pred[con] = node;
						if(con == v) {
							vector<int> rev;
							while(v != u) {
								rev.push_back(v);
								v = pred[v];
							}
							rev.push_back(u);
							vector<int> answer;
							for(i=rev.size()-1; i>=0; i--) {
								answer.push_back(rev[i]);
							}
							return answer;
						}
						visited[con] = 1;
						to.push(con);
					}
				}
			}
			return vector<int>{};
		}
		
		vector<vector<int> > components() {
			int i;
			int visited[n] = {};
			queue<int> to;
			vector<vector<int> > answer;
			for(i=0; i<n; i++) {
				if(!visited[i]) {
					vector<int> e;
					visited[i] = 1;
					to.push(i);
					e.push_back(i);
					while(!to.empty()) {
						int node = to.front();
						to.pop();
						for(int con:a[node]) {
							if(!visited[con]) {
								visited[con] = 1;
								to.push(con);
								e.push_back(con);
							}
						}
					}
					answer.push_back(e);
				}
			}
			return answer;
		}
		
		void print() {
			int i, j;
			for(i=0; i<a.size(); i++) {
				printf("%d: ", i);
				for(int con:a[i]) {
					printf("%d ", con);
				}
				printf("\n");
			}
		}
};

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int u, v;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d %d", &n, &m);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		Graph g(n);
		Graph rev(n);
		for(i=0; i<m; i++) {
			scanf("%d %d", &u, &v);
			u--, v--;
			g.add(u, v);
			rev.add(v, u);
		}
		int end;
		for(i=0; i<n; i++) {
			if(g.a[i].empty()) {
				end = i;
			}
		}
		int depth[n] = {};
		queue<int> to;
		to.push(end);
		while(!to.empty()) {
			int node = to.front();
			to.pop();
			for(int con:rev.a[node]) {
				if(depth[node]+1 > depth[con]) {
					depth[con] = depth[node]+1;
					to.push(con);
				}
			}
		}
		int maxd = 0;
		for(i=0; i<n; i++) {
			maxd = max(maxd, depth[i]);
		}
		int b[n];
		for(i=0; i<maxd; i++) {
			int check = 0;
			for(j=0; j<n; j++) {
				b[j] = a[j];
			}
			for(j=0; j<n; j++) {
				if(a[j] > 0) {
					check = 1;
					b[j]--;
					for(int con:g.a[j]) {
						b[con]++;
					}
				}
			}
			for(j=0; j<n; j++) {
				a[j] = b[j];
			}
			if(!check) {
				break;
			}
		}
		if(i != maxd) {
			printf("%d\n", i);
		} else {
			Mod mul[n];
			int count[n] = {};
			mul[end].val = 1;
			queue<int> to;
			to.push(end);
			while(!to.empty()) {
				int node = to.front();
				to.pop();
				for(int con:rev.a[node]) {
					mul[con] += mul[node];
					count[con]++;
					if(count[con] == g.a[con].size()) {
						to.push(con);
					}
				}
			}
			Mod answer;
			for(i=0; i<n; i++) {
				answer += mul[i]*Mod(a[i]);
			}
			answer += maxd;
			printf("%lld\n", answer.val);
		}
	}
}