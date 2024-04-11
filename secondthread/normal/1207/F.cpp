
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sqrtn=700, maxn=500001;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	vector<vector<int>> valuesAtMod;
	vector<int> values(maxn, 0);
	for (int i=0; i<sqrtn; i++)
		valuesAtMod.push_back(vector<int>(i, 0));
	int n; cin>>n;
	for (int qq=0; qq<n; qq++) {
		int type, x, y; cin>>type>>x>>y;

		if (type==1) {
			values[x]+=y;
			for (int mod=1; mod<sqrtn; mod++)
				valuesAtMod[mod][x%mod]+=y;
		}
		else {
			if (x<sqrtn) {
				int ans=valuesAtMod[x][y];
				cout<<ans<<'\n';
			}
			else {
				int ans=0;
				for (int i=y; i<maxn; i+=x)
					ans+=values[i];
				cout<<ans<<'\n';
			}
		}
	}
	return 0;
}