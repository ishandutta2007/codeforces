#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ll long long
#define rep(i,n,N) for(int i=n;i<=(int)N;i++)
#define rap(i,n,N) for(int i=n;i>=(int)N;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
const int MAX=1005;
ll gcd(ll r,ll v){
	if(v==0) return r;
	return gcd(v,r%v);
}
ll cube(ll x){
	ll r,l,m,ret;
	r=0, l=1000000;
	while(r<=l){
		m=(l+r)/2;
		if(m*m*m<=x){
			ret=m;
			r=m+1;
		}
		else l=m-1;
	}
	return ret;
}
ll a,b,now,cnt,n,lel,cnt2,idx,tmp;
bool stat;
int main(){
	//cout<<fixed<<setprecision(9);
	//ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n;
	while(n--){
		scanf("%lld%lld",&a,&b);
		tmp=cube(a*b);
		if(a*b!=tmp*tmp*tmp)printf("No\n");
		else {
			if(a%tmp==0 && b%tmp==0)printf("Yes\n");
			else printf("No\n");
		}
	}
	
	return 0;
}