#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 7;

struct segment_tree{
	pair<int, int> arr[4 * MAXN];

	segment_tree(){
		for(int i = 0; i < 4 * MAXN; ++i){
			arr[i] = {0, 0};
		}
	}

	pair<int, int> merge(pair<int, int> lvalue, pair<int, int> rvalue){
		pair<int, int> ret;

		ret.first = max(lvalue.first, rvalue.first);
		ret.second = max(lvalue.second, rvalue.second);

		return ret;
	}

	void update(int idx, int l, int r, int s, pair<int, int> val){
		if(s < l || s > r){
			return;
		}
		if(l == r){
			arr[idx] = val;
			return;
		}

		int mid = (l + r) >> 1;
		update(2 *idx, l, mid, s, val);
		update(2 * idx + 1, mid + 1, r, s, val);

		arr[idx] = merge(arr[2 * idx], arr[2 * idx + 1]);
	}

	pair<int, int> query(int idx, int l, int r, int sl, int sr){
		if(sl > r || sr < l){
			return {0, 0};
		}
		if(sl <= l && r <= sr){
			return arr[idx];
		}

		int mid = (l + r) >> 1;

		pair<int, int> lvalue = query(2 * idx, l, mid, sl, sr);
		pair<int, int> rvalue = query(2 * idx + 1, mid + 1, r, sl, sr);

		return merge(lvalue, rvalue);
	}
};

int a[MAXN], cnt[MAXN], r[MAXN];
segment_tree st;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, q;

	cin >> n >> q;

	for(int i = 0; i < n; ++i){
		cin >> a[i];
		++cnt[a[i]];
		r[a[i]] = i;
	}

	for(int i = 0; i < n; ++i){
		st.update(1, 0, n - 1, i, {r[a[i]], cnt[a[i]]});
	}

	int pr = -1, ans = 0;
	for(int i = 0; i < n; ++i){
		if(i <= pr){
			continue;
		}
		pair<int, int> p = {r[a[i]], 1};
		//cout << p.first << " p.first" << endl;
		while(true){
			pair<int, int> p2 = st.query(1, 0, n - 1, i, p.first);
			if(p2.first <= p.first){
				p = p2;
				break;
			}
			p = p2;
		}
		//cout << p.first << " " << p.second << " i " << i << endl;
		ans += p.first - i + 1 - p.second;
		pr = p.first;
	}

	cout << ans << "\n";

	return 0;
}