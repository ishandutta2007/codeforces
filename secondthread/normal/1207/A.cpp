
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T; cin>>T;
	while (T--) {
		int buns, h, c, hP, cP; cin>>buns>>h>>c>>hP>>cP;
		if (hP<cP) {
			swap(h, c);
			swap(hP, cP);
		}
		int ans=0;
		while (buns>1&&h>0) {
			ans+=hP;
			buns-=2;
			h--;
		}
		while (buns>1&&c>0) {
			ans+=cP;
			buns-=2;
			c--;
		}
		cout<<ans<<'\n';
	}
	return 0;
}