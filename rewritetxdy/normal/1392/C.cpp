#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 2e5+10;

int t,n,c[N];

int main()
{
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i <= n;i++) scanf("%d",&c[i]);
		ll ans = 0;
		for(int i=1;i < n;i++) ans += max(0,c[i]-c[i+1]);
		cout<<ans<<endl;
	}
	return 0;
}