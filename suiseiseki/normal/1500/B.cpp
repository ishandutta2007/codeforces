#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long ll;
const int Maxn=500000;
void exgcd(ll a,ll b,ll &x,ll &y){
	if(!b){
		x=1;
		y=0;
		return;
	}
	ll p;
	exgcd(b,a%b,x,y);
	p=x;
	x=y;
	y=p-(a/b)*y;
	return;
}
int gcd(int a,int b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}
ll lcm(int a,int b){
	return 1ll*a/gcd(a,b)*b;
}
int n,m;
ll k;
int a[Maxn+5],b[Maxn+5];
int id[Maxn<<1|5];
ll x[Maxn+5],y[Maxn+5];
int len;
bool check(ll t){
	ll ans=0;
	t--;
	for(int i=1;i<=len;i++){
		if(t<y[i]){
			continue;
		}
		ans+=(t-y[i])/x[i]+1;
	}
	return t+1-ans>=k;
}
int main(){
	scanf("%d%d%lld",&n,&m,&k);
	memset(id,-1,sizeof id);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		id[a[i]]=i;
	}
	for(int i=0;i<m;i++){
		scanf("%d",&b[i]);
		if(id[b[i]]!=-1){
			len++;
			x[len]=id[b[i]];
			y[len]=i;
			int g=gcd(n,m);
			int t_n=n/g,t_m=m/g;
			ll c=y[len]-x[len];
			if(c%g!=0){
				len--;
				continue;
			}
			c/=g;
			exgcd(t_n,t_m,x[len],y[len]);
			if(c<0){
				x[len]=-x[len];
				y[len]=-y[len];
				c=-c;
			}
			if(x[len]<0){
				x[len]+=t_m;
				y[len]-=t_n;
			}
			y[len]=-y[len];
			x[len]*=c;
			y[len]*=c;
			y[len]=x[len]*n+id[b[i]];
			x[len]=lcm(n,m);
			y[len]%=x[len];
		}
	}
	ll left=1,right=1000000000000000000ll;
	while(left<right){
		ll mid=(left+right)>>1;
		if(check(mid)){
			right=mid;
		}
		else{
			left=mid+1;
		}
	}
	printf("%lld\n",left);
	return 0;
}