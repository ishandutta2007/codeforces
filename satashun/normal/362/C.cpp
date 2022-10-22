#include <algorithm>
#include <iostream>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  FOR(i,0,n)

int n, t, ret;
short mi;
int a[5010];
int v[5010];
short dp1[5010][5010];
//int dp2[5010][5010];

int main(){
    cin >> n;
    rep(i, n){
	cin >> a[i];
	v[i] = a[i];
    }

    for (int i = 1; i < n; ++i){
	int j = i; 
	while (j > 0 && v[j] < v[j - 1]){
	    swap(v[j], v[j - 1]);
	    --j;
	    ++t;
	}
    }

    rep(i, n){
	if(i) rep(j, n) dp1[i][j] = dp1[i-1][j];
	rep(j, a[i]) ++dp1[i][j];
    }

    /*
    for(int i = n - 1; i >= 0; --i){
	rep(j, n) dp2[i-1][j] = dp2[i][j];
	for(int j = a[i] + 1; j < n; ++j) ++dp2[i-1][j];
    }
    */

    rep(i, n){

	rep(j, i){
	    if(a[j] < a[i]) continue;
	    short sa = dp1[i][a[i]] + dp1[j][a[j]] - dp1[j][a[i]] - dp1[i][a[j]];
	    sa = sa * 2 + 1;
	    /*
	    int sa = dp1[i][a[i]] + dp2[i][a[i]] - 1;
	    int sa = 
	    sa += dp1[j][a[j]] + dp2[j][a[j]];
	    sa -= dp1[i][a[j]] + dp2[i][a[j]];
	    sa -= dp1[j][a[i]] + dp2[j][a[i]];
	    */
	    if(sa > mi){
		mi = sa;
		ret = 1;
	    }
	    else if(sa == mi) ++ret;
	}
    }

    cout << t - (int)mi << " " << ret << endl;
    return 0;
}