#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
const int o=2e5+10,B=500;
int n,q,p[o],opt[o],x[o],y[o],bl[o],st[o],cnt;long long a[o],s[o],val[o],ans;vector<int> vec[o];
inline int query(int t,int z){
	int l=-1,r=vec[t].size()-1,md;
	for(;l<r;) if(vec[t][md=(l+r>>1)+1]<=z) l=md;else r=md-1;
	return l+1;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
	for(int i=1;i<=n;++i) scanf("%d",&p[i]);
	scanf("%d",&q);
	for(int i=1;i<=q;++i) scanf("%d%d%d",&opt[i],&x[i],&y[i]);
	for(int l=1,r;l<=q;l+=B,cnt=0){
		r=min(l+B-1,q);
		for(int i=1;i<=n;vec[i++].clear()) bl[i]=val[i]=0,s[i]=s[i-1]+a[i];
		for(int i=l;i<=r;++i)
			if(opt[i]==2) bl[x[i]]=x[i];
			else if(opt[i]==3) bl[x[i]]=x[i],bl[y[i]]=y[i];
		for(int i=1,j;i<=n;++i){
			if(bl[i]==i) st[++cnt]=i;
			if(bl[i]) continue;
			for(j=p[i];j-i&&!bl[j];j=p[j]);
			for(bl[i]=(i==j?-1:bl[j]),j=p[i];j-i&&!bl[j];j=p[j]) bl[j]=bl[i];
		}
		for(int i=1;i<=n;++i) if(bl[i]+1) vec[bl[i]].push_back(i);
		for(int i=l;i<=r;++i)
			if(opt[i]==1){
				ans=s[y[i]]-s[x[i]-1];
				for(int j=1;j<=cnt;++j) ans+=val[st[j]]*(query(st[j],y[i])-query(st[j],x[i]-1));
				printf("%lld\n",ans);
			}
			else if(opt[i]==3) swap(p[x[i]],p[y[i]]);
			else for(int j=bl[x[i]];(val[j]+=y[i],j=bl[p[j]])^bl[x[i]];);
		for(int i=1;i<=n;++i) if(bl[i]+1) a[i]+=val[bl[i]];
	}
	return 0;
}