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

int n;
int a[200005];
int xf[200005], pos[200005];
pair<int, int> lst[5000005];

int main() {
	scanf("%d", &n);
	cont(i, n) scanf("%d", a + i);
	vector<pair<int, int> > is;
	cont(i, n) is.pub(mak(a[i], i));
	sort(all(is));
	if (n >= 3300) {
		cont(i, SZ(is) - 1) {
			xf[i] = is[i].first - is[i - 1].first;
			if (pos[xf[i]] && pos[xf[i]] != i - 1) {
				int pp = pos[xf[i]];
				puts("YES");
				printf("%d %d %d %d\n", is[pp - 1].second, is[i].second, is[pp].second, is[i - 1].second);
				return 0;
			}
			if (!pos[xf[i]]) pos[xf[i]] = i;
		}
		return puts("NO"), 0;
	}
	loop(i, n) {
		circ(j, i + 1, n - 1) {
			int x = is[j].first - is[i].first;
			if (lst[x].first) {
				puts("YES");
				printf("%d %d %d %d\n", lst[x].second, is[i].second, lst[x].first, is[j].second);
				return 0;
			}
		}
		loop(j, i) {
			int x = is[i].first - is[j].first;
			lst[x] = mak(is[j].second, is[i].second);
		}
	}
	puts("NO");
	return 0;
}