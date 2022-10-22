#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MN 100005
int read(){
	int a=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a;
}
int ceildiv(int a,int b){return (a+b-1)/b;}
int n,m,k,p;
int tmp[MN],h[MN],a[MN],End[MN];
int ti[MN],lst[MN];
int q[50005];
int head[5005],to[50005],nxt[50005],cnt;
void add(int x,int y){
	to[++cnt]=y;
	nxt[cnt]=head[x];
	head[x]=cnt;
}
bool chk(int mid){
	cnt=0;
	for(int i=1;i<=n;++i)h[i]=tmp[i],lst[i]=ti[i]=0;
	for(int i=1;i<=m;++i)head[i]=0;
	int tot=0;
	for(int i=1;i<=n;++i){
		if(End[i]<=mid)continue;
		int v=End[i]-mid,d=v%p;
		ti[i]=ceildiv(v,p);
		if(!d)d=p;
		int nxt=1;
		if(d>h[i])nxt=ceildiv(d-h[i],a[i])+1;
		if(nxt>m)return 0;
		add(nxt,i);
		tot+=ti[i];
	}
	if(tot>m*k)return 0;
	int l=1,r=0;
	for(int i=1;i<=m;++i){
		for(int j=head[i];j;j=nxt[j]){
			q[++r]=to[j];
		}
		for(int j=1;j<=k;++j){
			if(l>r)break;
			int pos=q[l++];
			h[pos]+=(i-lst[pos])*a[pos]-p;
			ti[pos]--;lst[pos]=i;
			if(!ti[pos])continue;
			if(h[pos]>=p)q[++r]=pos;
			else{
				int ned=p-h[pos],ad=ceildiv(ned,a[pos]);
				if(i+ad>m)return 0;
				add(i+ad,pos);
			}
		}
	}
	if(l<=r)return 0;
	return 1;
}
signed main(){
	n=read();m=read();k=read();p=read();
	int l=1e15,r=0;
	for(int i=1;i<=n;++i){
		h[i]=read();a[i]=read();
		l=min(l,a[i]-1);r=max(r,h[i]+a[i]*m);
		tmp[i]=h[i];
		End[i]=h[i]+a[i]*m;
	}
	while(l+1<r){
		int mid=(l+r)>>1;
		if(chk(mid))r=mid;
		else l=mid;
	}
	printf("%lld\n",r);
	return 0;
}
//dddddddddd