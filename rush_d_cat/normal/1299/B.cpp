#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 10; 
typedef long long LL;
int n;LL x[N],y[N];
int main() {
	scanf("%d",&n);
	LL sx=0,sy=0;
	map< pair<LL,LL>, int > mp;
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&x[i],&y[i]);
		x[i]*=2, y[i]*=2; mp[make_pair(x[i],y[i])]=1;
		sx+=x[i], sy+=y[i];
	}
	if(sx%n || sy%n) return !printf("NO");
	sx/=n, sy/=n;
	for(int i=1;i<=n;i++){
		if(mp[make_pair(2*sx-x[i],2*sy-y[i])]==0) return !printf("NO\n");
	}
	return !printf("YES\n");
}