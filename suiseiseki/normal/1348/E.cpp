#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int Maxn=500;
typedef long long ll;
int a[Maxn+5],b[Maxn+5];
int f[Maxn+5],g[Maxn+5];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	ll sum_a=0,sum_b=0;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i],&b[i]);
		sum_a+=a[i];
		sum_b+=b[i];
	}
	ll ans=sum_a/k+sum_b/k;
	sum_a%=k;
	sum_b%=k;
	if((sum_a+sum_b)>=k){
		f[0]=1;
		for(int i=1;i<=n;i++){
			memset(g,0,sizeof g);
			for(int j=1;j<k;j++){
				if(j<=a[i]&&k-j<=b[i]){
					for(int x=0;x<k;x++){
						if(f[x]){
							g[(x+j)%k]=1;
						}
					}
				}
			}
			for(int j=0;j<k;j++){
				f[j]|=g[j];
			}
		}
		for(int i=1;i<k;i++){
			if(f[i]&&i<=sum_a&&k-i<=sum_b){
				ans++;
				break;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}