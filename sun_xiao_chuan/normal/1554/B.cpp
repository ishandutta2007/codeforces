#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[500500],b[500500];
ll res;


int main() {
    scanf("%d",&t);
    while(t--){
    	scanf("%d%d",&n,&m);
    	memset(a,-1,n*8+50);
    	memset(b,-1,n*8+50);
    	res=-1e18;
    	for(i=1;i<=n;i++){
    		scanf("%d",&k);
    		if(a[k]<i){b[k]=a[k];a[k]=i;continue;}
    		if(b[k]<i){b[k]=i;continue;}
		}
		for(int i = 0;i <= 20; ++i) for(int mask = 0; mask <=n*2; ++mask){
			if(mask & (1<<i)){
				int tmp=(mask^(1<<i));
				if(a[mask]<a[tmp]){
					b[mask]=a[mask];
					a[mask]=a[tmp];
				}
				else{
					if(b[mask]<a[tmp]){
						b[mask]=a[tmp];
					}
				}
				if(a[mask]<b[tmp]){
					b[mask]=a[mask];
					a[mask]=b[tmp];
				}
				else{
					if(b[mask]<b[tmp]){
						b[mask]=b[tmp];
					}
				}
			}
		}
		for(i=0;i<=n*2;i++){
			if(a[i]==-1||b[i]==-1){continue;}
			res=max(res,1ll*a[i]*b[i]-i*m);
		}
		printf("%lld\n",res);
	}
}