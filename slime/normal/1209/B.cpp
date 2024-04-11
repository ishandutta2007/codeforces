#include <bits/stdc++.h>
#define ll long long
#define maxn 100005 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
using namespace std;
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
int fl[maxn], a[maxn], b[maxn];
char inp[maxn];
int st[maxn]; 
int main() {
	int n;
	cin >> n;
	scanf("%s", inp);
	for (int i = 0; i < n; i++) 
		fl[i] = inp[i] - '0';
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i];
	int ans = 0;
	for (int i = 0; i < 200000; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (i >= b[j] && (i - b[j]) % a[j] == 0) fl[j] ^= 1;
			cnt += fl[j];
		}
		ans = max(ans, cnt);
	}
	cout << ans << endl;
	return 0;
}