#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
template<typename Elem>
Elem gcd(Elem a,Elem b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}
typedef long long ll;
ll a[4],b[4];
int maxn;
int x,y;
void update_1(int i,int j){
	if((a[j]<<1)-a[i]<=a[3]&&a[j]-a[i]>maxn){
		maxn=a[j]-a[i];
		x=i;
		y=j;
	}
}
void update_2(int i,int j){
	if((a[j]<<1)-a[i]>=a[0]&&a[i]-a[j]>maxn){
		maxn=a[i]-a[j];
		x=i;
		y=j;
	}
}
vector<pair<ll,ll> > work(ll *tmp_a,int &id){
	for(int i=0;i<4;i++){
		a[i]=tmp_a[i];
	}
	ll d=(tmp_a[3]-tmp_a[0])<<4;
	vector<pair<ll,ll> > ans;
	while(a[3]-a[0]<d){
		if(a[0]!=a[3]){
			ans.push_back(make_pair(a[0],a[3]));
			a[0]=(a[3]<<1)-a[0];
		}
		if(a[1]!=a[2]){
			ans.push_back(make_pair(a[1],a[2]));
			a[1]=(a[2]<<1)-a[1];
		}
		sort(a,a+4);
	}
	while(a[3]-a[0]>2){
		maxn=0;
		update_1(0,1);
		update_1(0,2);
		update_2(3,2);
		update_2(3,1);
		ans.push_back(make_pair(a[x],a[y]));
		a[x]=(a[y]<<1)-a[x];
		sort(a,a+4);
	}
	static pair<ll,ll> p[3];
	if(a[0]==a[1]){
		p[0]=make_pair(a[0],2);
		p[1]=make_pair(a[2],1);
		p[2]=make_pair(a[3],1);
	}
	if(a[1]==a[2]){
		p[0]=make_pair(a[0],1);
		p[1]=make_pair(a[1],2);
		p[2]=make_pair(a[3],1);
	}
	if(a[2]==a[3]){
		p[0]=make_pair(a[0],1);
		p[1]=make_pair(a[1],1);
		p[2]=make_pair(a[2],2);
	}
	int pos;
	while(1){
		if(p[2].first<2){
			pos=2;
		}
		else if(p[0].first>0){
			pos=0;
		}
		else{
			break;
		}
		pair<ll,ll> tmp=make_pair((p[pos].first<<1)-p[pos^2].first,p[pos^2].second);
		for(int i=0;i<tmp.second;i++){
			ans.push_back(make_pair(p[pos^2].first,p[pos].first));
		}
		p[pos^2]=tmp;
		sort(p,p+3);
	}
	while(p[0].first<0||p[2].first>2){
		if(p[1].first<=0){
			pos=0;
		}
		else{
			pos=2;
		}
		pair<ll,ll> tmp=make_pair((p[1].first<<1)-p[pos].first,p[pos].second);
		for(int i=0;i<tmp.second;i++){
			ans.push_back(make_pair(p[pos].first,p[1].first));
		}
		p[pos]=tmp;
		sort(p,p+3);
	}
	if(p[2].first==1){
		id=1;
		ans.push_back(make_pair(0,1));
	}
	else{
		for(int i=0;i<3;i++){
			if(p[i].second==2){
				id=i;
			}
		}
	}
	return ans;
}
int main(){
	for(int i=0;i<4;i++){
		scanf("%lld",&a[i]);
	}
	sort(a,a+4);
	ll t_a=gcd(gcd(a[1]-a[0],a[2]-a[1]),a[3]-a[2]);
	for(int i=0;i<4;i++){
		scanf("%lld",&b[i]);
	}
	sort(b,b+4);
	ll t_b=gcd(gcd(b[1]-b[0],b[2]-b[1]),b[3]-b[2]);
	if(t_a==0&&t_b==0){
		if(a[0]==b[0]){
			puts("0");
		}
		else{
			puts("-1");
		}
		return 0;
	}
	if(t_a!=t_b||(a[0]%t_a!=b[0]%t_a)){
		puts("-1");
		return 0;
	}
	ll tmp_1=t_a,tmp_2=a[0];
	for(int i=0;i<4;i++){
		a[i]=(a[i]-tmp_2)/tmp_1;
		b[i]=(b[i]-tmp_2)/tmp_1;
	}
	int sum_a=0,sum_b=0;
	for(int i=0;i<4;i++){
		sum_a+=(a[i]&1);
		sum_b+=(b[i]&1);
	}
	if(sum_a!=sum_b){
		puts("-1");
		return 0;
	}
	int pos_a,pos_b;
	vector<pair<ll,ll> > ans_1=work(a,pos_a),ans_2=work(b,pos_b);
	reverse(ans_2.begin(),ans_2.end());
	for(int i=0;i<(int)ans_2.size();i++){
		pair<ll,ll> &u=ans_2[i];
		u.first=((u.second<<1)-u.first);
	}
	if(pos_a!=pos_b){
		ans_1.push_back(make_pair(pos_a,1));
	}
	ans_1.insert(ans_1.end(),ans_2.begin(),ans_2.end());
	printf("%d\n",(int)ans_1.size());
	for(int i=0;i<(int)ans_1.size();i++){
		printf("%lld %lld\n",ans_1[i].first*tmp_1+tmp_2,ans_1[i].second*tmp_1+tmp_2);
	}
	return 0;
}