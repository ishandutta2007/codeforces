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
int a[100005], b[100005];
int f[100005], fs, pos[100005];

int main() {
	scanf("%d", &n);
	cont(i, n) scanf("%d", a + i);
	scanf("%d", &m);
	cont(i, m) scanf("%d", b + i);
	sort(b + 1, b + m + 1);
	multiset<int> ms;
	cont(i, m) ms.insert(b[i]);
	cont(i, n) {
		if (~a[i]) {
			if (a[i] > f[fs]) f[pos[i] = ++fs] = a[i];
			else {
				pos[i] = lower_bound(f + 1, f + fs + 1, a[i]) - f;
				f[pos[i]] = a[i];
			}
		}
		else {
			int pt = fs;
			range(j, m, 1, -1) {
				while (pt && f[pt] >= b[j]) --pt;
				if (pt == fs) f[++fs] = b[j];
				else f[pt + 1] = b[j];
			}
		}
	}
	int ln = 0, cur = Inf;
	range(i, n, 1, -1) {
		if (!~a[i]) {
			bool can = 1;
			range(j, i - 1, 1, -1) {
				if (~a[j] && a[j] < cur && pos[j] + ln == fs) {
					can = 0;
					break;
				}
			}
			if (can) {
				auto it = ms.lower_bound(cur);
				if (it != ms.begin()) {
					++ln; --it;
					a[i] = cur = *it;
					ms.erase(it);
				}
			}
		}
		else if (a[i] < cur && pos[i] + ln == fs) {
			++ln; cur = a[i];
		}
	}
	cont(i, n) if (!~a[i]) {
		a[i] = *ms.begin();
		ms.erase(ms.begin());
	}
	cont(i, n) printf("%d%c", a[i], " \n"[i == n]);
	return 0;
}