//In the name of God
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int cnt[N];
int dis[N];
int arr[N];
int tmp[N];
vector<int> to;
vector<int> d;
void do_stuff(int x) {
	to.clear();
	d.clear();
	for(int i = 0; i < 18; ++i) {
		int y = x >> i;
		int p = i;
		while(y < N) {
			to.push_back(y);
			tmp[y] = 1e9;
			d.push_back(p);
			p++;
			y <<= 1;
			if(!y) break;
		}
	}
	for(int i = 0; i < to.size();++i) {
		int y = to[i];
		tmp[y] = min(tmp[y],d[i]);
	}
	sort(to.begin(),to.end());
	for(int i = 0; i < to.size();++i) {
		if(i && to[i] == to[i-1]) continue;
		int y = to[i];
		dis[y] += tmp[y];
		cnt[y]++;
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(0);
	int n; cin >> n;
	for(int i = 0; i < n;++i) {
		cin >> arr[i];
		do_stuff(arr[i]);
	}
	int m = 1e9;
	for(int i = 0; i <= 100000; ++i) {
		if(cnt[i] == n) {
			m = min(m,dis[i]);
		}
	}
	cout << m << '\n';
	return 0;
}