#include<cstdio>
#include<algorithm>
using namespace std;
int n,l,add[12000005],ma[12000005];
void upd(int x,int y){add[x]+=y,ma[x]+=y;}
void update(int x,int l,int r,int ql,int qr,int v){
	if(l>=ql&&r<=qr){upd(x,v);return;}
	if(add[x])upd(x<<1,add[x]),upd(x<<1|1,add[x]),add[x]=0;
	int mid=l+r>>1;
	if(ql<=mid)update(x<<1,l,mid,ql,qr,v);
	if(qr>mid)update(x<<1|1,mid+1,r,ql,qr,v);
	ma[x]=max(ma[x<<1],ma[x<<1|1]);
}
struct pt{int x,y;}p[300005];
bool operator<(const pt&a,const pt&b){return a.x<b.x;}
int main(){
	scanf("%d%d",&n,&l),l<<=1;
	for(int i=1,x,y;i<=n;i++){
		scanf("%d%d",&x,&y);
		p[i].x=x-y,p[i].y=x+y;
	}
	sort(p+1,p+1+n);
	int ans=0;
	for(int i=1,j=1;i<=n;i++){
		while(p[i].x-p[j].x>l)update(1,-2000000,2000000,p[j].y,min(p[j].y+l,2000000),-1),j++;
		update(1,-2000000,2000000,p[i].y,min(p[i].y+l,2000000),1);
		ans=max(ans,ma[1]);
	}
	printf("%d\n",ans);
}