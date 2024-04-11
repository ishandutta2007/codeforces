#include <bits/stdc++.h>
#define ll long long
#define maxn 2005 /*rem*/
#define mod 998244353 
#define db double
#define vi vector<int>
#define pb push_back
#define pi pair<int, int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
char s[maxn];
char t[maxn];
vi otp;
int n;
void work(int x) {
	reverse(s + 1, s + n + 1);
	reverse(s + n + 1 - x, s + n + 1);
	otp.pb(n - x);
} 
int cnt[26];
int main() {
	cin >> n;
	scanf("%s", s + 1);
	scanf("%s", t + 1);
	for (int i = 1; i <= n; i++) {
		cnt[s[i] - 'a']++, cnt[t[i] - 'a']--;
	}
	for (int i = 0; i < 26; i++) 
		if (cnt[i]) {
			printf("-1\n");
			return 0;
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) 
			if (s[j] == t[i]) {
				work(j);
				work(n - 1);
				work(0);
				break;
			}
	cout << otp.size() << endl;
	for (auto v : otp) cout << v << ' ';
	cout << endl;
	return 0;
}
/*
1 2
..
*/