#include<bits/stdc++.h>
using namespace std;

#define N 300030

int a[N], b[N], n, ans;
#define left(I) (I<<1)
#define right(I) (I<<1|1)

template <class T> void chkmax(T &a, T b){ if(a < b) a = b; }

struct segment_tree{
	int arr[N], val[N << 2], L, R;
	void build(int l, int r, int id){
		if(l > r) return;
		if(l == r){ val[id] = arr[l]; return; }
		int m = (l + r) >> 1;
		build(l, m, left(id));
		build(m + 1, r, right(id));
		val[id] = max(val[left(id)], val[right(id)]);
	}

	int query_max(int l, int r, int id){
		if(L <= l && r <= R){
			return val[id];
		}
		int m = (l + r) >> 1;
		int ret = 0;
		if(m >= L) chkmax(ret, query_max(l, m, left(id)));
		if(m < R) chkmax(ret, query_max(m + 1, r, right(id)));
		return ret;
	}
}A, B;

int main(){
	//freopen("e.in", "r", stdin);
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++){
		scanf("%d", a + i);
		A.arr[i] = a[i];
		if(i > 1){ B.arr[i-1] = min(A.arr[i], A.arr[i-1]); }
	}
	A.build(1, n, 1);
	B.build(1, n-1, 1);
	for(int i = 0; i < n - 1; i ++){
		int rem = n - i;
		if(rem & 1){
			int k = rem / 2;
			B.L = k, B.R = n - k;
			ans = B.query_max(1, n - 1, 1);
		}
		else{
			int k = rem / 2;
			A.L = k, A.R = n - k + 1;
			ans = A.query_max(1, n, 1);
		}
		printf("%d ", ans);
	}
	printf("%d\n", *max_element(a + 1, a + n + 1));
}