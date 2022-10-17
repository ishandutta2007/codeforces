#include <cstdio>
#include <iostream>
using namespace std;
#define ll long long
ll a[45],b[45];
int main(){
	a[1]=b[1]=1;
	for(int i=2;i<=32;i++){
		a[i]=(a[i-1]<<2);
		a[i-1]+=a[i-2];
		b[i]=(b[i-1]<<1);
		b[i-1]+=b[i-2]-1;
	}
	int t;
	int n;
	ll k;
	scanf("%d",&t);
	int ans;
	while(t--){
		scanf("%d",&n);
		cin>>k;
		if(n>31){
			printf("YES %d\n",n-1);
		}
		else if(k>a[n]){
			puts("NO");
		}
		else if(n==2&&k==3){
			puts("NO");
		}
		else{
			for(ans=1;ans<=n;ans++){
				if(k>=b[ans]&&k<=a[ans]+a[n-ans]*((1<<ans)-1)*((1<<ans)-1)){
					break;
				}
			}
			printf("YES %d\n",n-ans);
		}
	}
	return 0;
}