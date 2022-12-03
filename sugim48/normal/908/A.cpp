#include <bits/stdc++.h>
#include <random>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
struct edge { int v, w; };
const int INF = INT_MAX / 2;
const int MOD = 1e9 + 7;

bool vowel(char c) {
	return c=='a' || c=='i' || c=='u' || c=='e' || c=='o';
}

bool odd(char c) {
	return c=='1' || c=='3' || c=='5' || c=='7' || c=='9';
}

int main() {
	string s; cin >> s;
	int ans = 0;
	for (char c: s) if (vowel(c) || odd(c)) ans++;
	cout << ans << endl;
}