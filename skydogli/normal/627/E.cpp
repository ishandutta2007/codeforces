#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MN 3005
#define pii pair<int,int>
#define x first
#define y second
#define mp make_pair
int r,c,n,k;
pii a[MN],b[MN];
int ID[MN],res;
int f[MN],L[MN],R[MN];
bool cmp(pii a,pii b){
	return mp(a.y,a.x)<mp(b.y,b.x);
}
void del(int x,int k){
	if(!x)return;
	if(k){
		del(L[x],k-1);
		f[L[x]]=(f[L[x]]+f[x]);
		res+=b[L[x]].y*f[x];
	}
	if(k){
		res-=b[x].y*f[x];
		f[x]=0;
	}
}
int pos[MN];
signed main(){
	scanf("%lld%lld%lld%lld",&r,&c,&n,&k);
	for(int i=1;i<=n;++i){
		scanf("%lld%lld",&a[i].x,&a[i].y);
		b[i]=a[i];
	}
	sort(b+1,b+1+n);
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;++i)pos[i]=lower_bound(b+1,b+1+n,a[i])-b;
	b[n+1].y=c+1;
	int ans=0;
	for(int u=1;u<=r;++u){
//		cerr<<"u: "<<u<<endl;
		int cnt=0;
		for(int i=0;i<=n;++i){
//			cerr<<i<<": "<<f[i]<<endl;
//			assert(!f[i]);
			f[i]=0;
		}
		for(int i=1;i<=n;++i)
			if(a[i].x>=u){
				int tmp=++cnt;
			//	id[i]=tmp;
				ID[tmp]=pos[i];
			}
		ID[0]=0;ID[cnt+1]=n+1;
		for(int i=1;i<=cnt;++i){
			L[ID[i]]=ID[i-1],R[ID[i]]=ID[i+1];
//			assert(b[ID[i-1]].y<=b[ID[i]].y);
//			assert(b[ID[i]].y<=b[ID[i+1]].y);
		}
		L[n+1]=ID[cnt];
		R[0]=ID[1];
		res=0;
		for(int i=1;i+k-1<=cnt;++i){
			f[ID[i]]=b[ID[i+k]].y-b[ID[i+k-1]].y;
			res=(res+b[ID[i]].y*f[ID[i]]);
		}
		ans=(ans+res);
		int p=n;
		for(int i=r;i>=u;--i){
			while(b[p].x>=i){
				del(p,k);
//				cerr<<"? "<<p<<" "<<L[p]<<" "<<R[p]<<endl;
				assert(R[L[p]]==p);
				assert(L[R[p]]==p);
				R[L[p]]=R[p];
				L[R[p]]=L[p];
				p--;
			}
			ans=(ans+res);
		}
//		cerr<<"p: "<<p<<endl;
	}
	printf("%lld\n",ans);
	return 0;
}