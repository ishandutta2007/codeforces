#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
void test(int x, int y) {
	int it = 0;
	while (1) {
		if (x < y) swap(x, y);
		printf("%d, x = %d, y = %d\n", it++, x, y);
		if (x == 2 && y == 1) break;
		x = x + (y-1) / y;
	
	}
}

int t, a[N];
int main() {
	scanf("%d", &t);



	while (t --) {
		int n; scanf("%d", &n);
		for(int i=1;i<=n;i++) {
			a[i]=i;
		}	
		vector<LL> v;
		v.push_back(2);
		while(1) {
			LL las = v.back();
			if (las * las < n) {
				v.push_back(las * las);
			} else {
				v.push_back(n); break;
			}
		}

		vector< pair<int,int> > ans;
		for(int i=2;i<=n;i++) {
			int pos = (*lower_bound(v.begin(),v.end(),i));
			if (i != pos)
				ans.push_back(make_pair(i, pos));
		}
		for(int i=v.size()-1;i>=1;i--) {
			int x = v[i], y = v[i-1];
			ans.push_back(make_pair(x,y));
			ans.push_back(make_pair(x,y));
		}
		printf("%d\n", ans.size());
		for(auto p: ans) {
			printf("%d %d\n", p.first, p.second);
		}
	}	
}