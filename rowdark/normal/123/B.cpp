#include<iostream>
using namespace std;
typedef long long ll;
ll x1,x2,y1,y2;
ll a,b;
ll ans;
inline void updata(ll &x,const ll y){
	if(x<y) x=y;
}
inline ll calc(ll f1,ll f2,ll f3){
	ll f4;
	if(f3<f2) f4=f2,f2=f3,f3=f4;
	if(f2==f3&&f2%f1==0){
		return 2;
		}
	++f3;
	if(f2%f1==0) f2/=f1;
	else
		if(f2<0)
			f2=f2/f1;
		else
			f2=f2/f1+1;
	if(f3%f1==0) f3/=f1;
	else
		if(f3<0)
			f3=f3/f1;
		else
			f3=f3/f1+1;
	return f3-f2;
}
int main(){
	cin>>a>>b>>x1>>y1>>x2>>y2;
	if(x1==x2&&y1==y2){
		ans=((x1+y1)%(2*a)==0)||((x1-y1)%(2*b)==0);
		goto end;
		}
	ans=calc(2*a,x1+y1,x2+y2);
	updata(ans,calc(2*b,x1-y1,x2-y2));
	end:cout<<ans<<endl;
	cin>>a;
	return 0;
}