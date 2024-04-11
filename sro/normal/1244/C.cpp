#include <bits/stdc++.h>
using namespace std;

long long n,p;
int d,w;

int main(){
	scanf("%lld%lld%d%d",&n,&p,&w,&d);
	for(int i=0;i<w;i++){
		if((p-1ll*d*i)%w==0){
			long long y=i,x=(p-1ll*d*i)/w;
			if(x+y>n){
				puts("-1");
				return 0;
			}
			if(x<0){
			    puts("-1");
			    return 0;
			}
			printf("%lld %lld %lld\n",x,y,n-x-y);
			return 0;
		}
	}
	puts("-1");
	return 0;
}