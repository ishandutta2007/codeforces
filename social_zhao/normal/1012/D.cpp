#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 4e5 + 5;
char s[N], t[N], tmps[N], tmpt[N]; 
int n, m, sumS[N], sumT[N];
vector<pair<int, int>> ans1, ans2;

void solve(vector<pair<int, int>>& ans, int n, int m) {
	int p1 = n, p2 = m, flag = 0;
	while(p1 || p2) {
		while(p1 && s[p1] == s[p1 - 1]) --p1;
		while(p2 && t[p2] == t[p2 - 1]) --p2;
		
		if(p1) --p1;
		if(p2) --p2;
		
		if(!p1 && !p2) break;
		if(!flag) ans.emplace_back(p1, p2);
		else ans.emplace_back(p2, p1);
		flag ^= 1;
	}
}

vector<pair<int, int>> calc(int n, int m) {
	vector<pair<int, int>> ans1, ans2;
	s[++n] = 'a', t[++m] = 'b';
	solve(ans1, n, m);
	s[n] = 'b', t[m] = 'a';
	solve(ans2, n, m);
	return ans1.size() < ans2.size()? ans1 : ans2;
}

int main() {
//	freopen("data.in", "r", stdin);
	scanf("%s", tmps + 1), n = strlen(tmps + 1);
	scanf("%s", tmpt + 1), m = strlen(tmpt + 1);
	
	for(int i = 2; i <= n; i++) sumS[i] = sumS[i - 1] + (tmps[i] != tmps[i - 1]);
	for(int i = 2; i <= m; i++) sumT[i] = sumT[i - 1] + (tmpt[i] != tmpt[i - 1]);
	
	vector<pair<int, int>> ans;
	int mn = max(sumS[n], sumT[m]) + (sumS[n] == sumT[m] && tmps[n] == tmpt[m]), bs = 0, bt = 0, lens = 0, lent = 0, sm;
	
	// swap s[1, i] and t[1, 0]
	for(int i = 1; i < n; i++) {
		int lft = sumS[n] - sumS[i + 1], rht = sumS[i] + sumT[m] + (tmps[i] != tmpt[1]);
		int now = 1 + max(lft, rht) + (lft == rht && tmps[n] == tmpt[m]);
		if(now < mn) 
			bs = i, bt = 0, mn = now;
	}
	// swap s[1, 0] and t[1, i]
	for(int i = 1; i < m; i++) {
		int lft = sumS[n] + sumT[i] + (tmpt[i] != tmpt[1]), rht = sumT[m] - sumT[i + 1];
		int now = 1 + max(lft, rht) + (lft == rht && tmps[n] == tmpt[m]);
		if(now < mn) 
			bs = 0, bt = i, mn = now;
	}
	// swap s[1, i] and t[1, 1]
	sm = 1;
	while(tmpt[sm] == tmpt[sm + 1]) ++sm;
	for(int i = 1; i < n; i++) {
		int lft = sumS[n] - sumS[i + 1] + (tmpt[sm] != tmps[i + 1]), 
			rht = sumT[m] - (sm != m) + sumS[i] + (sm != m && tmps[i] != tmpt[sm + 1]),
			now = 1 + max(lft, rht) + (lft == rht && tmps[n] == tmpt[m]);
		if(sm == m) now = 1 + max(lft, rht) + (lft == rht && tmps[i] == tmps[n]);
		if(now < mn) 
			bs = i, bt = sm, mn = now;
	}
	// swap s[1, 1] and t[1, i]
	sm = 1;
	while(tmps[sm] == tmps[sm + 1]) ++sm;
	for(int i = 1; i < m; i++) {
		int lft = sumS[n] - (sm != n) + sumT[i] + (sm != n && tmpt[i] != tmps[sm + 1]),
			rht = sumT[m] - sumT[i + 1] + (tmps[sm] != tmpt[i + 1]),
			now = 1 + max(lft, rht) + (lft == rht && tmps[n] == tmpt[m]);
		if(sm == n) now = 1 + max(lft, rht) + (lft == rht && tmpt[i] == tmpt[m]);
		if(now < mn) 
			bs = sm, bt = i, mn = now;
	}
	
	for(int i = 1; i <= bs; i++) t[++lent] = tmps[i];
	for(int i = 1; i <= bt; i++) s[++lens] = tmpt[i];
	for(int i = bs + 1; i <= n; i++) s[++lens] = tmps[i];
	for(int i = bt + 1; i <= m; i++) t[++lent] = tmpt[i];
	ans = calc(lens, lent);
	if(bs + bt) reverse(ans.begin(), ans.end()), ans.emplace_back(bs, bt), reverse(ans.begin(), ans.end());
	
	cout << ans.size() << endl;
//	return 0;
	for(auto v : ans) cout << v.first << " " << v.second << endl;
	return 0;
}