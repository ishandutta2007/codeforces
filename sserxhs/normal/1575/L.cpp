#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=2e5+10;
int n,f[N],a[N],b[N],ans=0;
int rt[N*2],cnt=0,lc[N*120],rc[N*120],mx[N*120];
#define mid ((l+r)>>1)
void upd(int& x,int l,int r,int pos,int val){
	if(!x)x=++cnt;
	mx[x]=max(mx[x],val);
	if(l==r)return;
	if(mid>=pos)upd(lc[x],l,mid,pos,val);
	else upd(rc[x],mid+1,r,pos,val);
}
int qry(int x,int l,int r,int pos){
	if(!x)return 0;
	if(l==r)return mx[x];
	if(mid>=pos)return qry(lc[x],l,mid,pos);
	return max(mx[lc[x]],qry(rc[x],mid+1,r,pos));
}
void update(int i){
	for(int x=a[i];x<=n;x+=x&-x)
		upd(rt[x],1,n,b[i],f[i]);
}
int query(int i){
	int res=0;
	for(int x=a[i]-1;x;x-=x&-x)
		res=max(res,qry(rt[x],1,n,b[i]));
	return res;
}

int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i],b[i]=i-a[i]+1;
		if(b[i]<=0)continue;
		f[i]=query(i)+1;
		ans=max(ans,f[i]);
		update(i);
	}
	cout<<ans<<endl;
}