#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin;
using std::cout;

typedef unsigned long long u64;
typedef double db;
typedef long long ll;
typedef unsigned u32;
const int N = 800800;

int n;

std::string s;

int c[N][26], tot = 1;
std::set<int> set[N];

inline void ins(std::string& s, int i) {
	int x = 1;
	for(char u : s) x = c[x][u-'a']?:c[x][u-'a']=++tot;
	set[x].insert(i);
}
int match[N];
ll res = 0;

inline void dfs(int x, int dep = 0) {
	for(int i = 0;i < 26;++i) if(c[x][i]) {
		dfs(c[x][i], dep + 1);
		if(set[c[x][i]].size()>set[x].size()) set[x].swap(set[c[x][i]]);
		set[x].insert(set[c[x][i]].begin(), set[c[x][i]].end());
	}
	for(;set[x].size()&&*set[x].begin()<0&&*set[x].rbegin()>0;){
		match[*set[x].rbegin()] = -*set[x].begin();
		set[x].erase(set[x].begin());
		set[x].erase(--set[x].end());
		res += dep;
	}
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	rep(i, 1, n) cin >> s, ins(s, i);
	rep(i, 1, n) cin >> s, ins(s, -i);
	dfs(1);
	cout<<res<<'\n';
	rep(i, 1, n) {
		cout << i << ' ' << match[i] << '\n';
	}
}