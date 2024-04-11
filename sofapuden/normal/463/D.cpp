#include<bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i<b; i++)
#define dep(i,a,b) for(int i = a-1; i>=b; i--)
#define makeUnique(vec) sort(all(vec)); vec.resize(unique(all(vec)) - vec.begin())
#define LOG_vec(vec, sep) for (int fl = 0; fl < vec.size(); fl++) { cout << vec[fl]<< sep; } cout << "\n";
#define LOG_ints(vec, sep) for (int fl = 0; fl < MAXSIZE; fl++) { cout << vec[fl]<< sep; } cout << "\n"
#define all(x) (x).begin(), (x).end()
#define LSB(i) ((i) & -(i))
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
int dp[1005];
vvi gra;

int DFS(int ind) {
	if (dp[ind] != 0) {
		return dp[ind];
	}
	int best = 0;
	rep(i, 0, gra[ind].size()) {
		best=max(DFS(gra[ind][i]),best);
	}
	dp[ind] = best+1;
	return best + 1;
}

int main() {

	int n, k; cin >> n >> k;
	vvi p;
	vector<multiset<int>> vm(n+5);
	gra.resize(n + 5);
	int best = 0;


	
	rep(i, 0, k) {
		vi tmp(n);
		rep(j, 0, n) {
			cin >> tmp[j];
		}
		p.push_back(tmp);
	}
	rep(i, 0, k) {
		set<int> s;
		rep(j, 0, n) {
			s.insert(p[i][j]);
			rep(ij, 1, n+1) {
				if (!s.count(ij)) {
					vm[p[i][j]].insert(ij);
				}
			}
		}
	}
	rep(i, 1, n+1) {
		rep(j, 1, n+1) {
			if (vm[i].count(j) == k) {
				gra[i].push_back(j);
			}
		}
	}
	rep(i, 1, n+1) {
		best = max(best, DFS(i));
	}
	cout << best << endl;
	return 0;
}