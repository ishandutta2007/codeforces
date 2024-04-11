#include <bits/stdc++.h>
using namespace std;
#define N 210
#define K 15
#define inf 1000000000
#define ep 1e-9
#define mp make_pair
#define pb push_back
#define ll long long
template<class T> void chkmax(T &a, T b) {if (a < b) a = b;}
template<class T> void chkmin(T &a, T b) {if (a > b) a = b;}
typedef pair<int, int> pii;

int n, m, f[N];
string s[N], pre[N], suf[N];
map<string, bool> p[N][K];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		cin>>s[i];
		for (int j = 1; j < K; j ++) {
			for (int k = 0; k + j <= s[i].length(); k ++) p[i][j][s[i].substr(k, j)] = 1;
			if (p[i][j].size() == 1<<j) f[i] = j;
		}
		if (s[i].length() < K) pre[i] = s[i], suf[i] = s[i];
		else pre[i] = s[i].substr(0, K), suf[i] = s[i].substr(s[i].length() - K, K);
	}
	scanf("%d", &m);
	int a, b;
	for (int i = n + 1; i <= n + m; i ++) {
		scanf("%d%d", &a, &b);
		pre[i] = pre[a];
		if (pre[a].length() < K) {
			pre[i] += pre[b];
			if (pre[i].length() > K) pre[i] = pre[i].substr(0, K);
		}
		suf[i] = suf[b];
		if (suf[b].length() < K) {
			suf[i] = suf[a] + suf[b];
			if (suf[i].length() > K) suf[i] = suf[i].substr(suf[i].length() - K, K);
		}
		string tmp = suf[a] + pre[b];
		for (int j = 1; j < K; j ++) {
			for (map<string, bool> ::iterator it = p[a][j].begin(); it != p[a][j].end(); it ++) p[i][j][it->first] = 1;
			for (map<string, bool> ::iterator it = p[b][j].begin(); it != p[b][j].end(); it ++) p[i][j][it->first] = 1;
			for (int k = 0; k + j <= tmp.length(); k ++) p[i][j][tmp.substr(k, j)] = 1;
			if (p[i][j].size() == 1<<j) f[i] = j;
		}
		cout<<f[i]<<endl;
	}
}