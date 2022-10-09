#include <iostream>
#include <map>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fs first
#define sc second
#define pb push_back

string s[2010];
int cnt_d[2010][2010], cnt_r[2010][2010];
int d[2010][2010];
int sum_d[2010][2010];
int mod = 1000000007;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    int n, m;
    cin >> n >> m;
    forn (i, n) {
    	cin >> s[i];
    }
    for (int i = n - 1; i >= 0; --i) {
		for (int j = m - 1; j >= 0; --j) {
			if (i < n - 1) {
				cnt_d[i][j] = cnt_d[i + 1][j] + (s[i + 1][j] == 'R');
			}
			if (j < m - 1) {
				cnt_r[i][j] = cnt_r[i][j + 1] + (s[i][j + 1] == 'R');
			}
		}
    }
    for (int i = n - 1; i >= 0; --i) {
    	vector<int> cur_sum(m + 1, 0);
		for (int j = m - 1; j >= 0; --j) {
			int dr = 0, dd = 0;
			if (i == n - 1 && j == m - 1) {
				d[i][j] = 1;
				dd = dr = 1;
			} else {
				dr += cur_sum[j + 1];
				dr += mod - cur_sum[m - cnt_r[i][j]];
				dr %= mod;
				dd += sum_d[i + 1][j];
				dd += mod - sum_d[n - cnt_d[i][j]][j];
				dd %= mod;
				d[i][j] = (dd + dr) % mod;
			}
			cur_sum[j] = (cur_sum[j + 1] + dd) % mod;
			sum_d[i][j] = (sum_d[i + 1][j] + dr) % mod;
		}
	}
	cout << d[0][0] << endl;
}