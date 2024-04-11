#include <cstdio>
#include <cstring>
#include <queue>
#include <memory.h>
#include <iostream>

using namespace std;

#define N 100100
#define SIGMA 26
typedef long long LL;

vector <int> o[N];
int tmp[N], n, Q, B;
int L[N], R[N];
string s[N];
vector <int> V[N];
int vis[N];
LL A[N];
int fen[N];

void add(int x, int v) {
    while(x < N) {
        fen[x] += v; x += x&-x;
    }
}

int calc(int x) {
    int rt = 0;
    while(x) {
        rt += fen[x];
        x -= x&-x;
    }
    return rt;
}

struct Aho_Corasick_Trie {

	struct Node {
		int nxt[SIGMA];
		int link;
	} node[N];

	int tot;
	int ans[N];

	int newnode() {
		node[tot].link = 0;
		memset(node[tot].nxt, 0, sizeof(int) * SIGMA);
		return tot ++;
	}

	void init() {
		tot = 0;
		newnode();
	}

	#define v node[u].nxt[c]
	#define f node[node[u].link].nxt[c]
	#define idx(c) (c - 'a')

	void insert(string &s, int id) {
		int u = 0, len = s.length();
		for (int i = 0; i < len; i ++) {
			int c = idx(s[i]);
			if (!v) v = newnode();
			u = v;
		}
		o[u].push_back(id);
	}

    int Q[N];

	void get_link() {
		//build Aho-Corasick reTRIEval : Advanced Method
		int u = 0;
		int h = 0, t = 0;
		for (int c = 0; c < SIGMA; c ++) if (v) Q[t ++] = v;
		while (h < t) {
			u = Q[h ++];
			for (int c = 0; c < SIGMA; c ++) {
				if (v) {
					Q[t ++] = v;
					node[v].link = f;
					//node[v].cnt += node[f].cnt;
				} else v = f;
			}
		}
		for(int i = 0; i < t; i ++) {
		    u = Q[i];
		    int x = node[u].link;
		    if(x && (int)o[x].size()) ans[u] = x; else ans[u] = ans[x];
		}
	}

    vector <int> U;

	void solve(string &T, int k) {
	    U.clear();
		int len = T.length();
		int u = 0;
		for (int i = 0; i < len; i ++) {
			int c = idx(T[i]);
			u = v;
			int x = u;
			while(x) {
                if(vis[x] == k) tmp[x] ++;
                else {
                    U.push_back(x); tmp[x] = 1;
                    vis[x] = k;
                }
                x = ans[x];
			}
		}
		for(int i = 0; i < U.size(); i ++) {
		    int j = U[i];
		    if((int)o[j].size() > B) {
                for(int l = 0; l < V[k].size(); l ++) {
                    int ii = V[k][l];
                    A[ii] += 1LL * tmp[j] * (lower_bound(o[j].begin(), o[j].end(), R[ii] + 1) - lower_bound(o[j].begin(), o[j].end(), L[ii]));
                }
		    } else {
		        for(int l = 0; l < o[j].size(); l ++) add(o[j][l], tmp[j]);
		    }
		}
		for(int l = 0; l < V[k].size(); l ++) {
            int ii = V[k][l];
            A[ii] += calc(R[ii]) - calc(L[ii] - 1);
		}
		for(int i = 0; i < U.size(); i ++) {
		    int j = U[i];
		    if((int)o[j].size() <= B) {
		        for(int l = 0; l < o[j].size(); l ++) add(o[j][l], -tmp[j]);
		    }
		}
	}

	#undef v
	#undef f
} ACT;

main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);

	//freopen("in.txt", "r", stdin);
	cin >> n >> Q;

	B = 333;

	ACT.init();

	for(int i = 1; i <= n; i ++) {
	    cin >> s[i];
        ACT.insert(s[i], i);
	}

	ACT.get_link();

	for(int i = 0, k; i < Q; i ++) {
	    cin >> L[i] >> R[i] >> k;
        V[k].push_back(i);
	}
	for(int i = 1; i <= n; i ++) if((int)V[i].size()) {
        ACT.solve(s[i], i);
	}
	for(int i = 0; i < Q; i ++) cout << A[i] << endl;
	return 0;
}