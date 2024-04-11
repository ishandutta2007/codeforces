#include <bits/stdc++.h>

using namespace std;
typedef long long INT;
typedef double DO;
typedef pair<int, int> pii;
typedef vector<int> VI;

int main() {
#ifndef ONLINE_JUDGE
//    freopen("in.in", "r", stdin);
//    freopen("out.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	INT x, y, z;
	cin >> x >> y >> z;
	INT mx=(x+y)/z;
	INT ans=-1;
	INT bi=(z-x%z)%z;
	if(bi<=y and y/z == (y-bi)/z) {
		ans=bi;
	}
	bi=(z-y%z)%z;
	if(bi<=x and x/z == (x-bi)/z) {
		if(ans==-1) ans=bi;
		else if(bi<ans) ans=bi;
	}
	if(ans==-1) ans=0;
	cout << mx<<' '<<ans << endl;
    return 0;
}