#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
#define sz(x) int((x).size())
using cp=__complex__ long long;
#define re(x) (__real__ x)
#define im(x) (__imag__ x)
nagai cross(cp a,cp b){
	 return re(a)*im(b)-im(a)*re(b);
}
using pol=vector<cp>;
pol ch1(pol x){
	pol ans;
	for(auto&y:x){
		while(ans.size()>=2&&cross(ans.back()-y,ans[ans.size()-2]-ans.back())>=0)
			ans.pop_back();
		ans.push_back(y);
	}
	return ans;
}
bool cmp(cp a,cp b){
	return re(a)!=re(b)?re(a)<re(b):im(a)<im(b);
}
pol ch(pol x){
	sort(x.begin(),x.end(),cmp);
	auto mem=ch1(x);
	reverse(x.begin(),x.end());
	for(auto&y:ch1(x))
		mem.push_back(y);
	return mem;
}
int p,q;
double calc(cp a,cp b){
//	a.x*n+b.x*m=p
//	a.y*n+b.y*m=q
//	(b.x-b.y*(a.x/a.y))*m=p-q*(a.x/a.y)
	double coef=re(a)/(double)im(a);
	double c=p-q*coef;
	double m=c/(re(b)-im(b)*coef);
	double n=(p-re(b)*m)/re(a);
//	cerr<<re(a)<<' '<<im(a)<<' '<<re(b)<<' '<<im(b)<<' '<<m<<' '<<n<<'\n';
	return max(n,0.0)+max(m,0.0);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n>>p>>q;
	pol po;
	for(int i=0;i<n;++i){
		 int x,y;cin>>x>>y;
		 po.push_back({x,y});
	}
	po=ch(po);
	double ans=1e18;
	for(int i=0;i<po.size();++i){
		ans=min(ans,max(p/(double)re(po[i]),q/(double)im(po[i])));
		ans=min(ans,calc(po[i],po[(i+1)%po.size()]));
	}
	cout.precision(30);
	cout<<ans<<'\n';
	return 0;
}