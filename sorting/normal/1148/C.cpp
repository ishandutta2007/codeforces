#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 7;

int a[N], n;
int where[N];
vector<pair<int, int> > ans;

void add_swap(int x, int y){
	ans.push_back({x, y});
	swap(a[x], a[y]);
	swap(where[a[x]], where[a[y]]);
}

void swap_idx(int i, int j){
	if(i > n / 2 && j > n / 2){
		add_swap(i, 1);
		add_swap(j, 1);
		add_swap(i, 1);
		return;
	}
	if(i <= n / 2 && j <= n / 2){
		add_swap(i, n);
		add_swap(j, n);
		add_swap(i, n);
		return;
	}
	if(i > j){
		swap(i, j);
	}

	if(i == 1 || j == n){
		add_swap(i, j);
		return;
	}

	add_swap(i, n);
	add_swap(j, 1);
	add_swap(1, n);
	add_swap(j, 1);
	add_swap(i, n);

	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; i++){
		cin >> a[i];
		where[a[i]] = i;
	}

	for(int i = 1; i <= n; i++){
		if(where[i] != i){
			swap_idx(where[i], i);
		}
	}

	/*for(int i = 1; i <= n; i++){
		cout << a[i] << " ";
	}
	cout << "\n";*/

	cout << ans.size() << "\n";

	for(pair<int, int> p: ans){
		cout << p.first << " " << p.second << "\n";
	}

	return 0;
}