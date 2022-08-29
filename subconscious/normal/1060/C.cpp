#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define pb push_back
#define mp pake_pair
#define x0 fuckcjb
#define y0 fuckyzc
#define x1 fucksm
#define y1 fucklzw
using namespace std;
typedef long long ll;
typedef long double ld;
const int N=2005,MOD=1e9+7;
const ld eps=1e-12;
int a[N],b[N],x,n,m;
int la[N],lb[N];
int main(){
	scanf("%d%d",&n,&m);
	rep(i,n)scanf("%d",a+i),a[i]+=a[i-1];
	rep(i,m)scanf("%d",b+i),b[i]+=b[i-1];
	scanf("%d",&x);
	int ans=0;
	rep(len,n){
		la[len]=MOD;
		rep(i,n-len+1)la[len]=min(a[i+len-1]-a[i-1],la[len]);
	}
	rep(len,m){
		lb[len]=MOD;
		rep(i,m-len+1)lb[len]=min(b[i+len-1]-b[i-1],lb[len]);
	}
	rep(i,n)rep(j,m)if(1ll*la[i]*lb[j]<=x)ans=max(ans,i*j);
	printf("%d\n",ans);
	return 0;
}