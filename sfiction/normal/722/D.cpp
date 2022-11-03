#include <bits/stdc++.h>

#define debug(x) cout << #x" = " << x;

#define st first
#define nd second

using namespace std;
using namespace placeholders;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

const int MAXN = 5E4 + 10;

int n;
int a[MAXN];
set<int> lst;

bool check(int limit){
	lst.clear();
	for (int i = 1; i <= n; ++i){
		int t = a[i];
		for (; t && (t > limit || lst.count(t)); t >>= 1);
		if (t)
			lst.insert(t);
		else
			return false;
	}
	return true;
}

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	int low = 1, high = 1E9, mid;
	while (low < high){
		mid = low + (high - low >> 1);
		if (check(mid))
			high = mid;
		else
			low = mid + 1;
	}
	check(low);
	bool flag = false;
	for (auto &p: lst){
		if (flag)
			putchar(' ');
		flag = true;
		printf("%d", p);
	}
	puts("");
	return 0;
}