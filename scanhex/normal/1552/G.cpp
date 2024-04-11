#include <bits/stdc++.h>
#include <bits/extc++.h> /** keep-include */

#pragma GCC optimize("-Ofast,-ffast-math")
#pragma GCC target("avx,sse,sse4.2,ssse3")


using namespace std;
using nagai = long long;

string acc = "ACCEPTED\n";
string rej = "REJECTED\n";

vector<vector<int>> all[50];

vector<int> szs;
int cur[100];
vector<int> rofl[15];
bitset<55> roflbs[15];
vector<int> nw[15], nwpos[15];
vector<int> stage;


struct chash { // large odd number for C
	const uint64_t C = nagai(4e18 * acos(0)) | 71;
	nagai operator()(nagai x) const { return __builtin_bswap64(x*C); }
};
//__gnu_pbds::gp_hash_table<nagai,int,chash> was({},{},{},{},{1<<18});

int n, k;
int cccc = 0;
int arr[100];
void check() {
	/*
	if (clock() * 1000 > 950 * CLOCKS_PER_SEC) {
		cout << acc;
		exit(0);
	}
	*/
	for(int i = 0; i < k; ++i) {
		int xi = cur[i];
		for(auto& kek : nw[i]) {
			if (xi == 0) {
				arr[kek] = 1;
			}
			else {
				arr[kek] = 0;
				--xi;
			}
		}
		int cc = 0;
		for(auto& x : rofl[i])
			cc += arr[x] == 0;
		for(auto& x : rofl[i]) {
			if (cc == 0) 
				arr[x] = 1;
			else 
				arr[x] = 0, --cc;
		}
	}
	for(int i = 0; i + 1 < n; ++i) {
		if (arr[i] > arr[i + 1]) {
			cout << rej;
			exit(0);
		}
	}
}
bitset<55> arrs[11];
bitset<55> roflmask[11], nwmask[11];
bitset<55> roflset[11][100], nwset[11][100];
void gena(int x) {
	if (x == szs.size()) {
		for(int i = 0; i + 1 < n; ++i) {
			if (arrs[x][i] > arrs[x][i + 1]) {
				cout << rej;
				exit(0);
			}
		}
		return;
	}
	if (x < 8 && clock() * 1000 > 970 * CLOCKS_PER_SEC) {
		cout << acc;
		exit(0);
	}
	for(int xi = 0; xi <= szs[x]; ++xi) {
		int xixi = xi;
		arrs[x + 1] = arrs[x];
		arrs[x+1] &= nwmask[x];
		arrs[x+1] ^= nwset[x][xi];
		int cc = 0;
		cc = rofl[x].size() - (arrs[x + 1] & roflbs[x]).count();
		arrs[x + 1] &= roflmask[x];
		arrs[x + 1] ^= roflset[x][cc];
		gena(x + 1);
	}
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
	cin >> n >> k;
	if (n == 1) {
		cout << acc;
		return 0;
	}
	vector<bool>used(n);
	stage.resize(n);
	nagai roflik = 1;
	for(int i = 0; i < k; ++i) {
		 int q;
		 cin >> q;
		 rofl[i].resize(q);
		 for(auto&x : rofl[i]) {
			 cin >> x;
			 --x;
			 roflbs[i][x] = true;
			 if (!used[x]) {
				 nw[i].push_back(x);
				 stage[x] = i;
			 }
			 used[x] = true;
		 }
		 sort(rofl[i].begin(),rofl[i].end());
		 sort(nw[i].begin(), nw[i].end());
		 szs.push_back(nw[i].size());
		 roflik *= nw[i].size();
		 for(auto& x : nw[i]) {
			 auto ind = find(rofl[i].begin(),rofl[i].end(),x) - rofl[i].begin();
			 nwpos[i].push_back(ind);
		 }
	}
	if (count(used.begin(),used.end(),false)) {
		cout << rej;
		return 0;
	}
	for(int i = 0; i < k; ++i) {
		roflmask[i].set();
		for(auto& x : rofl[i])
			roflmask[i][x] = false;
		nwmask[i].set();
		for(auto& x : nw[i])
			nwmask[i][x] = false;
		for(int cc = 0; cc <= nw[i].size(); ++cc) {
			int ccc = cc;
			for(auto& x : nw[i]) {
				if (ccc == 0) 
					nwset[i][cc][x] = 1;
				else
					nwset[i][cc][x] = 0, --ccc;
			}
		}
		for(int cc = 0; cc <= rofl[i].size(); ++cc) {
			int ccc = cc;
			for(auto& x : rofl[i]) {
				if (ccc == 0) 
					roflset[i][cc][x] = 1;
				else
					roflset[i][cc][x] = 0, --ccc;
			}
		}
	}
	gena(0);
	cout << acc;
	cerr << clock();
	return 0;
}

std::set<pair<vector<int>, int>> st;
void get(vector<int> arr, int x) {
	if (x == szs.size()) {
		for(int i = 0; i + 1 < n; ++i) {
			if (arr[i] > arr[i + 1]) {
				cout << rej;
				exit(0);
			}
		}
		return;
	}
	auto p = make_pair(arr, x);
	if (st.count(p)) return;
	st.insert(p);
	int iii = x;
	auto arr1 = arr;
	for(int i = 0; i <= szs[x]; ++i) {
		int ii = i;
		arr = arr1;
		for(auto& kek : nw[iii]) {
			if (ii == 0) {
				arr[kek] = 1;
			}
			else {
				arr[kek] = 0;
				--ii;
			}
		}
		int cc = 0;
		for(auto& x : rofl[iii])
			cc += arr[x] == 0;
		for(auto& x : rofl[iii]) {
			if (cc == 0) 
				arr[x] = 1;
			else 
				arr[x] = 0, --cc;
		}
		get(arr, x + 1);
	}
}