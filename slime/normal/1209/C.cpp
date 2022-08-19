#include <bits/stdc++.h>
#define ll long long
#define maxn 200005 /*rem*/
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
char inp[maxn];
int col[maxn];
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		scanf("%d", &n);
		scanf("%s", inp);
		int fn = 0;
		for (int j = 0; j < 10; j++) {
			if (fn) break;
			int pl[2] = {-1, maxn};
			for (int k = 0; k < n; k++) {
				if (inp[k] - '0' < j) col[k] = 1, pl[0] = k;
				else if (inp[k] - '0' > j) col[k] = 2, pl[1] = min(pl[1], k);
			}
			int nf = 1;
			for (int k = 0; k < n; k++)
				if (inp[k] - '0' == j) 
				{
					int ca[2] = {1, 1};
					if (k < pl[0]) ca[0] = 0;
					if (k > pl[1]) ca[1] = 0;
					if (ca[0]) col[k] = 1;
					else if (ca[1]) col[k] = 2;
					else nf = 0; 
				}
			if (nf) {
				int l[2] = {0, 0};
				for (int k = 0; k < n; k++) {
					int ns = inp[k] - '0';
					if (ns < l[col[k] - 1]) nf = 0;
					l[col[k] - 1] = ns;
				}
			}
			if (nf) {
				fn = 1;
				for (int k = 0; k < n; k++)
					printf("%d", col[k]);
				printf("\n");
				break;
			}
		}
		if (!fn) printf("-\n");
	}
	return 0;
}