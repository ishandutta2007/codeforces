#include <cstdio>
typedef long long ll;
const int Maxn=100000;
const ll Inf=200000000000ll;
int n;
ll t[Maxn+5];
int x[Maxn+5];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld%d",&t[i],&x[i]);
		}
		int pos=0,to=0;
		int ans=0;
		t[n+1]=Inf;
		for(int i=1;i<=n;i++){
			if(pos==to){
				to=x[i];
			}
			if(to>pos){
				if(pos+0ll+t[i+1]-t[i]>=to){
					if(pos<=x[i]&&x[i]<=to){
						ans++;
					}
					pos=to;
				}
				else{
					if(pos<=x[i]&&x[i]<=pos+0ll+t[i+1]-t[i]){
						ans++;
					}
					pos+=0ll+t[i+1]-t[i];
				}
			}
			else{
				if(pos-(0ll+t[i+1]-t[i])<=to){
					if(to<=x[i]&&x[i]<=pos){
						ans++;
					}
					pos=to;
				}
				else{
					if(pos-(0ll+t[i+1]-t[i])<=x[i]&&x[i]<=pos){
						ans++;
					}
					pos-=0ll+t[i+1]-t[i];
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}