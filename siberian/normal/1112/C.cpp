#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>

using namespace std;
#define int long long
int m, k, n, s;
vector <int> a;
map <int, int> b;
void read(){
	cin >> m >> k >> n >> s;
	a.resize(m);
	for (int i = 0; i < m; i++)
		cin >> a[i];
	for (int i = 0; i < s; i++)
	{
		int x;
		cin >> x;
		b[x]++;
	}
}

int ans= -1;
vector <int> fans;

void run(){
	int cnt = 0;
	int must = b.size();
	map <int, int> have;
	int can = m - n*k;
	int pos_right = -1;
	for (int i = 0; i < m; i++)
	{
		int need = i % k;
		while (pos_right < can - need + i + k - 1 && pos_right < m - 1){
			pos_right++;
			have[a[pos_right]]++;
			if (have[a[pos_right]] == b[a[pos_right]] && b[a[pos_right]] != 0)
				cnt++;
		}
		while (pos_right > can - need + i + k - 1) {
			if (have[a[pos_right]] == b[a[pos_right]] && b[a[pos_right]] != 0)
				cnt--;
			have[a[pos_right]]--;
			pos_right--;			
		}
		if (cnt == must)
		{
			for (int j = 0; j < need; j++)
				fans.push_back(j);
			ans = need;
			for (int j = i; j <= pos_right; j++)
			{
				if (b[a[j]] == 0 && ans != can)
				{
					ans++;
					fans.push_back(j);
				}
				else
				{
					b[a[j]]--;
				}
			}
			break;
		}
		if (have[a[i]] == b[a[i]] && b[a[i]] != 0)
				cnt--;
		have[a[i]]--;
	}
}

void write(){
	cout << ans << '\n';
	if (ans != -1)
	{
		for  (int i = 0; i < fans.size(); i++)
			cout << fans[i] + 1 << ' ';
	}
	cout << '\n';
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