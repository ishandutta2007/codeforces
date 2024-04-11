#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin;
using std::cout;

typedef unsigned long long u64;
typedef double db;
typedef long long ll;
typedef unsigned u32;

const int N = 300300;
const int M = 1001000;

int n, k;
int a[N];

int prev[N];
int next[N];

int left[N], right[N], st[N], top;

std::vector<int> A[M], B[M];

inline int count(const std::vector<int> & a, int l, int r) {
	return upper_bound(a.begin(), a.end(), r) - lower_bound(a.begin(), a.end(), l);
}

int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> k;
	rep(i, 1, n) cin >> a[i], prev[i] = (prev[i - 1] + a[i]) % k;
	for(int i = n;i >= 1;--i) next[i] = (next[i + 1] + a[i]) % k;
	for(int i = 1;i <= n;++i) {
		A[prev[i]].push_back(i);
		B[next[i]].push_back(i);
	}
	rep(i, 1, n) {
		for(;top && a[i] >= a[st[top]];) -- top;
		left[i] = st[top] + 1, st[++top] = i;
	}
	top = 0; st[top] = n + 1;
	for(int i = n;i >= 1;--i) {
		for(;top && a[i] > a[st[top]];) -- top;
		right[i] = st[top] - 1, st[++top] = i;
	}
	ll res = -n;
	rep(i, 1, n) {
		const int le = left[i], ri = right[i];
		if(i - le > ri - i) {
			for(int j = i;j <= ri;++j) {
				int su = prev[j] - prev[i] - next[i];
				res += count(B[(k - su) % k], le, i);
			}
		} else {
			for(int j = le;j <= i;++j) {
				int su = next[j] - prev[i] - next[i];
				res += count(A[(k - su) % k], i, ri);
			}
		}
	}
	cout << res << '\n';
}