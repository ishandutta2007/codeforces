#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 7;
const int MAXF = MAXN * 23;

struct Fenwick{
	int arr[MAXF];

	Fenwick(){}

	void Update(int idx, int val){
		for(; idx < MAXF; idx += (idx & -idx))
			arr[idx] += val;
	}

	int Query(int idx){
		int ret = 0;
		for(; idx >= 1; idx -= (idx & -idx))
			ret += arr[idx];
		return ret;
	}

	int Query(int l, int r){
		return Query(r) - Query(l - 1);
	}
};

int p[MAXN], rev_p[MAXN], ans[MAXN], n, m;
vector<array<int, 3> > intervals;//left, right, idx
Fenwick f;

bool cmp(array<int, 3> lvalue, array<int, 3> rvalue){
	if(lvalue[0] != rvalue[0])
		return lvalue[0] > rvalue[0];
	if(lvalue[1] != rvalue[1])
		return lvalue[1] < rvalue[1];
	return lvalue[2] < rvalue[2];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> p[i];

	for(int i = 0; i < m; ++i){
		array<int, 3> interval;
		cin >> interval[0] >> interval[1];
		interval[2] = i;

		intervals.push_back(interval);
	}

	for(int i = 1; i <= n; ++i)
		rev_p[p[i]] = i;

	for(int i = 1; i <= n; ++i){
		for(int j = i; j <= n; j += i){
			array<int, 3> interval{rev_p[i], rev_p[j], -1};
			if(interval[0] > interval[1])
				swap(interval[0], interval[1]);
			intervals.push_back(interval);
		}
	}

	sort(intervals.begin(), intervals.end(), cmp);

	for(auto interval: intervals){
		if(interval[2] != -1){
			ans[interval[2]] = f.Query(interval[1]);
		}
		else{
			f.Update(interval[1], 1);
		}
	}

	for(int i = 0; i < m; ++i){
		cout << ans[i] << "\n";
	}

	return 0;
}