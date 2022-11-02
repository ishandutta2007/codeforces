#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
using namespace std;
#define int long long
int n, k;
vector <int> p;
void read(){
	cin >> n >> k;
	p.resize(n);
	for (int i = 0; i < n; i++)
		cin >> p[i];
}
int ans = 0;
void run(){
	int s = 0;
	int m = 0;
	vector <int> proc(k, 0);
	vector <int> full(k, 0);
	vector <int> now(k, 0);
	vector <int> fans(n, 0);
	while (m != n)
	{
		for (int i = 0; i < k; i++) {
			if (proc[i] == full[i] && full[i] > 0)
				m++;
			if (proc[i] == full[i] && s < n) {
				proc[i] = 0;
				full[i] = p[s++];
				now[i] = s-1;
			} 
			else if (proc[i] == full[i])
			{
				proc[i] = 0;
				full[i] = -1;
			}
		}

		int d = ((long double)100*m/n + 0.5);
		for (int i = 0; i < k; i++)
		{
			if (full[i] == -1)
				continue;
			proc[i]++;
			if (proc[i] == d) {
				fans[now[i]] = 1;
			}
		}
	}
	for (int i = 0; i < n; i++)
		ans += fans[i];
}

void write(){
	cout << ans;
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