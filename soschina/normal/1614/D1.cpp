#include <cstdio>
#include <vector>
#include <utility>
#include <cstring>
#include <map>
using namespace std;
const int A = 2e7 + 1, N = 2e5 + 1;

int n, a[N], cnt[A], prime[A], nxt[A], len;
bool vis[A];

long long ans[A], ANS;

vector<pair<int, int>> primefac;

void getfac_from_disasm(vector<int> &res, int i, int now){
	if(i == -1){
		res.push_back(now);
		return;
	}
	int mul = 1;
	for(int j = 0; j <= primefac[i].second; j++){
		getfac_from_disasm(res, i - 1, mul * now);
		mul *= primefac[i].first;
	}
}

void getfac(vector<int> &res, int x){
	primefac.clear();
	res.clear();
	map<int, int> mp;
	while(x != 1){
		mp[x / nxt[x]]++;
		x = nxt[x];
	}
	for(auto pr : mp)
		primefac.push_back(pr);
	getfac_from_disasm(res, (int) primefac.size() - 1, 1);
}

long long dfs(int x){
	if(ans[x] != -1) return ans[x];
	vector<int> facs;
	getfac(facs, x);
	facs.pop_back();
	for(auto y : facs)
		ans[x] = max(ans[x], dfs(y) + 1ll * (cnt[y] - cnt[x]) * y);
	return ans[x];
}

int main(){
	memset(ans, 0xff, sizeof(ans));
	ans[1] = 0;
	nxt[1] = 1;
	for(int i = 2; i < A; i++){
		if(!vis[i]){
			nxt[i] = 1;
			prime[++len] = i;
		}
		for(int j = 1; j <= len && i * prime[j] < A; j++){
			vis[i * prime[j]] = true;
			nxt[i * prime[j]] = i;
			if(i % prime[j] == 0){
				break;
			}
		}
	}
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		vector<int> facs;
		getfac(facs, a[i]);
		for(auto x : facs)
			cnt[x]++;
	}
	for(int i = 1; i <= n; i++)
		ANS = max(ANS, 1ll * cnt[a[i]] * a[i] + dfs(a[i]));
	printf("%lld", ANS);
	return 0;
}