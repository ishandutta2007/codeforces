#include<bits/stdc++.h>
using namespace std;

#define N 2000100

class segment_tree{
public:
	int mx[N], SET[N], L, R, val;

	#define left(I) (I<<1)
	#define right(I) (I<<1|1)

	void push_down(int id){
		if(SET[id]){
			mx[left(id)] = mx[right(id)] = SET[id];
			SET[left(id)] = SET[right(id)] = SET[id];
			SET[id] = 0;
		}
	}

	void push_up(int id){
		mx[id] = max(mx[left(id)], mx[right(id)]);
	}

	void update(int l, int r, int id){
		if(L <= l && R >= r){
			mx[id] = SET[id] = val; return;
		}
		int m = (l + r) >> 1;
		push_down(id);
		if(m >= L) update(l, m, left(id));
		if(m < R) update(m + 1, r, right(id));
		push_up(id);
	}

	int query(int l, int r, int id){
		if(L <= l && R >= r){ return mx[id]; }
		push_down(id);
		int m = (l + r) >> 1;
		int tmp = 0;
		if(m >= L) tmp = max(tmp, query(l, m, left(id)));
		if(m < R) tmp = max(tmp, query(m + 1, r, right(id)));
		return tmp;
	}
}A, B;

vector <int> v[N];
int dtime, dt[N], ft[N];
int n, x, y, query, type;

void dfs(int x, int pre){
	dt[x] = ++ dtime;
	for(auto y : v[x]){
		if(y == pre) continue;
		dfs(y, x);
	}
	ft[x] = dtime;
}

int main(){
	scanf("%d", &n);
	//cout << n << endl;
	for(int i = 1; i < n; i ++){
		scanf("%d %d", &x, &y);
		v[x].emplace_back(y);
		v[y].emplace_back(x);
	}
	dfs(1, 0);
//	cout << dtime << endl;
	scanf("%d", &query);
	for(int step = 1; step <= query; step ++){
		scanf("%d %d", &type, &x);
		if(type == 1){
			A.L = dt[x];
			A.R = ft[x];
			A.val = step;
			A.update(1, dtime, 1);
		}
		else if(type == 2){
			B.L = B.R = dt[x];
			B.val = step;
			B.update(1, dtime, 1);
		}
		else{
			A.L = dt[x];
			A.R = dt[x];
			B.L = dt[x];
			B.R = ft[x];
		//	cout << A.query(1, dtime, 1) << "  AA  " << B.query(1, dtime, 1) << endl;
			if(A.query(1, dtime, 1) <= B.query(1, dtime, 1)) puts("0");
			else puts("1");
		}
	}
}