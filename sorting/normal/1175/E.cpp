#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 7;
const int logN = 21;

int st[4 * N + 7], lp[4 * N + 7];
pair<int, int> p[N];

int my_max(int lvalue, int rvalue){
	if(p[lvalue].second > p[rvalue].second){
		return lvalue;
	}

	return rvalue;
}

void update(int idx, int l, int r, int sl, int sr, int val){
	if(lp[idx]){
		st[idx] = my_max(st[idx], lp[idx]);

		if(l != r){
			lp[2 * idx] = my_max(lp[2 * idx], lp[idx]);
			lp[2 * idx + 1] = my_max(lp[2 * idx + 1], lp[idx]);
		}

		lp[idx] = 0;
	}

	if(l > sr || r < sl){
		return;
	}
	if(sl <= l && r <= sr){
		st[idx] = my_max(st[idx], val);
		lp[idx] = my_max(lp[idx], val);
		return;
	}

	int mid = (l + r) >> 1;

	update(2 * idx, l, mid, sl, sr, val);
	update(2 * idx + 1, mid + 1, r, sl, sr, val);

	st[idx] = my_max(st[2 * idx], st[2 * idx + 1]);
	//cout << st[idx] << " " << l << " " << r << endl;
}

int query(int idx, int l, int r, int ss){
	if(lp[idx]){
		st[idx] = my_max(st[idx], lp[idx]);

		if(l != r){
			lp[2 * idx] = my_max(lp[2 * idx], lp[idx]);
			lp[2 * idx + 1] = my_max(lp[2 * idx + 1], lp[idx]);
		}

		lp[idx] = 0;
	}

	if(l > ss || r < ss){
		return 0;
	}
	if(l == r){
		//cout << st[idx] << endl;
		return st[idx];
	}

	int mid = (l + r) >> 1;

	int lvalue = query(2 * idx, l, mid, ss);
	int rvalue = query(2 * idx + 1, mid + 1, r, ss);

	return my_max(lvalue, rvalue);
}

int nxt[logN][N];

bool cmp(pair<int, int> lvalue, pair<int, int> rvalue){
	return make_pair(lvalue.second, lvalue.first) < make_pair(rvalue.second, rvalue.first);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;

	cin >> n >> m;

	p[0].first = -1;
	p[0].second = -1;

	for(int i = 1; i <= n; i++){
		cin >> p[i].first >> p[i].second;
		update(1, 0, N, p[i].first, p[i].second, i);
	}

	for(int i = 1; i <= n; i++){
		nxt[0][i] = query(1, 0, N, p[i].second);
		//cout << nxt[0][i] << " - " << i << endl;
	}

	for(int i = 1; i < logN; i++){
		for(int j = 1; j <= n; j++){
			nxt[i][j] = nxt[i - 1][ nxt[i - 1][j] ];
			//cout << nxt[i][j] << " i j "<< i << " " << j << endl; 
		}
	}

	for(int i = 0; i < m; i++){
		int x, y;

		cin >> x >> y;

		int ans = 1;

		x = query(1, 0, N, x);

		if(p[x].second >= y){
			cout << "1\n";

			continue;
		}

		for(int j = logN - 1; j >= 0; j--){
			if(p[ nxt[j][x] ].second < y){
				x = nxt[j][x];
				ans += (1 << j);
			}
		}
		x = nxt[0][x];
		x = p[x].second;
		ans++;

		if(x < y){
			cout << "-1\n";
		}
		else{
			cout << ans << "\n";
		}
	}

	return 0;
}