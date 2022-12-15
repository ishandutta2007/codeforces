#include <bits/stdc++.h>

using namespace std;

const long long N = 1e5 + 7;
const long long LOG = 20;

long long fenwick[N], n;

void update_fenwick(long long idx, long long val){
	for(; idx <= n; idx += (idx & (-idx)) ){
		fenwick[idx] += val;
	}
}

long long query_fenwick(long long idx){
	long long ret = 0;
	for(; idx >= 1; idx -= (idx & (-idx))){
		ret += fenwick[idx];
	}

	return ret;
}

long long a[N];
long long st[4 * N];

void init(long long idx, long long l, long long r){
	if(l == r){
		st[idx] = l;
		update_fenwick(l, a[l]);

		return ;
	}

	long long mid = (l + r) / 2;

	init(2 * idx, l, mid);
	init(2 * idx + 1, mid + 1, r);

	int lvalue = st[2 * idx];
	int rvalue = st[2 * idx + 1];

	if(a[lvalue] > a[rvalue]){
		st[idx] = lvalue;
	}
	else{
		st[idx] = rvalue;
	}

	return ;
}

long long query(long long idx, long long l, long long r, long long sl, long long sr){
	if(l > sr || r < sl){
		return 0;
	}

	if(sl <= l && r <= sr){
		return st[idx];
	}

	long long mid = (l + r) / 2;

	long long lvalue = query(2 * idx, l, mid, sl, sr);
	long long rvalue = query(2 * idx + 1, mid + 1, r, sl, sr);

	if(a[lvalue] > a[rvalue]){
		return lvalue;
	}
	else{
		return rvalue;
	}

	return 0;
}

void update1(long long idx, long long l, long long r, long long s, long long x){
	if(l > s || r < s){
		return ;
	}

	if(l == r){
		update_fenwick(l, (a[l] % x) - a[l]);
		a[l] %= x;

		return ;
	}

	long long mid = (l + r) / 2;

	update1(2 * idx, l, mid, s, x);
	update1(2 * idx + 1, mid + 1, r, s, x);

	int lvalue = st[2 * idx];
	int rvalue = st[2 * idx + 1];

	if(a[lvalue] > a[rvalue]){
		st[idx] = lvalue;
	}
	else{
		st[idx] = rvalue;
	}

	return ;
}

void update2(long long idx, long long l, long long r, long long k, long long x){
	if(l > k || r < k){
		return ;
	}

	if(l == r){
		update_fenwick(l, x - a[l]);
		a[l] = x;

		return ;
	}

	long long mid = (l + r) / 2;

	update2(2 * idx, l, mid, k, x);
	update2(2 * idx + 1, mid + 1, r, k, x);

	int lvalue = st[2 * idx];
	int rvalue = st[2 * idx + 1];

	if(a[lvalue] > a[rvalue]){
		st[idx] = lvalue;
	}
	else{
		st[idx] = rvalue;
	}

	return ;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long m;

	cin >> n >> m;

	for(long long i = 1; i <= n; i++){
		cin >> a[i];
	}

	init(1, 1, n);

	for(long long i = 0; i < m; i++){
		long long type;

		//for(int j = 1; j <= n; j++){
		//	cout << a[j] << " ";
		//}
		//cout << "\n\n";

		cin >> type;

		if(type == 1){
			long long l, r;

			cin >> l >> r;

			if(l != 1){
				cout << query_fenwick(r) - query_fenwick(l - 1) << "\n";
			}
			else{
				cout << query_fenwick(r) << "\n";
			}

			continue;
		}

		if(type == 2){
			long long l, r, x;

			cin >> l >> r >> x;

			while(true){
				int idx = query(1, 1, n, l, r);
				if(a[idx] < x){
					break;
				}

				update1(1, 1, n, idx, x);
			}

			continue;
		}

		if(type == 3)
		{
			long long k, x;

			cin >> k >> x;

			update2(1, 1, n, k, x);
			continue;
		}
	}

	return 0;
}