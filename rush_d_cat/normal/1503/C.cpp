#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;


int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	int n;
	cin >> n;	
	vector< vector<int> > p(n);

	for (int i = 0; i < n; i ++) {
		vector<int> v(3);
		cin >> v[0] >> v[1]; v[2] = i;
		p[i] = v; 
	}
	sort(p.begin(), p.end());

	LL sum = 0;
	for (auto v: p) sum += v[1];

	int mx = p[0][0];
	int idx = 0;
	//cout << "# " << sum << endl;
	for (auto v: p) {
		//cout << v[0] << " " << v[1] << " " << v[2] << endl;
		if (v[0] <= mx) {
			mx = max(mx, v[0] + v[1]);
		} else {
			assert(idx > 0);
			sum += v[0] - mx;
			//printf("add %d\n", p[idx][0] - p[idx-1][0]);
			mx = max(mx, v[0] + v[1]);
		}
		idx ++;
	}
	cout << sum << endl;
}