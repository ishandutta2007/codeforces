#include <set>
#include <cstdio>
using namespace std;
typedef long long ll;
ll k,l,r,t,x,y;
set<ll> st;
int main(){
	scanf("%lld%lld%lld%lld%lld%lld",&k,&l,&r,&t,&x,&y);
	if(x>=y){
		if(k+y>r){
			t--;
			k-=x;
		}
		if(k<l){
			puts("No");
			return 0;
		}
		if(x==y){
			puts("Yes");
			return 0;
		}
		if((k-l)/(x-y)<t){
			puts("No");
			return 0;
		}
		puts("Yes");
		return 0;
	}
	ll tmp=k;
	tmp=l+(tmp-l)%x;
	t-=(k-tmp)/x;
	st.insert(tmp);
	while(t>0){
		tmp+=y;
		if(tmp>r){
			puts("No");
			return 0;
		}
		ll last=tmp;
		tmp=l+(tmp-l)%x;
		t-=(last-tmp)/x;
		if(t<=0){
			break;
		}
		if(st.count(tmp)>0){
			puts("Yes");
			return 0;
		}
		st.insert(tmp);
	}
	puts("Yes");
	return 0;
}