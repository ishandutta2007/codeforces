#include <bits/stdc++.h>
using namespace std;
const int N = 200000 + 10;
int n, a[N];
map<int,long long> mp;
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		mp[a[i]-i]+=a[i];
	}
	long long ans=0;
	for(auto p: mp) ans=max(ans,p.second);
	cout<<ans<<endl;
}