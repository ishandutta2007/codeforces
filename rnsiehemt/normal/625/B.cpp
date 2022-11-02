#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

char s[100005], t[35];
int N, M, ans;

int main()
{
	scanf(" %s %s", s, t);
	N = strlen(s); M = strlen(t);
	for (int i = 0; i+M <= N;) {
		bool same = true;
		for (int k = 0; k < M; k++) {
			if (s[i+k] != t[k]) {
				same = false;
				break;
			}
		}
		if (same) {
			ans++;
			i = i+M;
		} else {
			i++;
		}
	}
	printf("%d\n", ans);
}