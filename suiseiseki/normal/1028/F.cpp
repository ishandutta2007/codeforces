#include <map>
#include <vector>
#include <cstdio>
#include <algorithm>
typedef long long ll;
int gcd(int a,int b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}
int num;
std::map<ll,std::vector<std::pair<int,int> > > mp_lis;
std::pair<int,int> get_min(std::pair<int,int> v){
	int g=gcd(v.first,v.second);
	v.first/=g,v.second/=g;
	return v;
}
std::pair<int,int> operator +(const std::pair<int,int> &a,const std::pair<int,int> &b){
	return std::make_pair(a.first+b.first,a.second+b.second);
}
std::map<std::pair<int,int>,int> ans,sum;
void add_val(std::vector<std::pair<int,int> > &a,std::pair<int,int> v){
	num++;
	sum[get_min(v)]++;
	for(std::pair<int,int> i:a){
		ans[get_min(i+v)]++;
	}
	a.push_back(v);
}
void del_val(std::vector<std::pair<int,int> > &a,std::pair<int,int> v){
	num--;
	sum[get_min(v)]--;
	a.erase(std::find(a.begin(),a.end(),v));
	for(std::pair<int,int> i:a){
		ans[get_min(i+v)]--;
	}
}
int main(){
	int q;
	scanf("%d",&q);
	while(q--){
		int op,x,y;
		scanf("%d%d%d",&op,&x,&y);
		if(op==1){
			add_val(mp_lis[1ll*x*x+1ll*y*y],std::make_pair(x,y));
		}
		else if(op==2){
			del_val(mp_lis[1ll*x*x+1ll*y*y],std::make_pair(x,y));
		}
		else{
			printf("%d\n",num-2*ans[get_min(std::make_pair(x,y))]-sum[get_min(std::make_pair(x,y))]);
		}
	}
	return 0;
}