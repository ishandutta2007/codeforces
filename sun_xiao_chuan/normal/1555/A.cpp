#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
ll sb,res,sb2;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%lld",&sb);
		res=1e18;
		for(i=0;i<=10;i++){
			for(j=0;j<=10;j++){
				for(k=0;k<=10;k++){
					res=min(res,i*15+j*20+k*25+(max(0ll,sb-i*6-j*8-k*10)+6-1)/6*15);
					res=min(res,i*15+j*20+k*25+(max(0ll,sb-i*6-j*8-k*10)+8-1)/8*20);
					res=min(res,i*15+j*20+k*25+(max(0ll,sb-i*6-j*8-k*10)+10-1)/10*25);
				}
			}
		}
		printf("%lld\n",res);
	}
}