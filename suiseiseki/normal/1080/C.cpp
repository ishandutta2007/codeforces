#include <cstdio>
#include <iostream>
using namespace std;
#define ll long long
ll mn(ll a,ll b){
	return a<b?a:b;
}
ll mx(ll a,ll b){
	return a>b?a:b;
}
void swp(ll &a,ll &b){
	ll t=a;
	a=b;
	b=t;
}
int main(){
	int t;
	ll n,m;
	scanf("%d",&t);
	ll x1,x2,y1,y2,x3,x4,y3,y4,x5,x6,y5,y6;
	ll ans_1,ans_2;
	while(t--){
		cin>>n>>m;
		cin>>x1>>y1>>x2>>y2;
		cin>>x3>>y3>>x4>>y4;
		if((n&1)&&(m&1)){
			ans_1=(n*m>>1)+1;
			ans_2=(n*m>>1);
		}
		else{
			ans_1=(n*m>>1);
			ans_2=(n*m>>1);
		}
		if(((x2-x1+1)&1)&&((y2-y1+1)&1)){
			if((x1&1)==(y1&1)){
				ans_1+=((x2-x1+1)*(y2-y1+1)>>1);
				ans_2-=((x2-x1+1)*(y2-y1+1)>>1);
			}
			else{
				ans_1+=((x2-x1+1)*(y2-y1+1)>>1)+1;
				ans_2-=((x2-x1+1)*(y2-y1+1)>>1)+1;
			}
		}
		else{
			ans_1+=((x2-x1+1)*(y2-y1+1)>>1);
			ans_2-=((x2-x1+1)*(y2-y1+1)>>1);
		}
		if(((x4-x3+1)&1)&&((y4-y3+1)&1)){
			if((x3&1)==(y3&1)){
				ans_2+=((x4-x3+1)*(y4-y3+1)>>1)+1;
				ans_1-=((x4-x3+1)*(y4-y3+1)>>1)+1;
			}
			else{
				ans_2+=((x4-x3+1)*(y4-y3+1)>>1);
				ans_1-=((x4-x3+1)*(y4-y3+1)>>1);
			}
		}
		else{
			ans_2+=((x4-x3+1)*(y4-y3+1)>>1);
			ans_1-=((x4-x3+1)*(y4-y3+1)>>1);
		}
		x5=mn(mx(x1,x2),mx(x3,x4));
		y5=mn(mx(y1,y2),mx(y3,y4));
		x6=mx(mn(x1,x2),mn(x3,x4));
		y6=mx(mn(y1,y2),mn(y3,y4));
		if(x5>=x6&&y5>=y6){
			swp(x5,x6);
			swp(y5,y6);
			if(((x6-x5+1)&1)&&((y6-y5+1)&1)){
				if((x5&1)==(y5&1)){
					ans_2+=((x6-x5+1)*(y6-y5+1)>>1);
					ans_1-=((x6-x5+1)*(y6-y5+1)>>1);
				}
				else{
					ans_2+=((x6-x5+1)*(y6-y5+1)>>1)+1;
					ans_1-=((x6-x5+1)*(y6-y5+1)>>1)+1;
				}
			}
			else{
				ans_2+=((x6-x5+1)*(y6-y5+1)>>1);
				ans_1-=((x6-x5+1)*(y6-y5+1)>>1);
			}
		}
		cout<<ans_1<<" "<<ans_2<<endl;
	}
	return 0;
}