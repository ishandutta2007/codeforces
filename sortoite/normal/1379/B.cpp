#include<bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("B.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	int l, r;
	long long m;
	while(T--) {
		cin>>l>>r>>m;
		for(int a=l; a<=r; a++) {
			long long t = m/a;
			int rem = m%a;
			if(t == 0) {
				t++;
				rem -= a;
			}
			else if(abs(rem) > r-l) {
				rem -= a;
				t++;
			}
			if(abs(rem) <= r-l) {
				if(rem <= 0) cout<<a<<' '<<l<<' '<<l-rem<<endl;
				else cout<<a<<' '<<l+rem<<' '<<l<<endl;
				break;
			}
		}
	}
	return 0;
}