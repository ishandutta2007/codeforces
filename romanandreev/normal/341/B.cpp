#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<map>
#include<algorithm>
#include<cstring>
#include<set>
#include<ctime>
#include<cassert>


using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),(a).end()
const int inf = 1e9;
int a[1000000];
int n;
int dp[1000000];
int main() {
	#ifdef home
    	freopen("a.in", "r", stdin);
	    freopen("a.out", "w", stdout);
	#endif
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
    	scanf("%d", &a[i]);
    }
    for (int i = 0; i <= n; i++) {
    	dp[i] = inf;
    }
    for (int i = 0; i < n; i++) {
    	int k = upper_bound(dp, dp + n + 1, a[i]) - dp;
    	dp[k] = a[i];
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
    	if (dp[i] != inf) {
    		ans = i + 1;
    	}
    }
    cout<<ans<<endl;
	return 0;
}