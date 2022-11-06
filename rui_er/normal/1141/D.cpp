// Problem: CF1141D Colored Boots
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1141D
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1.5e5+5;

int n;
char s[N], t[N];
vector<int> pos1[26], pos2[26], qm1, qm2;
vector<tuple<int, int> > ans;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d%s%s", &n, s+1, t+1);
	rep(i, 1, n) {
		if(s[i] != '?') pos1[s[i]-'a'].push_back(i);
		else qm1.push_back(i);
		if(t[i] != '?') pos2[t[i]-'a'].push_back(i);
		else qm2.push_back(i);
	}
	rep(i, 0, 25) {
		while(!pos1[i].empty() && !pos2[i].empty()) {
			ans.emplace_back(pos1[i].back(), pos2[i].back());
			pos1[i].pop_back(); pos2[i].pop_back();
		}
		while(!pos1[i].empty() && !qm2.empty()) {
			ans.emplace_back(pos1[i].back(), qm2.back());
			pos1[i].pop_back(); qm2.pop_back();
		}
		while(!qm1.empty() && !pos2[i].empty()) {
			ans.emplace_back(qm1.back(), pos2[i].back());
			qm1.pop_back(); pos2[i].pop_back();
		}
	}
	while(!qm1.empty() && !qm2.empty()) {
		ans.emplace_back(qm1.back(), qm2.back());
		qm1.pop_back(); qm2.pop_back();
	}
	printf("%u\n", ans.size());
	for(auto i : ans) printf("%d %d\n", get<0>(i), get<1>(i));
	return 0;
}//qwq