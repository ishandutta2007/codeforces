#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 7;

long long st[4 * MAXN];

void update(int idx, int l, int r, int s, long long val){
	if(s < l || s > r){
		return;
	}
	if(l == r){
		st[idx] += val;
		return;
	}

	int mid = (l + r) >> 1;

	update(2 * idx, l, mid, s, val);
	update(2 * idx + 1, mid + 1, r, s, val);

	st[idx] = st[2 * idx] + st[2 * idx + 1];
}

pair<long long, int> query(int idx, int l, int r, long long val){
	//cout << idx << " " << l << " " << r << " " << val << endl;
	//cout << st[idx] << " - " << idx << endl;
	if(st[idx] <= val){
		return {st[idx], r};
	}
	if(l == r){
		return {st[idx], r};
	}

	int mid = (l + r) >> 1;

	pair<long long, int> lvalue = query(2 * idx, l, mid, val);

	if(val < lvalue.first){
		return {lvalue.first, lvalue.second};
	}

	pair<long long, int> rvalue = query(2 * idx + 1, mid + 1, r, val - lvalue.first);
	rvalue.first += lvalue.first;

	return rvalue;
}

long long a[MAXN], s[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n;

	cin >> n;

	for(long long i = 1; i <= n; ++i){
		update(1, 1, n, i, i);
	}

	for(int i = 1; i <= n; ++i){
		cin >> s[i];
	}

	for(long long i = n; i >= 1; --i){
		long long idx = query(1, 1, n, s[i]).second;
		//cout << idx << " --     idx" << endl;
		a[i] = idx;
		update(1, 1, n, idx, -idx);
	}

	for(int i = 1; i <= n; ++i){
		cout << a[i] << " ";
	}
	cout << "\n";

	return 0;
}