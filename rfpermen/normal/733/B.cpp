#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;i++)
#define fi first
#define se second
#define ll long long
#define mp make_pair
using namespace std;
ll n,l[150000],r[150000],L,R,ans,mx,tmp;
int main(){
	cin>>n;
	rep(i,n){
		cin>>l[i]>>r[i];
		L+=l[i], R+=r[i];
	}
	mx=abs(L-R);
	rep(i,n){
		tmp=abs(L-R-2*l[i]+2*r[i]);
		if(mx<tmp)mx=tmp, ans=i;
	}
	cout<<ans<<endl;
	return 0;
}