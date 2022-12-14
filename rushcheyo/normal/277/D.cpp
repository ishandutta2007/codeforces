#include<bits/stdc++.h>
using namespace std;
typedef long double llf;
int n,t;
struct res{
	llf s,t;
}dp[1565];
struct task{
	int ss,sl,ts,tl;
	llf p;
	res joins(const res&o){
		return {o.s+ss,o.t+ts};
	}
	res joinl(const res&o,int t){
		return {o.s+ss+sl*(1-p),p*(ts+o.t)+(1-p)*(t+ts+tl)};
	}
}p[1005];
bool operator<(const task&a,const task&b){
	return (1-b.p)*a.p*a.tl<(1-a.p)*b.p*b.tl;
}
void upd(res&a,const res&b){
	if(fabs(a.s-b.s)<1e-8){
		if(a.t>b.t)a=b;
	}else if(a.s<b.s)a=b;
}
int main(){
	cin>>n>>t;
	for(int i=1;i<=n;i++)
		cin>>p[i].ss>>p[i].sl>>p[i].ts>>p[i].tl>>p[i].p;
	sort(p+1,p+1+n);
	for(int i=1;i<=n;i++)
		for(int j=t;j>=0;j--){
			if(j+p[i].ts<=t)upd(dp[j+p[i].ts],p[i].joins(dp[j]));
			if(j+p[i].ts+p[i].tl<=t)upd(dp[j+p[i].ts+p[i].tl],p[i].joinl(dp[j],j));
		}
	res ans=dp[0];
	for(int i=1;i<=t;i++)upd(ans,dp[i]);
	cout<<setprecision(18)<<ans.s<<' '<<ans.t<<endl;
	return 0;
}