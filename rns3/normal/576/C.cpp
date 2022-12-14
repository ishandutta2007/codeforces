#include <bits/stdc++.h>
using namespace std;
typedef pair <int, int> PII;
#define M 1000010
#define L 1001
#define X first
#define Y second

vector <int> v[M];

PII p[M];
vector <PII> tmp[M];

int n, use[M], flag[M], T;

int main() {
//	freopen("C.in", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {scanf("%d %d", &p[i].X, &p[i].Y); v[p[i].Y/L].push_back(i);}
    int S = 1000000 / L;
    int last = 0;
    for (int i = 0; i <= S; i++) {
		int dir = 0;
		int cnt = 0;
		++T;
		for (int k = 0; k < v[i].size(); k++) {
			int I = v[i][k];
			int x = p[I].X, y = p[I].Y%L;
			tmp[x].push_back(PII(y, I));
			if (flag[x] != T) use[cnt++] = x, flag[x] = T;
		}
		if (!cnt) continue; sort(use, use + cnt);
    	if (abs(use[0] - last) < abs(use[cnt-1] - last)) {
			for (int k = 0; k < cnt; k++) {
				int I = use[k];
				sort(tmp[I].begin(), tmp[I].end());
				if (dir) reverse(tmp[I].begin(), tmp[I].end());
				for (int J = 0; J < tmp[I].size(); J++) printf("%d ", tmp[I][J].Y);
				dir ^= 1;
			}
		}
    	else {
			reverse(use, use + cnt);
			for (int k = 0; k < cnt; k++) {
				int I = use[k];
				sort(tmp[I].begin(), tmp[I].end());
				if (dir) reverse(tmp[I].begin(), tmp[I].end());
				for (int J = 0; J < tmp[I].size(); J++) printf("%d ", tmp[I][J].Y);
				dir ^= 1;
			}
    	}
    	last = use[cnt-1];
    	for (int j = 0; j < cnt; j++) tmp[use[j]].clear();
    }
}