#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
const int N=4e5+5;
ll a[N],b[N],p[N<<1],t;int top,n;
int T[N<<1];
void ins(int x){for(;x<N<<1;x+=x&-x)++T[x];}
int que(int x){int s=0;for(;x;x-=x&-x)s+=T[x];return s;}
int main(){
	scanf("%d%lld",&n,&t);
	rep(i,n)scanf("%lld",a+i),a[i]+=a[i-1],b[i]=a[i]-t;
	p[++top]=0;
	rep(i,n)p[++top]=a[i],p[++top]=b[i];
	sort(p+1,p+top+1);
	int cnt=0;
	rep(i,top)if(!cnt||p[cnt]!=p[i])p[++cnt]=p[i];
	top=cnt;
	a[0]=lower_bound(p+1,p+top+1,a[0])-p;
	rep(i,n)
		a[i]=lower_bound(p+1,p+top+1,a[i])-p,
		b[i]=lower_bound(p+1,p+top+1,b[i])-p;
	ll ans=0;
	//rep(i,n)printf("%lld %lld\n",a[i],b[i]);
	rep(i,n){
		ins(a[i-1]);
		ans+=i-que(b[i]);
	}
	printf("%lld\n",ans);
	return 0;
}