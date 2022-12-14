#include <bits/stdc++.h>
using namespace std;

#define N 3500000

vector <int> vv;
vector < vector <int> > Ans;

void print(vector <int> &v) {
    int sz = v.size();
    while (v.size() < 32) v.push_back(0);
    int tmp = 0;
    for (int i = 0; i < 8; i ++) {
		tmp = tmp * 2 + v[i];
    }
    printf("%d.", tmp);
    tmp = 0;
    for (int i = 8; i < 16; i ++) {
        tmp = tmp * 2 + v[i];
    }
    printf("%d.", tmp);
    tmp = 0;
    for (int i = 16; i < 24; i ++) {
        tmp = tmp * 2 + v[i];
    }
    printf("%d.", tmp);
    tmp = 0;
    for (int i = 24; i < 32; i ++) {
        tmp = tmp * 2 + v[i];
    }
    printf("%d/", tmp);
    printf("%d\n", sz);
}

struct Tree {
	int tot, rt;
	int nxt[N][2], b[N], w[N];
	void init() {
		tot = -1;
		make_node();
		rt = make_node();
	}
	int make_node() {
		tot ++;
		b[tot] = w[tot] = 0;
		memset(nxt[tot], 0, sizeof nxt[tot]);
		return tot;
	}
	void insert(int val, int g, vector <int> &v) {
		int nd = rt, x;
		for (int i = 0; i < g; i ++) {
            x = v[i];
            if (!nxt[nd][x]) nxt[nd][x] = make_node();
            nd = nxt[nd][x];
		}
        if (val == 0) b[nd] ++;
        else w[nd] ++;
	}
    bool dfs(int k) {
        int bb = b[k], ww = w[k];
        for (int i = 0; i < 2; i ++) {
			if (nxt[k][i]) {
                if (dfs(nxt[k][i])) return 1;
                bb += b[nxt[k][i]];
                ww += w[nxt[k][i]];
			}
        }
        if (b[k] > 0 && ww > 0) return 1;
        if (w[k] > 0 && bb > 0) return 1;
        b[k] = bb, w[k] = ww;
        return 0;
    }
    void dfs_1(int k) {
        if (!b[k]) return;
        if (!w[k]) {
			Ans.push_back(vv);
			return;
        }
        for (int i = 0; i < 2; i ++) {
            vv.push_back(i);
            if (nxt[k][i]) dfs_1(nxt[k][i]);
			vv.pop_back();
        }
        return;
    }
	void solve() {
        if (dfs(rt)) {
            puts("-1");
            return;
        }
        dfs_1(rt);
        printf("%d\n", Ans.size());
        int sz = Ans.size();
        for (int i = 0; i < sz; i ++) {
            print(Ans[i]);
        }
        return;
	}
} A;

char s[100];

int n;

int main() {
    scanf("%d", &n);
    bool flag;
    vector <int> tmp;
    for (int i = 1; i <= n; i ++) {
		flag = 0;
		scanf("%s", s);
        if (s[0] == '+') flag = 1;
		else flag = 0;
        int a = 0, b = 0, c = 0, d = 0, x = 32;
        int now = 0;
        for (now ++ ; s[now] >= '0' && s[now] <= '9'; now ++) a = 10 * a + s[now] - '0';
        for (now ++ ; s[now] >= '0' && s[now] <= '9'; now ++) b = 10 * b + s[now] - '0';
        for (now ++ ; s[now] >= '0' && s[now] <= '9'; now ++) c = 10 * c + s[now] - '0';
        for (now ++ ; s[now] >= '0' && s[now] <= '9'; now ++) d = 10 * d + s[now] - '0';
        if (s[now] == '/') {
			x = 0;
			for (now ++ ; s[now] >= '0' && s[now] <= '9'; now ++) x = 10 * x + s[now] - '0';
        }
        tmp.clear();
        for (int i = 0; i < 8; i ++) {
            tmp.push_back(d & 1);
            d >>= 1;
        }
        for (int i = 0; i < 8; i ++) {
            tmp.push_back(c & 1);
            c >>= 1;
        }
        for (int i = 0; i < 8; i ++) {
            tmp.push_back(b & 1);
            b >>= 1;
        }
        for (int i = 0; i < 8; i ++) {
            tmp.push_back(a & 1);
            a >>= 1;
        }
        reverse(tmp.begin(), tmp.end());
        A.insert(flag, x, tmp);
    }
	A.solve();
	return 0;
}