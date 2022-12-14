#include <bits/stdc++.h>
using namespace std;

#define N 110
#define M 1000010

int f[N][N][N], ss, tt, vv;
char s[N], t[N], v[N];
int kmp[N][400];

vector <int> id[N];

void prep() {
	for (int i = 0; i < vv; i ++) for (char c = 'A'; c <= 'Z'; c ++) {
        int rlt = i + 2;
        bool tag = 1;
        while (tag && rlt) {
			rlt --;
			if (c != v[rlt]) continue;
			tag = 0;
            for (int j = 1; j < rlt; j ++) if (v[j] != v[j-rlt+i+1]) {
				tag = 1;
				break;
            }
        }
        kmp[i][c] = rlt;
	}
}

int e;

struct Node {
	int p, q, cnt, prv;
}node[M];

int new_node(int pp = 0, int qq = 0, int cntt = 0, int prvv = 0) {
	e ++;
	node[e].p = pp, node[e].q = qq, node[e].cnt = cntt, node[e].prv = prvv;
    return e;
}

int main() {
	gets(s + 1);
	gets(t + 1);
	gets(v + 1);
    ss = strlen(s + 1);
    tt = strlen(t + 1);
    vv = strlen(v + 1);
    prep();
    node[0] = Node{0, 0, 0, 0};
    id[0].push_back(0);
    for (int i = 1; i <= ss; i ++) for (int j = 1; j <= tt; j ++) if (s[i] == t[j]) {
		int rlt, now;
		for (int k = 0; k < vv; k ++) {
            int aaa = kmp[k][s[i]];
            if (aaa == vv) continue;
            rlt = 0;
            for (int h = 0, sz = id[k].size(); h < sz; h ++) {
				if (node[id[k][h]].p < i && node[id[k][h]].q < j && node[id[k][h]].cnt + 1 > rlt) {
					rlt = node[id[k][h]].cnt + 1;
					now = id[k][h];
				}
            }
            if (rlt) id[aaa].push_back(new_node(i, j, rlt, now));
		}
    }
    int rlt = 0, now;
    for (int i = 1; i <= e; i ++) {
		if (node[i].cnt > rlt) {
			rlt = node[i].cnt;
            now = i;
		}
    }
    char ans[N];
    if (!rlt) puts("0");
    else {
		int cnt = 0;
		while (now) {
			ans[cnt++] = s[node[now].p];
			now = node[now].prv;
		}
		for (int i = cnt - 1; i >= 0; i --) printf("%c", ans[i]);
    }
	return 0;
}