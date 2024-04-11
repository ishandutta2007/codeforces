/* by Natsu Kinmoe */
#include <bits/stdc++.h>
using namespace std;
#define SZ(x)               ((int)(x).size())
#define all(x)              (x).begin(), (x).end()
#define loop(i, n)          for(int i = 0; i < (n); i++)
#define cont(i, n)          for(int i = 1; i <= (n); i++)
#define circ(i, a, b)       for(int i = (a); i <= (b); i++)
#define range(i, a, b, c)   for(int i = (a); ((c) > 0 ? i <= (b) : i >= (b)); i += (c))
#define foreach(it, v)      for(__typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define y0          y0O0OO00OO0OO0OO0OOO00OO0OO0O0O000OO0
#define y1          y1II11II11III11I1III11II111IIII1II1I1
#define pub         push_back
#define pob         pop_back
#define mak         make_pair
typedef long long   ll;
typedef long double lf;
const int   Inf = 0x3f3f3f3f;
const ll    INF = 0x3f3f3f3f3f3f3f3fll;
/* Source code starts here */

struct State {
	int x, y, msk;
	string s;
	State(int x, int y, int msk, string s) : x(x), y(y), msk(msk), s(s) {}
	bool inline operator<(const State &st) const {
		if(SZ(s) != SZ(st.s)) return SZ(s) > SZ(st.s);
		else return s > st.s;
	}
};

int n, m, k;
char s[55][55];
set<int> lgl[55][55];
int lst[55][55];
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

int main() {
	scanf("%d%d%d", &n, &m, &k);
	loop(i, n) scanf("%s", s[i]);
	int sx, sy;
	loop(i, n) loop(j, m) if(s[i][j] == 'S') sx = i, sy = j;
	priority_queue<State> pq;
	pq.push(State(sx, sy, 0, ""));
	while(pq.size()) {
		State st = pq.top(); pq.pop();
		loop(d, 4) {
			int nx = st.x + dx[d], ny = st.y + dy[d];
			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if(s[nx][ny] == 'T') {
				printf("%s\n", st.s.c_str());
				return 0;
			}
			if(s[nx][ny] == 'S') continue;
			int nmsk = st.msk | (1 << (s[nx][ny] - 'a'));
			if(__builtin_popcount(nmsk) > k || lgl[nx][ny].count(nmsk)) continue;
			if(lst[nx][ny] && (lst[nx][ny] & nmsk) == lst[nx][ny]) continue;
			lgl[nx][ny].insert(nmsk);
			lst[nx][ny] = nmsk;
			pq.push(State(nx, ny, nmsk, st.s + s[nx][ny]));
		}
	}
	return 0 & puts("-1");
}