#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MN 200005
#define pii pair<int,int>
#define mp make_pair
int a[MN],T,n,m;
char ch[MN];
int gcd(int a,int b){if(!b)return a;return b;}
signed main(){
	int T;
	scanf("%lld",&T);
	while(T--){
		int p,q;
		scanf("%lld%lld",&p,&q);
		if(p%q!=0)printf("%lld\n",p);
		else{
			int ans=0;
			for(int i=2;i*i<=q;++i){
				if(q%i==0){
					int a=1;
					while(q%i==0){
						a*=i;
						q/=i;
					}
					int v=p;
					while(v%a==0)v/=i;
					ans=max(ans,v);
				}
			}
			if(q!=1){
				int a=q;
				int v=p;
				while(v%a==0)v/=a;
				ans=max(ans,v);
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}