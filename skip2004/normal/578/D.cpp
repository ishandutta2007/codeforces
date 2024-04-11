#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin;
using std::cout;

typedef unsigned long long u64;
typedef double db;
typedef long long ll;
typedef unsigned u32;

const int N = 100100;
int n, m;
char s[N];
ll res = 0;
int suf[N];
int su[N];
int gr[N];

inline ll calc()
{
	ll res = 0;
	for(int i = n;i >= 1;--i) {
		if(i <= n - 2 && s[i] == s[i + 2])
			gr[i] = gr[i + 2];
		else
			gr[i] = i;
	}
	for(int i1 = 1;i1 <= n;++i1) {
		res += (i1 - 1) * (m - 1) * (s[i1] != s[i1 - 1]);
	}
	for(int i0 = 1;i0 <= n;++i0) {
		res += (n - i0) * (m - 1) * (s[i0] != s[i0 + 1]);
		if(s[i0] != s[i0 + 1]) {
			rep(i1, i0 + 1, std::min({n, gr[i0] + 1, gr[i0 + 1] + 1})) res -= 1;
		}
	}
	return res;
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m >> s + 1;

	res = calc() + (m - 1) * n;

	cout << res << '\n';
}