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

const int N = 2E3 + 10;

int n;
char a[N], b[N];
vector<int> ans;

void operate(int x){
	ans.push_back(x);
	rotate(a, a + (n - x), a + n);
	reverse(a, a + x);
}

bool add(int pre, char x){
	int r = find(a + pre, a + n, x) - a;
	if (r == n)
		return false;
	operate(n - r);
	operate(r - pre);
	operate(pre + 1);
	return true;
}

int main(){
	scanf("%d", &n);
	scanf("%s%s", a, b);
	int l = n >> 1, r = l;
	bool flag = true;
	if (n & 1){
		flag &= add(0, b[r++]);
	}
	while (0 < l){
		flag &= add(r - l, b[l - 1]), --l;
		flag &= add(r - l, b[r]), ++r;
	}
	if (flag){
		printf("%d\n", ans.size());
		for (int i = 0; i < ans.size(); ++i)
			printf("%d%c", ans[i], "\n "[i + 1 < ans.size()]);
	}
	else
		puts("-1");
	return 0;
}