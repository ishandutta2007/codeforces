#include <cstdio>
#define int long long
typedef long long ll;
void swap(int &a,int &b){
	int t=a;
	a=b;
	b=t;
}
ll min(ll a,ll b){
	return a<b?a:b;
}
signed main(){
	int T;
	scanf("%lld",&T);
	while(T--){
		int n,k;
		scanf("%lld%lld",&n,&k);
		int l_1,r_1,l_2,r_2;
		scanf("%lld%lld%lld%lld",&l_1,&r_1,&l_2,&r_2);
		if(l_1>l_2){
			swap(l_1,l_2);
			swap(r_1,r_2);
		}
		if(r_1>=r_2){
			int num=(r_2-l_2);
			if(k<=1ll*num*n){
				puts("0");
			}
			else if(k<=1ll*(r_1-l_1)*n){
				printf("%lld\n",k-1ll*num*n);
			}
			else{
				printf("%lld\n",(1ll*(r_1-l_1)*n-1ll*num*n)+2ll*(k-1ll*(r_1-l_1)*n));
			}
		}
		else{
			if(r_1>=l_2){
				int num=(r_2-r_1)+(l_2-l_1);
				if(k<=1ll*(r_1-l_2)*n){
					puts("0");
				}
				else if(k<=1ll*(r_2-l_1)*n){
					printf("%lld\n",k-1ll*(r_1-l_2)*n);
				}
				else{
					printf("%lld\n",1ll*num*n+2ll*(k-1ll*(r_2-l_1)*n));
				}
			}
			else{
				int num=(r_2-r_1)+(l_2-l_1);
				if(num<((r_2-l_1)<<1)){
					if(k<=(r_2-l_1)){
						printf("%lld\n",l_2-r_1+k);
					}
					else{
						int used=k/(r_2-l_1);
						if(used>=n){
							printf("%lld\n",1ll*num*n+2ll*(k-1ll*(r_2-l_1)*n));
						}
						else{
							int last=k-1ll*used*(r_2-l_1);
							ll ans_1,ans_2;
							ans_1=ans_2=1ll*used*num;
							ans_1+=l_2-r_1+last;
							ans_2+=2ll*last;
							printf("%lld\n",min(ans_1,ans_2));
						}
					}
				}
				else{
					if(k<=(r_2-l_1)){
						printf("%lld\n",l_2-r_1+k);
					}
					else{
						printf("%lld\n",num+2ll*(k-(r_2-l_1)));
					}
				}
			}
		}
	}
	return 0;
}