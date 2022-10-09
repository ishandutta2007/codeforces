#include <bits/stdc++.h>

using namespace std;
const int maxn=200001;
typedef long long ll;

int a[maxn];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin>>n;
	for (int i=0; i<n; i++) cin>>a[i];
 	for (int i=0; i<n; i++) a[i]=abs(a[i]);
	
	sort(a, a+n);
	int farIndex=0;
	ll ans=0;
	for (int start=0; start<n; start++) {
		farIndex=max(farIndex, start);
		while (farIndex+1<n&&a[start]*2>=a[farIndex+1])
			farIndex++;
		ans+=farIndex-start;
	}
	cout<<ans<<endl;
	return 0;
}