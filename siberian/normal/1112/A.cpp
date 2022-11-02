#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
using namespace std;
#define int long long
int n, m, k;
vector <int> pup, sh; 
set <int> need;
void read(){
	cin >> n >> m >> k;
	pup.resize(n);
	sh.resize(n);
	for (int i = 0; i < n; i++)
		cin >> pup[i];
	for (int i = 0; i < n; i++)
		cin >> sh[i];
	for (int i = 0; i < k; i++)
	{
		int x;
		cin >> x;
		need.insert(x);
	}
	vector <vector <pair <int, int> > > help(m);
	for (int i = 0; i < n; i++)
	{
		help[sh[i] - 1].push_back(make_pair(pup[i], i + 1));
	}
	for (int i = 0; i < m; i++)
	{
		sort(help[i].begin(), help[i].end());
	}
	int ans = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < help[i].size() - 1; j++)
			if (need.find(help[i][j].second) != need.end())
				ans++;
	}
	cout << ans << endl;
}

void run(){

}

void write(){

}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	run();
	write();
	return 0;
}