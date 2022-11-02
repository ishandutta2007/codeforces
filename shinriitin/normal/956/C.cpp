#include <bits/stdc++.h>

using ll = long long;

const int max_N = 1e5 + 21;

int n,a[max_N],s[max_N];

ll ans;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",a+i);
	s[n+1]=-0x7f7f7f7f;
	for(int i=n;i;--i)s[i]=std::max(a[i]-i+1,s[i+1]);
	for(int i=1,j=1;i<=n;++i){
		if(j-i<s[i])++j;
		ans+=j-1-a[i];
	}
	return printf("%lld\n",ans),0;
}