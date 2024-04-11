#include<bits/stdc++.h>
#define ll long long
using namespace std;

map<ll,int> dp,mx;
ll n,m,ans;
inline int calc(ll n,ll &maxx){
	if(!n) return 0;
	ll l=1,r=100000;
	while(l<r){
		ll mid=l+r+1>>1;
		if(mid*mid*mid<=n) l=mid;  else r=mid-1;
	}
	ll t1=0,t2=0;
	int ans=0,p=0,q=0;
	p=calc(n-l*l*l,t1);
	if(l>1) q=calc(l*l*l-(l-1)*(l-1)*(l-1)-1,t2);
	if(p>=q){
		ans=p;
		maxx=t1+l*l*l;
	}
	else{
		ans=q;
		maxx=t2+(l-1)*(l-1)*(l-1);
	}
	return ans+1;
}
int main(){
	cin>>m;
	cout<<calc(m,n);cout<<" "<<n<<endl;
	return 0;

}
/*6
*/