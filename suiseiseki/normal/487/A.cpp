#include <cstdio>
#include <iostream>
using namespace std;
#define int long long
int mn(int a,int b){
	return a<b?a:b;
}
int mx(int a,int b){
	return a>b?a:b;
}
signed main(){
	int hp_y,atk_y,def_y;
	int hp_m,atk_m,def_m;
	int h,a,d;
	cin>>hp_y>>atk_y>>def_y;
	cin>>hp_m>>atk_m>>def_m;
	cin>>h>>a>>d;
	int ans=(1ll<<60),tmp,now;
	int now_i;
	for(int j=0;j<=300;j++){
		for(int k=0;k<=300;k++){
			if(atk_y+j-def_m<=0){
				continue;
			}
			tmp=(hp_m+(atk_y+j-def_m)-1)/(atk_y+j-def_m);
			now_i=hp_y-tmp*mx(0,(atk_m-def_y-k));
			if(now_i>0){
				now_i=0;
			}
			else{
				now_i=-now_i;
				now_i++;
			}
			now=now_i*h+a*j+d*k;
			ans=mn(ans,now);
		}
	}
	cout<<ans<<endl;
	return 0;
}