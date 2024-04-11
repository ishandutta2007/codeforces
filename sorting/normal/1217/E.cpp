#include <bits/stdc++.h>

using namespace std;

const long long MAXN = 2e5 + 7;
const long long D = 11;
const long long inf = 2e9 + 7;

struct info{
	pair<long long, long long> p[D];

	info(){
		for(int i = 0; i < D; ++i){
			p[i] = make_pair(inf, inf);
		}
	}
};

info merge(info lvalue, info rvalue){
	info ret;
	for(int i = 0; i < D; ++i){
		if(lvalue.p[i].first <= rvalue.p[i].first){
			ret.p[i].first = lvalue.p[i].first;
			ret.p[i].second = min(lvalue.p[i].second, rvalue.p[i].first);
		}
		else{
			ret.p[i].first = rvalue.p[i].first;
			ret.p[i].second = min(rvalue.p[i].second, lvalue.p[i].first);
		}
	}

	return ret;
}

struct segment_tree{
	info arr[4 * MAXN];

	segment_tree(){
	}

	void update(long long idx, long long l, long long r, long long s, long long val[D]){
		if(s < l || s > r){
			return;
		}
		if(l == r){
			for(int i = 0; i < D; ++i){
				arr[idx].p[i] = make_pair(val[i], inf);
			}
			return;
		}

		long long mid = (l + r) >> 1;
		update(2 * idx, l, mid, s, val);
		update(2 * idx + 1, mid + 1, r, s, val);

		arr[idx] = merge(arr[2 * idx], arr[2 * idx + 1]);
	}

	info query(long long idx, long long l, long long r, long long sl, long long sr){
		if(sr < l || sl > r){
			return info();
		}
		if(sl <= l && r <= sr){
			return arr[idx];
		}

		long long mid = (l + r) >> 1;
		return merge(query(2 * idx, l, mid, sl, sr), query(2 * idx + 1, mid + 1, r, sl, sr));
	}
};

segment_tree st;
long long a[MAXN];
long long n, m, val[D];


void add(long long idx){
	long long x = a[idx];

	for(long long i = 0; i < D; ++i){
		if(x % 10)
			val[i] = a[idx];
		else
			val[i] = inf;
		x /= 10;
	}
	st.update(1, 0, n - 1, idx, val);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for(long long i = 0; i < n; ++i){
		cin >> a[i];
		add(i);
	}

	for(long long i = 0; i < m; ++i){
		long long type;

		cin >> type;

		if(type == 1){
			long long idx, x;

			cin >> idx >> x;
			--idx;

			a[idx] = x;
			add(idx);
		}
		else{
			long long ans = inf, l, r;

			cin >> l >> r;
			--l;
			--r;

			info t = st.query(1, 0, n - 1, l, r);
			for(int i = 0; i < D; ++i){
				ans = min(ans, t.p[i].first + t.p[i].second);
			}

			if(ans == inf){
				cout << "-1\n";
			}
			else{
				cout << ans << "\n";
			}
		}
	}

	return 0;
}