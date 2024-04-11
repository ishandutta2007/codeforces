#include <bits/stdc++.h>

/*
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <set>
*/

using namespace std;

typedef long long LL;
typedef double DB;
typedef pair<int, int> PII;

const int inf = 0x7f7f7f7f;

#define rdi() read<int>()
#define rdl() read<LL>()
#define rds(a) scanf("%s", a)
#define mk(i, j) make_pair(i, j)
#define pb push_back
#define fi first
#define se second
#define For(i, j, k) for (int i = j; i <= k; i ++)
#define Rep(i, j, k) for (int i = j; i >= k; i --)
#define Edge(i, u) for (int i = head[u]; i; i = e[i].nxt)

template<typename t> t read() {
	t x = 0; int f = 1; char c = getchar();
	while (c > '9' || c < '0') f = c == '-' ? -1 : 1 , c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48 , c = getchar();
	return x * f;
}

template<typename t> void write(t x) {
	if (x < 0){
		putchar('-'), write(-x);
		return;
	}
	if (x >= 10) write(x / 10);
	putchar(x % 10 + 48);
}

const int maxn = 1e5 + 10;

struct Hanoi{
	int in, out, h;
	
	bool operator < (const Hanoi & t) const {
		return out > t.out || (out == t.out && in > t.in);
	}
}a[maxn];
int n;
LL h, ans;

stack <Hanoi> s;

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	n = rdi();
	
	For(i, 1, n) a[i].in = rdi(), a[i].out = rdi(), a[i].h = rdi();
	
	sort(a + 1, a + n + 1);
	
	s.push(a[1]), h = a[1].h, ans = 0;
	
	For(i, 2, n) {
		
		if (s.empty()) h = a[i].h, s.push(a[i]);
		else {
			
			if (a[i].out > s.top().in) h += a[i].h, s.push(a[i]);
			else {
				ans = max(ans, h);
				while (!s.empty() && a[i].out <= s.top().in) h -= s.top().h, s.pop();
				h += a[i].h, s.push(a[i]);	
			}
			
		}
		
	}
	ans = max(ans, h);
	write(ans);
	return 0;
}