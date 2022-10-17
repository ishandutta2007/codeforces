#include <cstdio>
#include <iostream>
using namespace std;
#define ll long long
#define Maxn 100000
char s[Maxn+5];
const int d[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int dc[300];
int num[4];
bool use[4];
int n;
ll c_x,c_y;
ll ans;
ll now_x,now_y;
ll ab(ll a){
	return a<0?-a:a;
}
ll x_1,y_1,x_2,y_2;
bool check(ll x){
	ll now=x/n;
	ll step=n*now;
	ll step_x=now_x*now,step_y=now_y*now;
	ll need_use=ab(x_2-(x_1+step_x))+ab(y_2-(y_1+step_y));
	/*cout<<x<<" "<<need_use<<endl;
	cout<<step_x<<" "<<step_y<<endl;
	cout<<endl;*/
	if(need_use<=step){
		return 1;
	}
	for(int i=1;i<=x%n;i++){
		step++;
		step_x+=d[dc[s[i]]][0];
		step_y+=d[dc[s[i]]][1];
		need_use=ab(x_2-(x_1+step_x))+ab(y_2-(y_1+step_y));
		if(need_use<=step){
			return 1;
		}
	}
	return 0;
}
int main(){
	cin>>x_1>>y_1>>x_2>>y_2;
	scanf("%d",&n);
	scanf("%s",s+1);
	dc['U']=0;
	dc['D']=1;
	dc['L']=3;
	dc['R']=2;
	for(int i=1;i<=n;i++){
		num[dc[s[i]]]++;
		now_x+=d[dc[s[i]]][0];
		now_y+=d[dc[s[i]]][1];
	}
	if(x_1==x_2&&y_1==y_2){
		puts("0");
		return 0;
	}
	ll left=0,right=(1ll<<50),mid;
	while(left<right){
		mid=(left+right)>>1;
		if(check(mid)){
			right=mid;
		}
		else{
			left=mid+1;
		}
	}
	if(left==(1ll<<50)){
		left=-1;
	}
	cout<<left<<endl;
	return 0;
}