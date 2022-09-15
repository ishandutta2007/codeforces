#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <pthread.h>

using namespace std;

#define all(x) begin(x), end(x)

const int maxn = 5e6 + 42;
const int maxs = 1e5 + 42;
vector<int> g[maxs], gt[maxs];
string work[maxs];
char used[maxn];

int d;

#define stack laflal

int stack[2 * maxn];
int head = 0;

void dfs(int v, int mod = 0) {
	used[v] = 1;
	for(auto it: (mod == 0 ? g[v / 50] : gt[v / 50])) {
		int u = it * 50 + (v % 50 + (mod == 0 ? 1 : d - 1)) % d;
		if(!used[u]) {
			dfs(u, mod);
		}
	}
	stack[head++] = v;
	used[v] = 2;
}

int in_comp[maxn];
int comp_cnt[maxn];
int counted[maxs];


void dfs_ans(int v, vector<int> *G) {
	used[v] = 1;
	int mx = 0;
	for(auto u: G[v]) {
		if(!used[u]) {
			dfs_ans(u, G);
		}
		mx = max(mx, comp_cnt[u]);
	}
	comp_cnt[v] += mx;
	used[v] = 2;
}

int u[maxs], v[maxs];
void* main2(void *arg) {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m >> d;
	//const int GG = 1e5;
	//n = GG, m = GG, d = 50;
	for(int i = 0; i < m; i++) {
		cin >> u[i] >> v[i];
		u[i]--, v[i]--;
		g[u[i]].push_back(v[i]);
		gt[v[i]].push_back(u[i]);
	}
	for(int i = 0; i < n; i++) {
		cin >> work[i];
	}
	dfs(0);
	int tops = head;
	reverse(stack, stack + tops);
	fill(used, used + maxn, 1);
	for(int i = 0; i < tops; i++) {
		int it = stack[i];
		used[it] = 0;
	}
	for(int i = 0; i < tops; i++) {
		int it = stack[i];
		if(!used[it]) {
			int cur = head;
			dfs(it, 1);
			int ncur = head;
			head = tops;
			for(int j = cur; j < ncur; j++) {
				int jt = stack[j];
				in_comp[jt] = it;
				if(work[jt / 50][jt % 50] == '1') {
					if(!counted[jt / 50]) {
						counted[jt / 50] = 1;
						comp_cnt[it]++;
					}
				}
			}
			//cout << "! " << it << ' ' << comp_cnt[it] << endl;
			for(int j = cur; j < ncur; j++) {
				int jt = stack[j];
				counted[jt / 50] = 0;
			}
		}
	}
	
	vector<int> G[n * 50];
	for(int i = 0; i < tops; i++) {
		int v = stack[i];
		for(auto it: g[v / 50]) {
			int u = it * 50 + (v % 50 + 1) % d;
			if(in_comp[v] != in_comp[u]) {
				G[in_comp[v]].push_back(in_comp[u]);
			}
		}
	}
	fill(used, used + maxn, 1);
	for(int i = 0; i < tops; i++) {
		int it = stack[i];
		used[it] = 0;
	}
	dfs_ans(in_comp[0], G);
	cout << comp_cnt[in_comp[0]] << endl;
	//cout << clock() / double(CLOCKS_PER_SEC) << endl;
}

#include <Processthreadsapi.h>
#include <iostream>
#include <Synchapi.h>
#include <windows.h>
#include <process.h>

DWORD WINAPI MyThreadFunction( LPVOID lpParam ) {
main2(nullptr);
return 0;
}
int main() {
auto h =CreateThread(nullptr, 1024 << 20, MyThreadFunction, nullptr, STACK_SIZE_PARAM_IS_A_RESERVATION, nullptr);
WaitForSingleObject(h, INFINITE);
}