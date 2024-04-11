#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int P = 1000000007;
int t;
string s;

const int maxN = 110;
int dp[maxN][maxN * 26];

void precalc() {
	dp[0][0] = 1;
	for (int i = 0; i <= 100; ++i) {
		for (int sum = 0; sum < maxN * 26; ++sum) {
			if (dp[i][sum] == 0) {
				continue;
			}
			for (int j = 0; j < 26; ++j) {
				dp[i + 1][sum + j] += dp[i][sum];
				if (dp[i + 1][sum + j] >= P) {
					dp[i + 1][sum + j] -= P;
				}
			}
		}
	}
}

void solve() {
	int sum = 0;
	for (int i = 0; i < s.size(); ++i) {
		sum += s[i] - 'a';
	}
	printf("%d\n", (dp[s.size()][sum] + P - 1) % P);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	precalc();
	cin >> t;
	for (int i = 0; i < t; ++i) {
		cin >> s;
		solve();
	}

	return 0;
}