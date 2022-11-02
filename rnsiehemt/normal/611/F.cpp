#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const ll Mod = 1000*1000*1000+7;
const int inf = 1e9;

int dc[] = {'U','R','D','L'};
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};

int N, Y, X, y, x, maxy, maxx, miny, minx, curY, curX, last[4];
int firstx_[1000005], firsty_[1000005];
char s[500005];
ll ans;
std::vector<std::pair<ll, int>> events;

int &firstx(int a) { return firstx_[a + 500002]; }
int &firsty(int a) { return firsty_[a + 500002]; }
void add(ll l) { ans = (ans + l) % Mod; }

int main()
{
	std::fill(firstx_, firstx_+1000005, inf);
	std::fill(firsty_, firsty_+1000005, inf);
	firstx(0) = firsty(0) = -1;
	scanf("%d%d%d %s", &N, &Y, &X, s);
	curY = Y;
	curX = X;
	for (int i = 0; i < N; i++) {
		char c = s[i];
		int d;
		last[d] = i;
		for (d = 0; dc[d] != c; d++);
		y += dy[d]; x += dx[d];
		if (x > maxx || x < minx) {
			add(ll(i+1) * curY);
			curX--;
		}
		if (y > maxy || y < miny) {
			add(ll(i+1) * curX);
			curY--;
		}
		if (curX == 0 || curY == 0) break;
		domin(firstx(x), i);
		domin(firsty(y), i);
		domax(maxx, x);
		domax(maxy, y);
		domin(minx, x);
		domin(miny, y);
	}
	if (curX && curY) {
		if (x == 0 && y == 0) {
			printf("-1\n");
			return 0;
		}
		if (x > 0) {
			for (int xx = maxx - x + 1; xx <= maxx; xx++)
				events.push_back({firstx(xx), 0});
		}
		if (x < 0) {
			for (int xx = minx - x - 1; xx >= minx;  xx--)
				events.push_back({firstx(xx), 0});
		}
		if (y > 0) {
			for (int yy = maxy - y + 1; yy <= maxy; yy++)
				events.push_back({firsty(yy), 1});
		}
		if (y < 0) {
			for (int yy = miny - y - 1; yy >= miny; yy--)
				events.push_back({firsty(yy), 1});
		}
		std::sort(events.begin(), events.end());
		for (int cycle = 1;; cycle++) {
			ll extra = (ll(cycle) * N) % Mod;
			for (std::pair<ll, int> &p : events) {
				if (p.second == 0) {
					add(ll(p.first+1 + extra) * curY);
					curX--;
				} else {
					add(ll(p.first+1 + extra) * curX);
					curY--;
				}
				if (curX == 0 || curY == 0) break;
			}
			if (curX == 0 || curY == 0) break;
		}
	}
	printf("%lld\n", ans);
}