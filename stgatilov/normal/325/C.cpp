//#pragma comment(linker, "/STACK:20000000")
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#ifdef HOME
	#define E(c) cerr<<#c
	#define Eo(x) cerr<<#x<<" = "<<(x)<<endl
	#define Ef(...) fprintf(stderr, __VA_ARGS__)
#else
	#define E(c) ((void)0)
	#define Eo(x) ((void)0)
	#define Ef(...) ((void)0)
#endif

const int SIZE = 100<<10;
const int MAXVAL = 314000000;
const int INF = 1000000000;

struct Rule {
	int src;
	vector<int> res;
};

int n, m;
vector<Rule> rules;

vector<int> prods[SIZE];
vector<int> presIn[SIZE];
bool aliveVar[SIZE], aliveRule[SIZE];
int rcnt[SIZE];

struct CmpCnt {
	bool operator() (int a, int b) const {
		if (rcnt[a] != rcnt[b])
			return rcnt[a] < rcnt[b];
		return a < b;
	}
};
set<int, CmpCnt> remQueue;

vector<int> varGoes[SIZE], varAnti[SIZE];
bool varInf[SIZE];


int varRes[SIZE][2], ruleRes[SIZE][2];
struct CmpMinRes {
	bool operator() (int a, int b) const {
		int ar = varRes[a][0];
		int br = varRes[b][0];
		if (ar != br) return ar < br;
		return a < b;
	}
};
set<int, CmpMinRes> varHeap;

bool used[SIZE];
vector<int> backorder;

void DFS1(int u) {
	used[u] = true;
	for (int i = 0; i<varGoes[u].size(); i++) {
		int v = varGoes[u][i];
		if (!used[v]) DFS1(v);
	}
	backorder.push_back(u);
}

vector<int> comp;
void DFS2(int u) {
	used[u] = true;
	for (int i = 0; i<varAnti[u].size(); i++) {
		int v = varAnti[u][i];
		if (!used[v]) DFS2(v);
	}
	comp.push_back(u);
}

void Combine(int& res, int a, bool checkInf = true) {
	if (checkInf && (res > MAXVAL || a > MAXVAL))
		res = INF;
	else
		res = min(res + a, MAXVAL);
}

void Combine2(int *res, int *a) {
	Combine(res[0], a[0], false);
	Combine(res[1], a[1], true);
}


