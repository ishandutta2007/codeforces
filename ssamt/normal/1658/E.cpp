#include <bits/stdc++.h>

using namespace std;

template <typename T>
class SegmentTree {
	public:
		T (*func)(T, T);
		int n;
		vector<T> tree;
		T def;
		
		SegmentTree(int nodes, T (*f)(T, T), T def_val) {
			int i;
			nodes--;
			for(n=1; nodes>0; n<<=1, nodes>>=1);
			func = f;
			def = def_val;
			tree = vector<T>(2*n);
			for(i=2*n-1; i>0; i--) {
				if(i >= n) {
					tree[i] = def;
				} else {
					tree[i] = max(tree[2*i], tree[2*i+1]);
				}
			}
		}
		
		void update(int idx, T val) {
			int i;
			for(i=n+idx; i>0; i/=2) {
				if(i >= n) {
					tree[i] = val;
				} else {
					tree[i] = max(tree[2*i], tree[2*i+1]);
				}
			}
		}
		
		void change(int idx, T val) {
			tree[idx+n] = val;
		}
		
		void recal() {
			for(int i=n-1; i>0; i--) {
				tree[i] = func(tree[2*i], tree[2*i+1]);
			}
		}
		
		T query(int l, int r) {
			if(l == r) {
				return def;
			}
			return cur(0, n, 1, l, r);
		}
		
		T cur(int start, int end, int idx, int l, int r) {
			if(l <= start && end <= r) {
				return tree[idx];
			}
			if(end <= l || r <= start) {
				return def;
			}
			int mid = (start+end)/2;
			return max(cur(start, mid, idx*2, l, r), cur(mid, end, idx*2+1, l, r));
		}
		
		T idx(int i) {
			return tree[n+i];
		}
		
		void print() {
			int i;
			for(i=1; i<2*n; i++) {
				printf("%d ", tree[i]);
			}
			printf("\n");
		}
};

int large(int a, int b) {
	return (a>b)?a:b;
}

int main() {
	int i, j, k, l;
	int t, n, m, q;
	cin >> n >> k;
	vector<vector<int>> idx(n*n+1);
	SegmentTree<int> st(n*n, large, 0);
	vector<vector<int>> a(n, vector<int>(n));
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			scanf("%d", &a[i][j]);
			st.change(i*n+j, a[i][j]);
			idx[a[i][j]] = {i, j};
		}
	}
	st.recal();
	vector<vector<int>> answer(n, vector<int>(n, -1));
	int suml = 0, sumr = 2*n-1;
	int difl = -n+1, difr = n;
	while(true) {
		int get = st.query(0, n*n);
		if(get == 0) {
			break;
		}
		int px = idx[get][0], py = idx[get][1];
		st.update(px*n+py, 0);
		answer[px][py] = 1;
		if(px+py-k <= suml && sumr <= px+py+k+1 && px-py-k <= difl && difr <= px-py+k+1) {
			continue;
		}
		for(int sum=suml; sum<sumr; sum++) {
			int boxl = (sum<n)?-sum:sum-(2*n-2);
			int boxr = (sum<n)?sum:-sum+(2*n-2);
			for(int dif=max(boxl, ((sum+difl)%2)?difl+1:difl); dif<min(boxr+1, difr); dif+=2) {
				int x = (sum+dif)/2, y = (sum-dif)/2;
				//cout << x << " " << y << endl;
				if(abs(px-x)+abs(py-y) <= k) {
					dif = px-py+k-1;
					if((max(boxl, ((sum+difl)%2)?difl+1:difl)+dif)%2 != 0) {
						dif++;
					}
					continue;
				}
				st.change(x*n+y, 0);
				answer[x][y] = 0;
			}
		}
		st.recal();
		suml = max(suml, px+py-k);
		sumr = min(sumr, px+py+k+1);
		difl = max(difl, px-py-k);
		difr = min(difr, px-py+k+1);
		if(sumr-suml <= k+1 && difr-difl <= k+1) {
			for(i=0; i<n; i++) {
				for(j=0; j<n; j++) {
					if(a[i][j] == -1) {
						a[i][j] = 1;
					}
				}
			}
			break;
		}
	}
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			cout << (answer[i][j]?'M':'G');
		}
		cout << endl;
	}
}