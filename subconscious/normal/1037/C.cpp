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
const int N=1e6+5,P=1e9+7,inf=0x3f3f3f3f;
const ld eps=1e-9;
char a[N],b[N];
int n;
int main(){
	scanf("%d",&n);
	scanf("%s%s",a+1,b+1);
	int ans=0;
	rep(i,n){
		if(a[i]==b[i])continue;
		if(i<n&&a[i+1]!=b[i+1]&&a[i]!=a[i+1]){
			++ans;++i;
			continue;
		}
		++ans;
	}
	printf("%d\n",ans);
	return 0;
}