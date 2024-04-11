#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
const int o=2e6+10;const long long inf=1e18;
int T,n,cnt;long long a[o],b[o],mx1[o],mx2[o],mx3[o],f[o];map<long long,int> mp;
void build(int id,int l,int r){
	mx1[id]=mx2[id]=mx3[id]=-inf;
	if(l==r) return;
	int md=l+r>>1;
	build(id<<1,l,md);build((id<<1)|1,md+1,r);
}
void modify1(int id,int pos,long long val,int l=1,int r=cnt){
	mx1[id]=max(mx1[id],val);
	if(l==r) return;
	int md=l+r>>1;
	if(pos<=md) modify1(id<<1,pos,val,l,md);
	else modify1((id<<1)|1,pos,val,md+1,r);
}
void modify2(int id,int pos,long long val,int l=1,int r=cnt){
	mx2[id]=max(mx2[id],val);
	if(l==r) return;
	int md=l+r>>1;
	if(pos<=md) modify2(id<<1,pos,val,l,md);
	else modify2((id<<1)|1,pos,val,md+1,r);
}
void modify3(int id,int pos,long long val,int l=1,int r=cnt){
	mx3[id]=max(mx3[id],val);
	if(l==r) return;
	int md=l+r>>1;
	if(pos<=md) modify3(id<<1,pos,val,l,md);
	else modify3((id<<1)|1,pos,val,md+1,r);
}
long long query1(int id,int ql,int qr,int l=1,int r=cnt){
	if(ql>qr) return -inf;
	if(ql<=l&&r<=qr) return mx1[id];
	int md=l+r>>1;
	return max((ql<=md)?query1(id<<1,ql,qr,l,md):-inf,(md<qr)?query1((id<<1)|1,ql,qr,md+1,r):-inf);
}
long long query2(int id,int ql,int qr,int l=1,int r=cnt){
	if(ql>qr) return -inf;
	if(ql<=l&&r<=qr) return mx2[id];
	int md=l+r>>1;
	return max((ql<=md)?query2(id<<1,ql,qr,l,md):-inf,(md<qr)?query2((id<<1)|1,ql,qr,md+1,r):-inf);
}
long long query3(int id,int ql,int qr,int l=1,int r=cnt){
	if(ql>qr) return -inf;
	if(ql<=l&&r<=qr) return mx3[id];
	int md=l+r>>1;
	return max((ql<=md)?query3(id<<1,ql,qr,l,md):-inf,(md<qr)?query3((id<<1)|1,ql,qr,md+1,r):-inf);
}
int main(){
	for(scanf("%d",&T);T--;a[0]=b[0]=cnt=0,mp.clear()){
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%lld",&a[i]),a[i]+=a[i-1],b[i]=a[i];
		sort(b,b+n+1);
		for(int i=0;i<=n;++i) if(!i||b[i]-b[i-1]) mp[b[i]]=++cnt;
		for(int i=0;i<=n;++i) a[i]=mp[a[i]];
		build(1,1,cnt);
		for(int i=0;i<=n;modify1(1,a[i],f[i]-i),modify2(1,a[i],f[i]+i),modify3(1,a[i],f[i]),++i)
			if(i) f[i]=max(max(i+query1(1,1,a[i]-1),query2(1,a[i]+1,cnt)-i),query3(1,a[i],a[i]));
		printf("%lld\n",f[n]);
	}
	return 0;
}