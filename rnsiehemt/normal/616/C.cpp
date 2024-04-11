#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define em emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int dy[] = {-1,0,1,0}, dx[] = {0,1,0,-1};

int Y, X, p[1000005], sz[1000005];
char g[1005][1005];

int find(int a) {
	if (p[a] == a) return a;
	else return p[a] = find(p[a]);
}
void join(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) {
		p[b] = p[a];
		sz[a] += sz[b];
	}
}

int main()
{
	scanf("%d%d", &Y, &X);
	for (int y = 0; y < Y; y++) scanf(" %s", g[y]);
	for (int i = 0; i < Y*X; i++) {
		p[i] = i;
		sz[i] = 1;
	}
	for (int y = 0; y < Y; y++) for (int x = 0; x < X; x++) {
		if (g[y][x] == '.') {
			if (y+1 < Y && g[y+1][x] == '.') join(p[y*X + x], p[(y+1)*X +x]);
			if (x+1 < X && g[y][x+1] == '.') join(p[y*X + x], p[y*X + x+1]);
		}
	}
	for (int y = 0; y < Y; y++) for (int x = 0; x < X; x++) if (g[y][x] == '*') {
		std::set<int> s;
		for (int d = 0; d < 4; d++) {
			int ny = y + dy[d], nx = x + dx[d];
			if (0 <= ny && ny < Y && 0 <= nx && nx < X && g[ny][nx] == '.') {
				s.insert(find(p[ny*X + nx]));
			}
			int ans = 1;
			for (const int &i : s) ans += sz[i];
			g[y][x] = (ans % 10) + '0';
		}
	}
	for (int y = 0; y < Y; y++) printf("%s\n", g[y]);
}