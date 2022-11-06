//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 905;

int n, k, a[N], buc[N];
vector<int> ans[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d%d", &n, &k);
	rep(i, 1, k) {
		scanf("%d", &a[i]);
		buc[a[i]] = 1;
		ans[i].push_back(a[i]);
	}
	int j = 1;
	rep(i, 1, k) {
		while((int)ans[i].size() < n) {
			while(buc[j]) ++j;
			ans[i].push_back(j);
			++j;
		}
		for(int j : ans[i]) printf("%d ", j);
		puts("");
	}
	return 0;
}