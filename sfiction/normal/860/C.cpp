#include <bits/stdc++.h>

#define st first
#define nd second
#define all(x) (x).begin(), (x).end()

using namespace std;
using namespace placeholders;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template <class T> void mini(T &l, T r){l = min(l, r);}
template <class T> void maxi(T &l, T r){l = max(l, r);}

template <class TH> void _dbg(const char *sdbg, TH h){cerr << sdbg << "=" << h << "\n";}
template <class TH, class ...TA> void _dbg(const char *sdbg, TH h, TA... a){
	while (*sdbg != ',') cerr << *sdbg++; cerr << "=" << h << ","; _dbg(sdbg + 1, a...);
}
template <class T> ostream &operator <<(ostream &os, vector<T> V){
	os << "["; for (auto vv: V) os << vv << ","; return os << "]";
}
template <class L, class R> ostream &operator <<(ostream &os, pair<L, R> P){
	return os << "(" << P.st << "," << P.nd << ")";
}

#ifdef SFIC
	#define eput(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
	#define eput(...) 218
#endif

const int MAXN = 1E5 + 10;

string a[MAXN];
int b[MAXN], num[MAXN];
int mark[MAXN];

vector<int> f[2], g[2];

int main(){
	int n, exm = 0;
	scanf("%d", &n);

	char s[20];
	for (int i = 0; i < n; ++i){
		scanf("%s%d", s, b + i);
		a[i] = s;
		int l = a[i].size();

		exm += b[i];

		bool flag = true;
		if (a[i][0] == '0')
			flag = false;
		else{
			for (int j = 0; j < l; ++j)
				flag &= isdigit(a[i][j]);
			if (flag){
				int t = strtol(s, NULL, 10);
				flag &= 1 <= t && t <= n;
			}
		}
		if (flag){
//			f[b[i]].push_back(i);
			num[i] = strtol(s, NULL, 10);
		}
		else{
//			g[b[i]].push_back(i);
			num[i] = 0;
		}
	}

	for (int i = 0; i < n; ++i){
		if (num[i]){
			if (b[i] && 1 <= num[i] && num[i] <= exm)
				mark[num[i]] = 1;
			else if (!b[i] && exm < num[i])
				mark[num[i]] = 1;
			else{
				f[b[i]].push_back(i);
				mark[num[i]] = 2;
			}
		}
		else
			g[b[i]].push_back(i);
	}

	set<int> lst;
	int marked = true;
	for (int i = 1; i <= n; ++i){
		marked &= mark[i] == 1;
		if (mark[i] == 0)
			lst.insert(i);
	}

	vector<pair<string, string>> ans;
	if (g[0].size() == 0 && g[1].size() == 0){
		if (marked){
			puts("0");
			return 0;
		}
		int u = f[0].back();
		f[0].pop_back();
		g[0].push_back(u);
		ans.emplace_back(a[u], "999999");
		a[u] = "999999";
		lst.insert(num[u]);
	}

	{
		while (!f[0].empty() || !f[1].empty()){
			if (!f[0].empty() && lst.lower_bound(exm + 1) != lst.end()){
				int t = *lst.lower_bound(exm + 1);
				int u = f[0].back();
				f[0].pop_back();
				ans.emplace_back(a[u], to_string(t));
				lst.erase(t);
				lst.insert(num[u]);
			}
			else{
				int t = *lst.begin();
				int u = f[1].back();
				f[1].pop_back();
				ans.emplace_back(a[u], to_string(t));
				lst.erase(t);
				lst.insert(num[u]);
			}
		}

		for (auto &u: g[0]){
			int t = *lst.lower_bound(exm + 1);
			ans.emplace_back(a[u], to_string(t));
			lst.erase(t);
		}
		for (auto &u: g[1]){
			int t = *lst.begin();
			ans.emplace_back(a[u], to_string(t));
			lst.erase(t);
		}
	}

	printf("%d\n", (int)ans.size());
	for (auto &x: ans)
		printf("move %s %s\n", x.st.c_str(), x.nd.c_str());
	return 0;
}