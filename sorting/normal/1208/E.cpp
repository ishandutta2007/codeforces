#include <bits/stdc++.h>

using namespace std;

const long long MAXN = 1e6 + 7;
const long long inf = 1e9;

vector<long long> a[MAXN];
long long ans[MAXN];
multiset<long long> ms;

void update(int l, int r, long long val){
	//cout << l << " " << r << " " << val << " l r val" << endl;
	ans[l] += val;
	ans[r + 1ll] -= val;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n, w;

	cin >> n >> w;

	for(long long i = 0; i < n; ++i){
		long long sz;
		cin >> sz;

		for(long long j = 0; j < sz; ++j){
			long long x;

			cin >> x;

			a[i].push_back(x);
		}
	}

	for(long long i = 0; i < n; ++i){
		//cout << i << " i" << endl;
		long long sz = (long long)a[i].size();

		//long long mx = -inf;
		int f = 0;

		ms.clear();
		for(long long j = 0; j < sz - 1ll; ++j){
			ms.insert(a[i][j]);
			if(sz - 1 > w - j - 1){
				auto it = ms.find(a[i][f++]);
				ms.erase(it);
			}

			long long mx = *ms.rbegin();
			if(sz + j < w){
				mx = max(mx, 0ll);
			}

			update(j, j, mx);
		}

		ms.insert(a[i][sz - 1ll]);

		if(sz - 1ll < w - sz){
			update(sz - 1ll, w - sz, max(*ms.rbegin(), 0ll));
		}
		else{
			if(sz - 1ll > w - sz){
				auto it = ms.find(a[i][f]);
				ms.erase(it);
			}
			update(sz - 1ll, sz - 1ll, *ms.rbegin());
		}

		ms.clear();
		f = sz - 1;

		for(long long j = w - 1ll; j >= max(w - sz + 1ll, sz); --j){
			long long idx = sz - (w - j);
			ms.insert(a[i][idx]);
			if(j - sz + 1 < 0){
				auto it = ms.find(a[i][f--]);
				ms.erase(it);
			}

			long long mx = *ms.rbegin();
			if(j - sz >= 0){
				mx = max(mx, 0ll);
			}

			update(j, j, mx);
		}
	}

	for(long long i = 1; i < w; ++i){
		ans[i] += ans[i - 1];
	}

	for(long long i = 0; i < w; ++i){
		cout << ans[i] << " ";
	}
	cout << "\n";

	return 0;
}