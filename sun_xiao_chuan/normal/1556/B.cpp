#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int i,j,k,n,m,t,a[100500],b[100500],m0,m1;
ll res;

ll chk1(){
	int i,j,k,lim1=(n+1)/2,lim0=n-lim1;
	ll res=0;
	if(lim1!=m1||lim0!=m0){
		return 1e18;
	}
	for(i=1;i<=lim1;i++){
		res+=abs(a[i]-(i*2-1));
	}
	return res;
}

ll chk0(){
	int i,j,k,lim0=(n+1)/2,lim1=n-lim0;
	ll res=0;
	if(lim1!=m1||lim0!=m0){
		return 1e18;
	}
	for(i=1;i<=lim1;i++){
		res+=abs(a[i]-(i*2));
	}
	return res;
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		m0=m1=0;
		res=1e18;
		for(i=1;i<=n;i++){
			scanf("%d",&k);
			if(k&1){
				a[++m1]=i;
			}
			else{
				b[++m0]=i;
			}
		}
		if(n==1){puts("0");continue;}
		res=min(chk1(),chk0());
		if(res==1e18){
			puts("-1");
		}
		else{
			printf("%lld\n",res);
		}
	}
}