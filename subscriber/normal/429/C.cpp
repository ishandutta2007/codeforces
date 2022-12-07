#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#include<cstring>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define M 1000000007
#define N 211111
using namespace std;
typedef pair<int,int> pt;

int k, a[25];
bool dp[14][25][10000];
int sum[10000], kol[10000];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	cin >> k;
	if (k == 1) {
		puts("YES");
		return 0;
	}
	int n = 0, e = 0;
	for (int i = 0; i < k; i++){
		int x;
		cin >> x;
		if (x == 1) e++; else a[n++] = x;

	}
	if (e <= n) {
		puts("NO");
		return 0;
	}
	sort(a, a + n);
	for (int o = 0; o < pw(n); o++) {
		for (int i = 0; i < n; i++) if (o & pw(i)) sum[o] += a[i], kol[o]++;
	}
	dp[0][e][0] = 1;
	for (int i = 0; i < n; i++) for (int ee = 0; ee <= e; ee++) for (int o = 0; o < pw(n); o++) if (dp[i][ee][o]) {
		for (int te = 0; te <= ee; te++) {
			int so = o;
			for(;;) {
				if (sum[so] + te + 1 == a[i] && kol[so] + te >= 2) {
					dp[i + 1][ee - te][o - so + pw(i)] = 1;
				}
				if (so == 0) break;
				so = (so - 1) & o;
			}
		}
	}
	string ans = "NO";
	for (int i = 0; i < n; i++) if (dp[n][0][pw(i)]) {
		ans = "YES";
	}
	cout << ans << endl;
	return 0;
}