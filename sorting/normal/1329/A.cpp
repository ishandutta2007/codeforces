#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<int> l(m);
	for(int i = 0; i < m; ++i)
		cin >> l[i];

	long long sum = 0;
	for(int i = 0; i < m; ++i)
		sum += (long long)l[i];

	if(sum < n){
		cout << "-1\n";
		return 0;
	}

	vector<int> p(m);
	int pr_start = -1, pr_end = 0;
	for(int i = 0; i < m; ++i){
		if(sum + pr_start + 1ll < n)
			p[i] = pr_start + 1 + (n - sum - pr_start - 1);
		else
			p[i] = pr_start + 1;

		if(p[i] > pr_end || p[i] <= pr_start || p[i] + l[i] > n){
			cout << "-1\n";
			return 0;
		}

		pr_start = p[i];
		pr_end = pr_start + l[i];
		sum -= l[i];
	}

	for(int x: p){
		cout << x + 1 << " ";
	}
	cout << "\n";
}