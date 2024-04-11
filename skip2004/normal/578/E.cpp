#include<bits/stdc++.h>
const int maxn = 200200;
const int mod = 998244353;
typedef long long ll;
inline ll pow(ll a,int b,ll ans = 1) {
	for(;b;b >>= 1,a = a * a % mod) if(b & 1) ans = ans * a % mod;
	return ans;
}
inline ll inverse(int x){ return pow(x, mod - 2); }
inline void reduce(int & x){ x += x >> 31 & mod; }
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
int n, idx, tot;
char s[maxn];
std::vector<int> v[maxn];
std::stack<std::vector<int>*> stack[2];
std::vector<std::pair<int,int>> vector[2][2];
int nxt[maxn], go[maxn];
int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> s, n = strlen(s);
	for(int i = 0;i < n;++i) {
		if(stack[s[i] == 'L'].empty()) {
			v[++tot] = {i};
			stack[s[i] == 'R'].push(v + tot);
		} else {
			stack[s[i] == 'L'].top() -> push_back(i);
			stack[s[i] != 'L'].push(stack[s[i] == 'L'].top());
			stack[s[i] == 'L'].pop();
		}
	}
	std::cout << tot - 1 << '\n';
	for(int i = 1;i <= tot;++i){
		for(int j = 0;j + 1 < v[i].size();++j)
			nxt[v[i][j] + 1] = v[i][j + 1] + 1;
		vector[s[v[i].front()] == 'L'][s[v[i].back()] == 'L'].emplace_back(v[i].front() + 1, v[i].back() + 1);
	}
	for(;-- tot;) {
		if(vector[0][0].size() && vector[1][1].size()) {
			if(vector[0][1].size() < vector[1][0].size()) {
				auto x0 = vector[0][0].back(); vector[0][0].pop_back();
				auto x1 = vector[1][1].back(); vector[1][1].pop_back();
				nxt[x0.second] = x1.first;
				vector[0][1].emplace_back(x0.first, x1.second);
			} else {
				auto x0 = vector[0][0].back(); vector[0][0].pop_back();
				auto x1 = vector[1][1].back(); vector[1][1].pop_back();
				nxt[x1.second] = x0.first;
				vector[1][0].emplace_back(x1.first, x0.second);
			}
		} else
			if(vector[0][1].size() >= 2) {
				auto x0 = vector[0][1].back(); vector[0][1].pop_back();
				auto x1 = vector[0][1].back(); vector[0][1].pop_back();
				nxt[x0.second] = x1.first;
				vector[0][1].emplace_back(x0.first, x1.second);
		} else if(vector[1][0].size() >= 2) {
				auto x0 = vector[1][0].back(); vector[1][0].pop_back();
				auto x1 = vector[1][0].back(); vector[1][0].pop_back();
				nxt[x0.second] = x1.first;
				vector[1][0].emplace_back(x0.first, x1.second);
		} else if(vector[0][0].size()) {
			if(vector[0][1].size()) {
				auto x0 = vector[0][0].back(); vector[0][0].pop_back();
				auto x1 = vector[0][1].back(); vector[0][1].pop_back();
				nxt[x1.second] = x0.first;
				vector[0][0].emplace_back(x1.first, x0.second);
			} else {
				auto x0 = vector[0][0].back(); vector[0][0].pop_back();
				auto x1 = vector[1][0].back(); vector[1][0].pop_back();
				nxt[x0.second] = x1.first;
				vector[0][0].emplace_back(x0.first, x1.second);
			}
		} else if(vector[1][1].size()) {
			if(vector[0][1].size()) {
				auto x0 = vector[1][1].back(); vector[1][1].pop_back();
				auto x1 = vector[0][1].back(); vector[0][1].pop_back();
				nxt[x0.second] = x1.first;
				vector[1][1].emplace_back(x0.first, x1.second);
			} else {
				auto x0 = vector[1][1].back(); vector[1][1].pop_back();
				auto x1 = vector[1][0].back(); vector[1][0].pop_back();
				nxt[x1.second] = x0.first;
				vector[1][0].emplace_back(x1.first, x0.second);
			}
		} else {
			auto x0 = vector[0][1].back(); vector[0][1].pop_back();
			auto x1 = vector[1][0].back(); vector[1][0].pop_back();
			if(x0.second < x1.second) std::swap(x0, x1);
			for(int i = 1;i <= n;++i) if(nxt[i] == x0.second) nxt[i] = x1.first;
			nxt[x1.second] = x0.second;
		}
	}
	for(int i = 1;i <= n;++i) go[nxt[i]] = 1;
	for(int start = std::find(go + 1,go + n + 1,0) - go;start;start = nxt[start])
		std::cout << start << ' ';
}