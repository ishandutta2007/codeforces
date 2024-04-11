#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,t;
ll n,m,a,b,c,d,x,y,res;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%lld%lld%lld%lld%lld%lld%lld%lld",&n,&m,&a,&b,&c,&d,&x,&y);
		if(a>c){swap(a,c);}
		if(b>d){swap(b,d);}
		res=1e18;
		if(y+(d-b)<=m){
			res=min(res,y-b);
			d=m-d;
			res=min(res,y-d);
		}
		if(x+(c-a)<=n){
			res=min(res,x-a);
			c=n-c;
			res=min(res,x-c);
		}
		res=max(res,0ll);
		if(res==1e18){
			puts("-1");continue;
		}
		printf("%lld\n",res);
	}
}