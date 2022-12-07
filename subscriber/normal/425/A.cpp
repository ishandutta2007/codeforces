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

int n, K, s[5555];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	cin >> n >> K;
	for (int i = 0; i < n; i++) cin >> s[i];
	int ans = -1e9;
	for (int i = 0; i < n; i++) for (int j = i; j < n; j++) {
		vector<int> a, b;
		for (int k = 0; k < n; k++) {
			if (i <= k && k <= j) a.pb(s[k]); else b.pb(s[k]);
		}
		sort(a.begin(), a.end());
		sort(b.rbegin(), b.rend());
		int t = 0;
		for (int i = 0; i < a.size(); i++) t += a[i];
		for (int i = 0; i < K; i++) {
			if (i >= a.size() || i >= b.size()) continue;
			if (a[i] > b[i]) break;
			t -= a[i];
			t += b[i];
		}
		ans = max(ans, t);
	}
	cout << ans << endl;
	return 0;
}