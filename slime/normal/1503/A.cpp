//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 200005 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

using namespace std;
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
int n;
char inp[maxn]; 
int res[2][maxn];
int main() {
	int t;
	cin >> t;
	while (t--) {
		scanf("%d", &n);
		scanf("%s", inp + 1);
		int df = 0;
		for (int i = 1; i <= n; i++)
			if (inp[i] == '0') df += 1;
		int fl = 1;
		if (df % 2) fl = 0;
		else {
			int cnt[2] = {0, 0};
			int t[2] = {0, 0};
			for (int i = 1; i <= n; i++) {
				int cm = inp[i] - '0';
				t[cm]++;
				if (cm == 1)
					if (t[cm] <= (n - df) / 2) res[0][i] = res[1][i] = 1;
					else res[0][i] = res[1][i] = -1;
				else {
					if (t[cm] % 2) res[0][i] = 1, res[1][i] = -1;
					else res[0][i] = -1, res[1][i] = 1;
				}
				cnt[0] += res[0][i], cnt[1] += res[1][i];
				if (cnt[0] < 0 || cnt[1] < 0) fl = 0;
			}
		}
		if (!fl) printf("NO\n");
		else {
			printf("YES\n");
			for (int i = 0; i < 2; i++) {
				for (int j = 1; j <= n; j++)
					if (res[i][j] == 1) printf("(");
					else printf(")");
				printf("\n");
			}
		}
	}
	return 0;
}