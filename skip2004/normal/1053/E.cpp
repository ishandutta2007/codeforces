#include<bits/stdc++.h>
using std::cin;
using std::cout;
 
const int maxn = 1001000;
int n, N;
int a[maxn];
 
inline void kill_pa()
{
	cout << "no" << '\n';
	exit(0);
}
 
int pre[maxn], suf[maxn];
int last[maxn], next[maxn];
 
inline void del(int a, int b)
{
	suf[pre[a]] = suf[b];
	pre[suf[b]] = pre[a];
}
 
inline int newid()
{
	static int idx = 1;
	for(;last[idx];)
		++ idx;
	return idx ++;
}
inline void solve(int l, int r)
{
	if(l + r & 1)
		kill_pa();
	for(int i = l;i <= r;i = suf[i])
	{
		for(;next[i];) 
		{
			if(next[i] > r) 
			{
				kill_pa();
			}
			solve(suf[i], pre[next[i]]);
			del(suf[i], next[i]);
			next[i] = next[next[i]];
		}
	}
	int s = 0, c = 0, father = a[pre[l]];
	for(int i = l;i <= r;i = suf[i])
		s += 1, c += bool(a[i]);
	s = s + 1 >> 1;
	if(c > s) {
		kill_pa();
	}
	for(int i = suf[l];i <= r;i = suf[i]) {
		if(!a[i] && c < s) {
			a[i] = newid();
			++ c;
		}
	}
	if(s == 1 && c == 0) a[l] = newid();
	for(int i = l;suf[i] <= r;i = suf[i]) {
		for(;i > l && suf[i] <= r && !a[pre[i]] && a[i] && a[suf[i]];) {
			a[pre[i]] = a[suf[i]];
			del(i, suf[i]);
			i = pre[pre[i]];
		}
		for(;i >= l && suf[suf[i]] <= r && a[i] && a[suf[i]] && !a[suf[suf[i]]];) {
			a[suf[suf[i]]] = a[i];
			del(suf[i], suf[suf[i]]);
			i = pre[i];
		}
	}
	for(int i = l;i <= r;i = suf[i]) if(!a[i]) {
		a[i] = father;
	}
}
 
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n, N = n + n - 1;
	for(int i = 1;i <= N;++i)
	{
		cin >> a[i];
	}
	if(a[1] && a[N] && a[1] != a[N])
		kill_pa();
	a[1] = a[N] = a[1] ? a[1] : a[N];
	for(int i = 0;i <= N;++i)
	{
		pre[i] = i - 1;
		suf[i] = i + 1;
	}
	for(int i = N;i >= 1;--i) if(a[i])
	{
		next[i] = last[a[i]];
		last[a[i]] = i;
	}
	solve(1, N);
	cout << "yes" << '\n';
	for(int i = 1;i <= N;++i)
	{
		cout << a[i] << " \n"[i == N];
	}
}