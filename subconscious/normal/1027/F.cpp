#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
const int N=2e6+5;
int f[N],mx1[N],mx2[N],typ[N];
int to[N],n;
pair<int,int>a[N];
vector<int>cp;
int fa(int x){return f[x]==x?x:f[x]=fa(f[x]);}
int main(){
	scanf("%d",&n);
	rep(i,n){
		scanf("%d%d",&a[i].first,&a[i].second);
		cp.push_back(a[i].first),cp.push_back(a[i].second);
	}
	sort(cp.begin(),cp.end());
	auto it=unique(cp.begin(),cp.end());
	cp.resize(distance(cp.begin(),it));
	int d=cp.size();
	rep(i,d)to[i]=cp[i-1];
	rep(i,d)f[i]=i,mx1[i]=to[i],mx2[i]=-1,typ[i]=0;
	rep(i,n){
		a[i].first=lower_bound(to+1,to+d+1,a[i].first)-to;
		a[i].second=lower_bound(to+1,to+d+1,a[i].second)-to;
		int x=a[i].first,y=a[i].second;
		//printf("%d %d\n",x,y);
		x=fa(x),y=fa(y);
		if(x==y){
			++typ[x];
		}else{
			f[x]=y;
			typ[y]+=typ[x];
			if(mx1[x]>mx1[y]){
				mx2[y]=max(mx1[y],mx2[x]);
				mx1[y]=mx1[x];
			}else{
				mx2[y]=max(mx1[x],mx2[y]);
			}
		}
	}
	int ans=0;
	rep(x,d)if(f[x]==x){
		//printf("%d %d %d\n",typ[x],mx1[x],mx2[x]);
		if(typ[x]==0){
			if(mx2[x]==-1)ans=max(ans,mx1[x]);else ans=max(ans,mx2[x]);
		}else if(typ[x]==1){
			ans=max(ans,mx1[x]);
		}else ans=(int)(2e9+1);
	}
	if(ans==(int)(2e9+1))puts("-1");else printf("%d\n",ans);
}