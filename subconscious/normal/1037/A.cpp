#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define pb push_back
#define mp make_pair
#define x0 fuckyzc
#define y0 fuckcjb
#define x1 fuckjtjl
#define y1 fucksf
using namespace std;
typedef long long ll;
typedef long double ld;
const int N=1e5+5,P=1e9+7,inf=0x3f3f3f3f;
const ld eps=1e-9;
int n;
int main(){
	scanf("%d",&n);
	int ans=1;
	while((1<<ans)-1<n)++ans;
	printf("%d\n",ans);
	return 0;
}