int nrm(int x) { return (x<0 ? -1 : x-1); }

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &m, &n);
	for (int i = 0; i<m; i++) {
		Rule r;
		scanf("%d", &r.src);
		r.src = nrm(r.src);
		int tk;
		scanf("%d", &tk);
		for (int j = 0; j<tk; j++) {
			int q;
			scanf("%d", &q);
			r.res.push_back(nrm(q));
		}
		rules.push_back(r);
	}

	for (int i = 0; i<m; i++) {
		prods[rules[i].src].push_back(i);
		for (int j = 0; j<rules[i].res.size(); j++) {
			int v = rules[i].res[j];
			if (v < 0) continue;
			presIn[v].push_back(i);
		}
	}

	for (int i = 0; i<m; i++) {
		for (int j = 0; j<rules[i].res.size(); j++)
			rcnt[i] += (rules[i].res[j] >= 0);
		remQueue.insert(i);
	}

	while (!remQueue.empty()) {
		int q = *remQueue.begin();
		if (rcnt[q] > 0) break;
		remQueue.erase(remQueue.begin());

		int v = rules[q].src;
		aliveRule[q] = true;
		if (aliveVar[v]) continue;
		aliveVar[v] = true;

		for (int i = 0; i<presIn[v].size(); i++) {
			int w = presIn[v][i];
			remQueue.erase(w);
			rcnt[w]--;
			remQueue.insert(w);
		}
	}

	for (int i = 0; i<n; i++) if (aliveVar[i]) Ef("%d var is alive\n", i);
	for (int i = 0; i<m; i++) if (aliveRule[i]) Ef("%d rule is alive\n", i);

	for (int i = 0; i<m; i++) if (aliveRule[i]) {
		int fv = rules[i].src;
		for (int j = 0; j<rules[i].res.size(); j++) {
			int v = rules[i].res[j];
			if (v < 0) continue;
			varGoes[fv].push_back(v);
			varAnti[v].push_back(fv);
		}
	}

	memset(used, 0, sizeof(used));
	for (int i = 0; i<n; i++) if (aliveVar[i])
		if (!used[i])
			DFS1(i);
	memset(used, 0, sizeof(used));
	for (int i = backorder.size() - 1; i >= 0; i--) {
		int q = backorder[i];
		if (!used[q]) {
			comp.clear();
			DFS2(q);

			bool isinf = false;
			if (comp.size() > 1) isinf = true;
			else isinf = (find(varGoes[q].begin(), varGoes[q].end(), q) != varGoes[q].end());

			//for (int s = 0; s<comp.size(); s++) Ef("%d ", comp[s]); Ef("\n");

			if (isinf)
				for (int j = 0; j<comp.size(); j++)
					varInf[comp[j]] = true;
		}
	}

	for (int i = 0; i<n; i++) if (varInf[i]) Ef("%d var is inside loop\n", i);
	
	
	for (int i = 0; i<n; i++) {
		varRes[i][0] = INF;
		varRes[i][1] = -INF;
		if (aliveVar[i]) {
			varHeap.insert(i);
			if (varInf[i]) varRes[i][1] = INF;
		}
	}
	varRes[n][0] = varRes[n][1] = 1;

	remQueue.clear();
	for (int i = 0; i<m; i++) {
		rcnt[i] = 0;
		for (int j = 0; j<rules[i].res.size(); j++)
			rcnt[i] += (rules[i].res[j] >= 0);
		remQueue.insert(i);
	}

	while (1) {
		while (!remQueue.empty()) {
			int q = *remQueue.begin();
			if (rcnt[q] > 0) break;
			remQueue.erase(remQueue.begin());

			int from = rules[q].src;
			ruleRes[q][0] = ruleRes[q][1] = 0;
			for (int i = 0; i<rules[q].res.size(); i++) {
				int to = rules[q].res[i];
				if (to < 0) to = n;
				Combine2(ruleRes[q], varRes[to]);
			}
			Ef("Rule %d done with result = (%d; %d)\n", q, ruleRes[q][0], ruleRes[q][1]);

			if (varHeap.find(from) != varHeap.end()) {
				varHeap.erase(from);
				varRes[from][0] = min(varRes[from][0], ruleRes[q][0]);
				varRes[from][1] = max(varRes[from][1], ruleRes[q][1]);
				varHeap.insert(from);
			}
		}

		if (varHeap.empty()) break;
		int v = *varHeap.begin();
		varHeap.erase(v);
		Ef("Var %d done with result = (%d;%d)\n", v, varRes[v][0], varRes[v][1]);
		
		for (int i = 0; i<presIn[v].size(); i++) {
			int w = presIn[v][i];
			remQueue.erase(w);
			rcnt[w]--;
			remQueue.insert(w);
		}
	}

	for (int i = 0; i<backorder.size(); i++) {
		int v = backorder[i];
		varRes[v][1] = 0;

		if (varInf[v])
			varRes[v][1] = INF;
		else {
			for (int j = 0; j<prods[v].size(); j++) {
				int r = prods[v][j];
				if (!aliveRule[r]) continue;
				int tres = 0;
				for (int s = 0; s<rules[r].res.size(); s++) {
					int tv = rules[r].res[s];
					if (tv < 0) tv = n;
					Combine(tres, varRes[tv][1]);
				}
				if (varRes[v][1] < tres)
					varRes[v][1] = tres;
			}
		}
	}

	for (int i = 0; i<n; i++) {
		for (int j = 0; j<2; j++) {
			int a = varRes[i][j] > MAXVAL ? -2 : varRes[i][j];
			if (!aliveVar[i]) a = -1;
			printf("%d ", a);
		}
		printf("\n");
	}


	return 0;
}