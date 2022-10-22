#include <bits/stdc++.h>

using namespace std;
using nagai=long long;
#define sz(x) int((x).size())

struct mt1488{
	using result_type = unsigned int;
	unsigned int seed = 239239239;
	mt1488(unsigned int seed) : seed(seed){}
	mt1488(){}
	unsigned int min(){
		 return 0;
	}
	unsigned int max(){
		 return UINT_MAX;
	}
	unsigned int operator()(){
		seed ^= seed << 13;
		seed ^= seed >> 17;
		seed ^= seed << 5;
		return seed;
	}
} rnd;

int main(){
	int n;
	cin >> n;
	vector<bool>kek(n);
	int cc = 0;
	int sq=1;
	while(sq*sq<n)++sq;
	vector<int>ord;
	int cur = 0;
	vector<bool>used(n);
	for(int i=0;i<n;++i) {
		ord.push_back(cur);
		used[cur]=true;
		cur += sq;
		if (cur >= n)cur -= n;
		while(used[cur])++cur;
	}
	for(int i=0;i<9999;++i) {
		int cnt=0;
		vector<int>v;
		for(int x:ord)
			if (!kek[x]) {
				v.push_back(x);
				++cnt;
				if (cnt == sq)
					break;
			}
		cout << sq << ' ';
		for(int x : v)
			cout << x+1 << ' ', kek[x] = true;
		cout << endl;
		int x;
		cin >> x;
		--x;
		for(int i=0;i<sq;++i) {
			int xx = x + i;
			if (xx >= n) xx -= n;
			kek[xx]=false;
		}
	}
	cout << 0 << endl;
	return 0;
}