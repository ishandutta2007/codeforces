#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const ll Mod = 1000*1000*1000+7;

int N, o[5005][5005];
char s[5005];
std::vector<int> v;
ll dp[5005][5005], ans;

bool cmp1(const int &a, const int &b) {
	return s[a] < s[b];
}
int prevl;
bool cmp2(const int &a, const int &b) {
	if (s[a] < s[b]) return true;
	if (s[b] < s[a]) return false;
	return o[prevl][a+1] < o[prevl][b+1];
}
bool cmp3(int l, int i, int r) {
	if (r-i > i-l) return true;
	else if (i-l > r-i) return false;
	else {
		int len = i-l;
		return o[len][l] < o[len][i];
	}
}

int main()
{
	scanf("%d %s", &N, s);

	for (int i = 0; i < N; i++) v.push_back(i);
	std::sort(v.begin(), v.end(), cmp1);
	int oo = 0;
	for (int i = 0; i < sz(v); i++) {
		if (i && cmp1(v[i-1], v[i])) oo++;
		o[1][v[i]] = oo;
	}
	for (int l = 2; l <= N; l++) {
		v.clear();
		for (int i = 0; i < N-l+1; i++) v.push_back(i);
		prevl = l-1;
		std::sort(v.begin(), v.end(), cmp2);
		int oo = 0;
		for (int i = 0; i < sz(v); i++) {
			if (i && cmp2(v[i-1], v[i])) oo++;
			o[l][v[i]] = oo;
		}
	}
	for (int i = 1; i < N; i++) {
		if (s[i] == '0') continue;
		dp[0][i] = 1;
		int r = i+1;
		ll ways = 0;
		for (int l = i-1; l >= 0; l--) {
			if (s[l] == '0') continue;
			while (r <= N && !cmp3(l, i, r)) {
				dp[i][r] = (dp[i][r] + ways) % Mod;
				r++;
			}
			ways = (ways + dp[l][i]) % Mod;
		}
		while (r <= N) {
			dp[i][r] = (dp[i][r] + ways) % Mod;
			r++;
		}
	}
	for (int i = 0; i < N; i++) ans = (ans + dp[i][N]) % Mod;
	ans = (ans + 1) % Mod;
	printf("%lld\n", ans);
}