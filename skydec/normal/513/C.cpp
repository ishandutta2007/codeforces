#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<assert.h>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
#define VI vector<int>
#define S(x) x.size()
using namespace std;
typedef long long LL;
typedef double db;
int l[6],r[6];int n;db ans;
inline int wei(int x,int y){return (x>>y)&1;}
inline int cnt(int x){
	int pa=0;
	rep(i,0,n-1)pa+=wei(x,i);
	return pa;
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d%d",&l[i],&r[i]);
	/*rep(i,0,(1<<n)-1)if(cnt(i)>=2){
		int lp,rp;lp=0;rp=10000;
		rep(j,0,n-1)if(wei(i,j)){
			lp=max(lp,l[j+1]);
			rp=min(rp,r[j+1]);
		}
		if(lp>rp)continue;
		
		rep(j,lp,rp){
			db tmp=0;
			db cc=1;
			rep(k,1,n)if(wei(i,k-1)==0){
				if(l[k]>=j)cc=0;
				else cc*=1.*min(r[k]-l[k]+1,j-l[k]);
			}
			if(cc==0)continue;
			tmp+=cc*1.*cnt(i)*1.*j;
			rep(k,1,n)if(wei(i,k-1)==0){
				int s=l[k];int mo=r[k];if(mo>=j)mo=j-1;
				
				tmp+=((s+mo)*(mo-s+1)/2.)*1.*(cc/(mo-s+1));
			}
			printf("%.10lf %d %d\n",tmp,i,j);
			tmp*=(1./n);
			rep(k,1,n)tmp/=(r[k]-l[k]+1);
			ans+=tmp;
		}
	}*/
	rep(j,1,(1<<n)-1)if(cnt(j)>1){
		int lp=0;int rp=100000;
		rep(i,1,n)if(wei(j,i-1)){
			lp=max(lp,l[i]);
			rp=min(rp,r[i]);
		}
		rep(hi,lp,rp){
			db ep=1;
			rep(k,1,n)if(!wei(j,k-1)){
				if(l[k]>=hi)ep=0;
				else ep*=1.*min(hi-l[k],r[k]-l[k]+1)/(r[k]-l[k]+1);
			}
			rep(k,1,n)if(wei(j,k-1))ep/=(r[k]-l[k]+1);
			ans+=ep*hi;
		}
	}
		
		rep(j,1,n)rep(mid,1,r[j]-1)
				for(int k=(1<<n)-1-(1<<(j-1));k;k=(k-1)&((1<<n)-1-(1<<(j-1)))){
					db ep=1;
					rep(u,1,n)if(wei(k,u-1)&&(r[u]<mid||mid<l[u]))ep=0;
					
					rep(u,1,n)if(wei(k,u-1))ep/=(r[u]-l[u]+1);
					
					ep*=1.*min(r[j]-mid,r[j]-l[j]+1)/(r[j]-l[j]+1);
					
					rep(u,1,n)if(wei(k,u-1)==0&&u!=j){
						if(l[u]>=mid)ep=0;
						else ep*=1.*min(r[u]-l[u]+1,mid-l[u])/(r[u]-l[u]+1);
					}
					
					ans+=ep*mid;
				}
				
		printf("%.12lf\n",ans);
		return 0;
}