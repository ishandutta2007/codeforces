#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e9;
const int N = 200000 + 10;
int n, m, x;
int lg[N];

struct Rmq {
	vector<int> v;
	vector< vector<int> > st;
	vector<int> result;
	Rmq(vector<int> v_) {
		v = v_;
		st.resize(v.size(), vector<int>(20,0));
		for (int i = 0; i < v.size(); i ++) 
			st[i][0] = v[i];

		for (int i = 1; i < 20; i ++) {
			for (int j = 0; j < v.size(); j ++) {
				if (j + (1<<i) <= v.size())
				st[j][i] = max(st[j][i-1], st[j+(1<<(i-1))][i-1]);
			}
		}
		vector<int> stk;
		vector<int> l, r;
		for (int i = 0; i < v.size(); i ++) {
			while (stk.size()>0 && v[stk.back()] > v[i]) stk.pop_back();
			l.emplace_back(stk.size()==0?-1:stk.back());
			stk.emplace_back(i);
		}
		stk.clear();
		for (int i = (int)v.size() - 1; i >= 0; i --) {
			while (stk.size()>0 && v[stk.back()] >= v[i]) stk.pop_back();
			r.emplace_back(stk.size()==0?v.size():stk.back());
			stk.emplace_back(i);
		}
		reverse(r.begin(), r.end());
		for (int i = 0; i < v.size(); i ++) {
			//printf("%d %d %d\n", i, l[i], r[i]);
			int tmp = min(l[i]==-1?inf:query(l[i]+1, i), r[i]==v.size()?inf:query(i,r[i]-1));
			result.emplace_back(tmp);
		}
	}	
	int query(int l, int r) {
		int k = lg[r - l + 1];
		return max(st[l][k], st[r-(1<<k)+1][k]);
	}
};

struct Bit {
	vector<int> a;
	Bit(int n) {
		a.resize(n, 0);
	}
	void add(int pos, int x) {
		while (pos < a.size()) {
			a[pos] += x;
			pos += pos & (-pos);
		}
	}
	int sum(int pos) {
		int ans = 0;
		while (pos > 0) {
			ans += a[pos];
			pos -= pos & (-pos);
		}
		return ans;
	}
	int sum(int l, int r) {
		return sum(r) - sum(l - 1);
	}
};

int main() {
	for (int i = 1; i < N; i ++) lg[i] = (int)log2(i);
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin >> n >> m >> x;
	vector<int> a(n), b(m);
	for (int i = 0; i < n; i ++) cin >> a[i];
	for (int i = 0; i < m; i ++) cin >> b[i];

	Rmq qa(a), qb(b);	
	vector<int> na = qa.result;
	vector<int> nb = qb.result;

	assert(na.size() == a.size());
	assert(nb.size() == b.size());

	vector< pair<int,int> > A, B;
	for (int i = 0; i < a.size(); i ++) A.emplace_back(a[i], na[i]);
	for (int i = 0; i < b.size(); i ++) B.emplace_back(b[i], nb[i]);
	Bit tree(N);
	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), [](pair<int,int> e1, pair<int,int> e2) {
		return e1.second > e2.second;
	});

	long long ans = 0; 
	

	for (int i = 0, j = 0; i < A.size(); i ++) {
		while (j < B.size() && A[i].first + B[j].second > x) {
			tree.add(B[j].first, 1);
			j ++;
		}
		if (x+1-A[i].second <= x-A[i].first) {
			ans += tree.sum(x+1-A[i].second, x - A[i].first);
		}
	}
	cout << ans << endl;
	/*
		a[i] + b[j] <= x
		a[i] + nb[j] >= x+1
		na[i] + b[j] >= x+1
	*/
}