//1:09
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL inf=1e18;
const int N=1000000+10;
const int B=1000001;
int n,m,p;
pair<int,int> a[N],b[N];
bool cmp(pair<int,int> p1,pair<int,int> p2){
	if(p1.first==p2.first)return p1.second>p2.second;
	return p1.first<p2.first;
}
struct Item{
	int x,y,z;
	bool operator<(const Item&o)const{
		return x<o.x;
	}
	void read(){
		scanf("%d%d%d",&x,&y,&z);
	}
} it[N];
LL mx[N<<2],lz[N<<2];
void pushdown(int rt){
	if(lz[rt]){
		mx[rt<<1]+=lz[rt]; lz[rt<<1]+=lz[rt];
		mx[rt<<1|1]+=lz[rt]; lz[rt<<1|1]+=lz[rt];
		lz[rt]=0;
	}
}
void update(int l,int r,int rt,int L,int R,LL x){
	if(L<=l&&r<=R){
		mx[rt]+=x; lz[rt]+=x; return;
	}
	int mid=(l+r)>>1; pushdown(rt);
	if(L<=mid)update(l,mid,rt<<1,L,R,x);
	if(R >mid)update(mid+1,r,rt<<1|1,L,R,x);
	mx[rt]=max(mx[rt<<1],mx[rt<<1|1]);
}
LL query(int l,int r,int rt,int L,int R){
	if(L<=l&&r<=R)return mx[rt];
	int mid=(l+r)>>1; pushdown(rt);
	LL ans=-inf;
	if(L<=mid)ans=max(ans,query(l,mid,rt<<1,L,R));
	if(R >mid)ans=max(ans,query(mid+1,r,rt<<1|1,L,R));
	return ans;
}
int main() {
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i].first,&a[i].second);
	for(int i=1;i<=m;i++)scanf("%d%d",&b[i].first,&b[i].second);
	for(int i=1;i<=p;i++)it[i].read();
	sort(it+1,it+1+p);
	sort(a+1,a+1+n,cmp);
	sort(b+1,b+1+m,cmp);
	int mm=1; 
	for(int i=2;i<=m;i++){
		while(mm>=1 && b[i].second<=b[mm].second){
			--mm;
		}
		b[++mm]=b[i];
	}
	m=mm;
	for(int i=1;i<=m;i++){
		//printf("upd [%d,+) += %d\n", max(b[i].first-1,1),b[i-1].second-b[i].second);
		update(1,B,1,b[i-1].first+1,B,b[i-1].second-b[i].second);
	}
	update(1,B,1,b[m].first+1,B,-inf);
	LL ans=-inf;
	for(int i=1,j=1;i<=n;i++){
		LL tmp=-a[i].second;
		//printf("i=%d\n", i);
		while(j<=p && it[j].x<a[i].first) {
			//printf("upd [%d,+) += %d\n", it[j].y,it[j].z);
			update(1,B,1,it[j].y+1,B,it[j].z);
			j++;
		}
		tmp+=query(1,B,1,b[1].first,B);
		//printf("que = %d\n", query(1,B,1,b[1].first,B));
		ans=max(ans,tmp);
	}
	cout<<ans<<endl;
}