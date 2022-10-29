#include<bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i<b; i++)
#define dep(i,a,b) for(int i = a-1; i>=b; i--)
#define makeUnique(vec) sort(all(vec)); vec.resize(unique(all(vec)) - vec.begin())
#define LOG_vec(vec, sep) for (int fl = 0; fl < vec.size(); fl++) { cout << vec[fl]<< sep; } cout << "\n";
#define LOG_ints(vec, sep) for (int fl = 0; fl < MAXSIZE; fl++) { cout << vec[fl]<< sep; } cout << "\n"
#define all(x) (x).begin(), (x).end()
#define LSB(i) ((i) & -(i))
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> vvi;
typedef vector<ll> vi;


int main() {
	ll mod = 100000000;
	int n1, n2, k1, k2; cin >> n1 >> n2 >> k1 >> k2;
	vi tmp(7, 0);
	vvi tmp2(15,tmp);
	vector<vvi> tmp3(105,tmp2);
	vector<vector<vvi>> dp(205,tmp3);
	if (k1 != 0) {
		dp[1][0][1][0] = 1;
	}
	if (k2 != 0) {
		dp[1][1][1][1] = 1;
	}

	rep(i, 0, 204) {
		rep(ii, 0, 104) {
			rep(iii, 0, 14) {
				rep(iiii, 0, 2) {
					if (iiii == 0) {
						if (iii < k1&&i-ii <n1) {
							dp[i + 1][ii][iii + 1][iiii] = (dp[i][ii][iii][iiii]%mod+ dp[i + 1][ii][iii + 1][iiii])%mod;
						}
						if (ii < n2) {
							dp[i + 1][ii + 1][1][1] = (dp[i][ii][iii][iiii]%mod+ dp[i + 1][ii + 1][1][1])%mod;
						}
					}
					else {
						if (iii < k2 && ii < n2) {
							dp[i + 1][ii + 1][iii + 1][iiii] = (dp[i][ii][iii][iiii]%mod + dp[i + 1][ii + 1][iii + 1][iiii])%mod;
						}
						if (i - ii < n1) {
							dp[i + 1][ii][1][0] = (dp[i][ii][iii][iiii]%mod+ dp[i + 1][ii][1][0])%mod;
						}
					}
				}
			}
		}
	}
	ll sum = 0;
	rep(i,0,105) {
		rep(ii,0,15) {
			rep(iii,0,7) {
				sum += dp[n1 + n2][i][ii][iii];
				sum %= mod;
			}
		}
	}
	cout <<sum%mod << "\n";

	return 0;
}