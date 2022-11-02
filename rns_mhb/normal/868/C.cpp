#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pc putchar
#define gc getchar
#define pb push_back
#define ppb pop_back
#define x first
#define y second
#define f0(i, a, b) for (int i = a; i < b; i ++)
#define f1(i, a, b) for (int i = a; i <= b; i ++)
#define f2(i, a, b) for (int i = a; i > b; i --)
#define f3(i, a, b) for (int i = a; i >= b; i --)
template <class T> void chkmax(T &a, T b) {if (a < b) a = b;}
template <class T> void chkmin(T &a, T b) {if (a > b) a = b;}

typedef pair <int, int> pii;
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;
typedef pair <ll, ll> pll;
typedef vector <int> vi;

const int inf = 0x3f3f3f3f;
const ll linf = 2e18 + 100;
const double eps = 1e-7;

#define N 100005

int n, k;
vector <int> v[N];
bool d[N][5], vis[N];

int main() {
	int x;
    scanf("%d %d", &n, &k);
    f1(i, 1, n) {
		f1(j, 1, k) {
			scanf("%d", &d[i][j]);
            if (d[i][j]) {
				v[i].pb(j);
            }
		}
    }
    int mn = 5;
    f1(i, 1, n) if (v[i].empty()) {
		puts("YES");
		return 0;
    }
    int pnt = 0;
    f1(i, 1, n) {
		if (mn > v[i].size()) {
            mn = v[i].size();
            pnt = i;
		}
    }
    if (mn >= 3) {
		puts("NO");
		return 0;
    }
    else if (mn == 1) {
        int now = v[pnt][0];
        f1(i, 1, n) if (!d[i][now]) {
			puts("YES");
			return 0;
        }
        puts("NO");
        return 0;
    }
    else if (mn == 2) {
        if (k <= 3) {
            puts("NO");
            return 0;
        }
        map <pii, int> h; vector <int> ww;
        f1(i, 1, n) if (v[i].size() == 2) {
            pii rpt = pii(v[i][0], v[i][1]);
            if (h.count(rpt)) continue;
            else {
				ww.clear();
                f1(j, 1, k) if (!d[i][j]) ww.pb(j);
                if (h.count(pii(ww[0], ww[1]))) {
					puts("YES");
					return 0;
                }
                h[rpt] = 1;
            }
        }
        puts("NO");
        return 0;
    }
	else assert(0);
	return 0;
}