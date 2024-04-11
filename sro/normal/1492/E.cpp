#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define loop(i, a) for (int i = 0; i < (a); ++i)
#define cont(i, a) for (int i = 1; i <= (a); ++i)
#define circ(i, a, b) for (int i = (a); i <= (b); ++i)
#define range(i, a, b, c) for (int i = (a); (c) > 0 ? i <= (b) : i >= (b); i += (c))
#define parse(it, x) for (auto &it : (x))
#define pub push_back
#define pob pop_back
#define emb emplace_back
#define mak make_pair
#define mkt make_tuple
typedef long long ll;
typedef long double lf;
const int Inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

int n, m;
vector<vector<int> > a;
int fau[250005], mxfau, p;

bool check(const vector<int> &fin) {
	bool can = 1;
	cont(i, n) {
		int dif = 0;
		cont(j, m) {
			if (a[i][j] != fin[j]) ++dif;
			if (dif > 2) return 0;
		}
	}
	return 1;
}

int main() {
	scanf("%d%d", &n, &m);
	a.assign(n + 1, vector<int>(m + 1, 0));
	cont(i, n) cont(j, m) scanf("%d", &a[i][j]);
	circ(i, 2, n) cont(j, m) fau[i] += (a[i][j] != a[1][j]);
	cont(i, n) if (fau[i] > mxfau) mxfau = fau[i], p = i;
	if (mxfau > 4) return puts("No"), 0;
	if (mxfau <= 2) {
		puts("Yes");
		cont(j, m) printf("%d%c", a[1][j], " \n"[j == m]);
		return 0;
	}
	if (mxfau == 4) {
		vector<int> pos;
		cont(j, m) if (a[1][j] != a[p][j]) pos.pub(j);
		loop(msk, 16) if (__builtin_popcount(msk) == 2) {
			vector<int> fin(m + 1);
			loop(j, 4) {
				if ((msk >> j) & 1) fin[pos[j]] = a[1][pos[j]];
				else fin[pos[j]] = a[p][pos[j]];
			}
			cont(j, m) if (!fin[j]) fin[j] = a[1][j];
			if (check(fin)) {
				puts("Yes");
				cont(j, m) printf("%d%c", fin[j], " \n"[j == m]);
				return 0;
			}
		}
		return puts("No"), 0;
	}
	/*---------------  3  ---------------*/
	vector<int> pos;
	cont(j, m) if (a[1][j] != a[p][j]) pos.pub(j);
	// 
	cont(msk, 6) {
		vector<int> fin(m + 1);
		loop(j, 3) {
			if ((msk >> j) & 1) fin[pos[j]] = a[1][pos[j]];
			else fin[pos[j]] = a[p][pos[j]];
		}
		int np = p;
		if (__builtin_popcount(msk) == 1) np = 1;
		cont(j, m) if (!fin[j]) fin[j] = a[np][j];
		if (check(fin)) {
			puts("Yes");
			cont(j, m) printf("%d%c", fin[j], " \n"[j == m]);
			return 0;
		}
	}
	// 
	loop(w, 3) loop(c, 3) if (c != w) {
		vector<int> fin(m + 1);
		fin[pos[w]] = -1;
		fin[pos[c]] = a[1][pos[c]];
		fin[pos[3 ^ w ^ c]] = a[p][pos[3 ^ w ^ c]];
		cont(j, m) if (!fin[j]) fin[j] = a[1][j];
		memset(fau, 0, sizeof(fau));
		cont(i, n) cont(j, m) fau[i] += (a[i][j] != fin[j]);
		bool fnd = 0;
		cont(i, n) if (fau[i] == 3) { fnd = 1; fin[pos[w]] = a[i][pos[w]]; break;}
		if (!fnd) fin[pos[w]] = 1;
		if (check(fin)) {
			puts("Yes");
			cont(j, m) printf("%d%c", fin[j], " \n"[j == m]);
			return 0;
		}
	}
	return puts("No"), 0;
}
/**
 * 
 *   2 4
 *   4 4 
 *   3 3 
 *   1.  3  1  2 
 *     1  2 
 *     2  2 
 *   2.  3 
 *    
 *     2
 *     
 *  100L
 */