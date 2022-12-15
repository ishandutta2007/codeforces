#include <bits/stdc++.h>

using namespace std;

const int kN = 5e5 + 7;
const int kMax = 1e7 + 7;
const int kBit = 26;

struct FenwickTree{
	int tr[kMax];

	void clear(){
		for(int i = 0; i < kMax; ++i)
			tr[i] = 0;
	}

	void update(int idx, int val){
		for(++idx; idx < kMax; idx += idx & -idx)
			tr[idx] += val;
	}

	int query(int idx){
		if(idx >= kMax)
			idx = kMax - 1;
		if(idx < 0)
			return 0;

		int ret = 0;
		for(++idx; idx >= 1; idx -= idx & -idx)
			ret += tr[idx];
		return ret;
	}

	int query(int l, int r){
		return query(r) - (l ? query(l - 1) : 0);
	}
};

int a[kN];
FenwickTree fenwick;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for(int i = 0; i < n; ++i)
		cin >> a[i];

	int ans = 0;
	for(int bit = 0; bit < kBit; ++bit){
		fenwick.clear();
		for(int i = 0; i < n; ++i)
			fenwick.update(a[i] % (1 << (bit + 1)), 1);

		int cnt = 0;
		for(int i = 0; i < n; ++i){
			int x = a[i] % (1 << (bit + 1));
			cnt += fenwick.query((1 << bit) - x, 2 * (1 << bit) - 1 - x);
			cnt += fenwick.query(3 * (1 << bit) - x, 4 * (1 << bit) - 1 - x);
			if((2 * x % (1 << (bit + 1))) & (1 << bit))
				--cnt;
		}

		cnt /= 2;
		if(cnt & 1)
			ans += (1 << bit);
	}

	cout << ans << "\n";
}