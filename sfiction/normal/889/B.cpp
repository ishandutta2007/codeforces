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

const int S = 26, N = 1E5 + 10;

int nex[S], pre[S];
int vis[S];
char s[N];

int main(){
	int n;
	scanf("%d", &n);
	fill_n(nex, S, -1);
	fill_n(pre, S, -1);
	bool flag = true;
	for (int i = 0; i < n; ++i){
		scanf("%s", s);
		set<char> lst;
		lst.insert(s[0]), vis[s[0] - 'a'] = true;
		for (int i = 1; s[i]; ++i){
			int u = s[i - 1] - 'a', v = s[i] - 'a';
			flag &= lst.find(s[i]) == lst.end();
			lst.insert(s[i]), vis[s[i] - 'a'] = true;
			if (~nex[u] && nex[u] != v || ~pre[v] && pre[v] != u)
				flag = false;
			nex[u] = v, pre[v] = u;
		}
	}
	if (flag){
		string ans;
		int len = 0;
		for (int i = 0; i < S; ++i){
			if (vis[i] && !~pre[i]){
				int u = i;
				for (; ~nex[u]; u = nex[u])
					ans.push_back('a' + u);
				ans.push_back(u + 'a');
			}
			len += vis[i];
		}
		puts(ans.size() != len ? "NO" : ans.c_str());
	}
	else{
		puts("NO");
	}
	return 0;
}